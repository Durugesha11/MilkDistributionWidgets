#include "mywidget.h"
#include <QTableView>
#include <QStackedWidget>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include "milkDistributionEnums.h"
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    m_myDataModel=new MyCustomerTabModel;
    this->resize(800,600);
    m_myStackedWidget=new QStackedWidget(this);
    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(m_myStackedWidget);
    setLayout(mainLayout);
    QWidget *loginWindow=createLoginWindow();
    m_myStackedWidget->addWidget(loginWindow);
    m_myStackedWidget->setCurrentIndex(Page::loginPage);

}
QWidget* MyWidget::createLoginWindow()
{
    QWidget *loginWindow=new QWidget(this);
    QVBoxLayout *loginVLayout=new QVBoxLayout(loginWindow);

    QLabel *adminName=new QLabel("AdminName:");
    QLineEdit *nameLabel=new QLineEdit();
    QHBoxLayout *loginHlayout=new QHBoxLayout;
    loginHlayout->addWidget(adminName);
    loginHlayout->addWidget(nameLabel);
    loginVLayout->addLayout(loginHlayout);

    QHBoxLayout *loginHlayout2=new QHBoxLayout;
    QLabel *passwordLabel=new QLabel("Password:");
    QLineEdit *enterPassword=new QLineEdit();
    loginHlayout2->addWidget(passwordLabel);
    loginHlayout2->addWidget(enterPassword);
    loginVLayout->addLayout(loginHlayout2);
    QPushButton *login=new QPushButton("Login");
    loginVLayout->addWidget(login);
    loginVLayout->setAlignment(Qt::AlignCenter);
    loginVLayout->setAlignment(Qt::AlignAbsolute);

    connect(login,&QPushButton::clicked,this,&MyWidget::showHomePage);

    return loginWindow;

}
void MyWidget::showHomePage()
{
    qDebug()<<"welcome to milk distribution home page";

    QWidget *firstWindow=new QWidget(this);
    QVBoxLayout *firstLayout=new QVBoxLayout(firstWindow);
    m_addCustomer=new QPushButton("Add Customer", firstWindow);
    m_displayCustomer=new QPushButton("Display All", firstWindow);
    m_mapView=new QPushButton("Map View", firstWindow);
    m_distributeMilk=new QPushButton("Start Distribute", firstWindow);
    m_milkBalance=new QPushButton("Check Balance", firstWindow);
    m_logout=new QPushButton("Logout", firstWindow);

    connect(m_logout,&QPushButton::clicked,[this](){this->close();});
    QHBoxLayout *hlyt1=new QHBoxLayout;
    hlyt1->addWidget(m_addCustomer);
    hlyt1->addWidget(m_displayCustomer);
    hlyt1->addWidget(m_mapView);

    QHBoxLayout *hlyt2=new QHBoxLayout;
    hlyt2->addWidget(m_distributeMilk);
    hlyt2->addWidget(m_milkBalance);
    hlyt2->addWidget(m_logout);

    firstLayout->addLayout(hlyt1);
    firstLayout->addLayout(hlyt2);
    m_myStackedWidget->addWidget(firstWindow);

    //adding different widgets to stackwidget
    addCustomerWindow();
    displayAllCustomerwindow();
    addGoogleMapWindow();

    //switch widgets using connect
    connect(m_addCustomer,&QPushButton::clicked,this,[this](){m_myStackedWidget->setCurrentIndex(Page::AddCustomerPage);});
    connect(m_backButton,&QPushButton::clicked,this,[this](){m_myStackedWidget->setCurrentIndex(Page::HomePage);});
    connect(m_displayCustomer,&QPushButton::clicked,this,[this](){m_myStackedWidget->setCurrentIndex(Page::CustomerTableViewPage);});
    connect(m_mapView,&QPushButton::clicked,this,[this](){m_myStackedWidget->setCurrentIndex(Page::GoogleMapPage);});
    m_myStackedWidget->setCurrentIndex(Page::HomePage);

}
void MyWidget::addGoogleMapWindow()
{
    QWidget *mapView=new QWidget;

    QVBoxLayout *webvlyt=new QVBoxLayout(mapView);

    m_webView=new QWebEngineView;
    webvlyt->addWidget(m_webView);

    QPushButton *mapHomePageButton=new QPushButton("Back <<");
    connect(mapHomePageButton,&QPushButton::clicked,this,[this](){m_myStackedWidget->setCurrentIndex(Page::HomePage);});

    webvlyt->addWidget(mapHomePageButton);

    //web page view connect function
    QWebEnginePage *page=m_webView->page();
    connect(page, &QWebEnginePage::featurePermissionRequested,
            [this, page](const QUrl &securityOrigin, QWebEnginePage::Feature feature) {
                if (feature != QWebEnginePage::Geolocation)
                    return;

                QMessageBox msgBox(this);
                msgBox.setText(tr("%1 wants to know your location").arg(securityOrigin.host()));
                msgBox.setInformativeText(tr("Do you want to send your current location to this website?"));
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::Yes);

                if (msgBox.exec() == QMessageBox::Yes) {
                    page->setFeaturePermission(
                        securityOrigin, feature, QWebEnginePage::PermissionGrantedByUser);
                } else {
                    page->setFeaturePermission(
                        securityOrigin, feature, QWebEnginePage::PermissionDeniedByUser);
                }
            });

    page->load(QUrl(QStringLiteral("https://maps.google.com")));

    m_myStackedWidget->addWidget(mapView);

    qDebug()<<"welcome to map view";

}

void MyWidget::init()
{


}
void MyWidget::displayAllCustomerwindow()
{
    QWidget *displayAll=new QWidget(this);
    QTableView *view=new QTableView();
    view->setModel(m_myDataModel);

    QVBoxLayout *vdisplyLayout=new QVBoxLayout(displayAll);
    QPushButton *displayBackButton=new QPushButton("Back <<");
    vdisplyLayout->addWidget(view);
    vdisplyLayout->addWidget(displayBackButton);
    connect(displayBackButton,&QPushButton::clicked,this,[this](){m_myStackedWidget->setCurrentIndex(Page::HomePage);});

    m_myStackedWidget->addWidget(displayAll);
}

void MyWidget::addCustomerWindow()
{
    QWidget *addCustomerWindow=new QWidget(this);
    QVBoxLayout *addCustomerLayout=new QVBoxLayout(addCustomerWindow);
    QPushButton *acButton = new QPushButton("New Window", addCustomerWindow);
    m_backButton = new QPushButton("Back", addCustomerWindow);
    addCustomerLayout->addWidget(acButton);
    addCustomerLayout->addWidget(m_backButton);
    m_myStackedWidget->addWidget(addCustomerWindow);

    //enter below details


}

MyWidget::~MyWidget() {
    qDebug()<<"i'm deleting all objects\n";
}

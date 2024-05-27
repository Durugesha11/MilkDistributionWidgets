#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <mycustomertabmodel.h>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QWebEngineView>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    void init();
    void addCustomerWindow();
    void displayAllCustomerwindow();

    void addGoogleMapWindow();
public slots:
    void showHomePage();
private:
    QStackedWidget *m_myStackedWidget;
    QPushButton *m_addCustomer;
    QPushButton *m_displayCustomer;
    QPushButton *m_mapView;
    QPushButton *m_fillMilktoContainer;
    QPushButton *m_distributeMilk;
    QPushButton *m_milkBalance;
    QPushButton *m_backButton;
    QPushButton *m_logout;


    MyCustomerTabModel *m_myDataModel;
    QWidget *createLoginWindow();

    QWebEngineView *m_webView;
};
#endif // MYWIDGET_H

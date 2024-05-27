#include "mycustomertabmodel.h"
#include "milkDistributionEnums.h"
#include <QFont>
#include <QColor>
MyCustomerTabModel::MyCustomerTabModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    readCustomerFile();

}
std::string MyCustomerTabModel::getCurrentDate()
{

    std::time_t now=std::time(nullptr);
    std::tm* localTime=std::localtime(&now);
    std::stringstream ss;
    ss<<(localTime->tm_year + 1900)<<'-'
       <<(localTime->tm_mon +1)<<'-'
       <<localTime->tm_mday;
    return ss.str();

}
bool MyCustomerTabModel::readCustomerFile()
{
    std::ifstream customerSourceFile("customerDetails.txt");
    std::string currentDate=getCurrentDate();
    std::string debugFileName="DebugLogfile"+currentDate+".txt";
    std::ofstream debugFile(debugFileName);

    if(!customerSourceFile)
    {
        qDebug()<<"Error: unable to open file\n";
        return 1;
    }
    else
    {
        qDebug()<<"file opened successfully\n";

        if(!debugFile.is_open())
        {
            qDebug()<<"error: when debug file opening";
        }else
        {
            qDebug()<<"Success: when debug file opening";

        }

        int lineNumber=0;
        std::string line;
        while (std::getline(customerSourceFile, line))
        {
            std::istringstream iss(line);
            std::string token;
            std::vector<std::string> values;
            lineNumber++;
            while (std::getline(iss, token, ','))
            {
                values.push_back(token);
            }


            std::regex namePattern("^[a-zA-Z]+(?: [a-zA-Z]+)*$");
            if(!std::regex_match(values[CustomerName],namePattern))
            {
                debugFile<<lineNumber<<":Invalid name"<<std::endl;

            }
            std::regex phonePattern("^[1-9]\\d{9}$");
            if(!std::regex_match(values[PhoneNumber],phonePattern))
            {
                debugFile<<lineNumber<<":Invalid PhoneNumer"<<std::endl;

            }
            std::regex milkQty("^[1-9]$");
            if(!std::regex_match(values[MilkQuantity],milkQty))
            {
                debugFile<<lineNumber<<":Invalid Milk Quantity"<<std::endl;

                values[MilkQuantity]="0"; //taking wrong entry default to zero

            }
            std::regex houseNumberPattern("^[0-9]+$");
            if (!std::regex_match(values[HouseNumber], houseNumberPattern))
            {
                debugFile<<lineNumber<<":Invalid House Number"<<std::endl;

            }
            if(!std::regex_match(values[Area],namePattern))
            {
                debugFile<<lineNumber<<":Invalid Area name"<<std::endl;

            }
            if(!std::regex_match(values[City],namePattern))
            {
                debugFile<<lineNumber<<":Invalid City name"<<std::endl;
            }

            std::regex pincodePattern("^[0-9]{6}$");
            if(!std::regex_match(values[Pincode],pincodePattern))
            {
                debugFile<<lineNumber<<":Invalid Pincode"<<std::endl;

            }

#ifndef DEBUG
            debugFile<<lineNumber<<":valid entry="<<values[CustomerName]<<","<<values[PhoneNumber]<<","<<values[MilkQuantity]<<","<<values[HouseNumber]<<","<<values[Area]<<","<<values[City]<<","<<values[Pincode]<<std::endl;
#endif

            Customer* newCustomer=new Customer(values);

            m_myCustomers.append(newCustomer);

        }
    }


    customerSourceFile.close();
    debugFile.close();


    return false;


}

QVariant MyCustomerTabModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return QVariant();
}

int MyCustomerTabModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return m_myCustomers.size();
}

int MyCustomerTabModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 11;
}

QVariant MyCustomerTabModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    int r1=index.row();
    int c1=index.column();
    switch(role)
    {
    case Qt::DisplayRole:
    {
        if(c1==0)
        {

            QString cid= m_myCustomers.at(r1)->CId();
            return cid;
        }
        if(c1==1){

            QString name= m_myCustomers.at(r1)->name();
            return name;
        }
        if(c1==2){
            QString fone= m_myCustomers.at(r1)->phoneNumber();
            return fone;
        }
        if(c1==3){
            QString milkqty= m_myCustomers.at(r1)->milkQuantity();
            return milkqty;
        }
        if(c1==4){

            QString dstatus= m_myCustomers.at(r1)->deliveryStatus();
            return dstatus;
        }
        if(c1==5){
            QString housenumber= m_myCustomers.at(r1)->houseNumber();
            return housenumber;
        }
        if(c1==6){
            QString area= m_myCustomers.at(r1)->area();
            return area;
        }
        if(c1==7){
            QString city= m_myCustomers.at(r1)->city();
            return city;
        }
        if(c1==8){
            QString pincode= m_myCustomers.at(r1)->pincode();
            return pincode;
        }
        if(c1==9){
            QString lat= m_myCustomers.at(r1)->latitude();
            return lat;
        }
        if(c1==10){
            QString longitude= m_myCustomers.at(r1)->longitude();
            return longitude;
        }
    }
    case Qt::FontRole:{
        QFont font;
        font.setPixelSize(20);
        font.setBold(true);
        return font;
        break;}
    case Qt::BackgroundRole :
    {QColor col;
        if(r1%2==0){
            col=QColor(100,100,100);
        }else
        {
            col=QColor(200,200,100);
        }
        return col;
        break;

    }
    }

    return QVariant();
}

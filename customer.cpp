#include "customer.h"
#include <QDebug>
#include "milkDistributionEnums.h"
Customer::Customer(QObject *parent)
    : QObject{parent}
{}

Customer::Customer(std::vector<std::string> &customerData)
{

    init(customerData);
}
void Customer::init(std::vector<std::string> &customerData)
{
    m_CId=QString::fromStdString(customerData[CustomerId]);
    m_name=QString::fromStdString(customerData[CustomerName]);
    m_phoneNumber=QString::fromStdString(customerData[PhoneNumber]);
    m_milkQuantity=QString::fromStdString(customerData[MilkQuantity]);
    m_deliveryStatus=QString::fromStdString(customerData[DeliveryStatus]);
    m_houseNumber=QString::fromStdString(customerData[HouseNumber]);
    m_area=QString::fromStdString(customerData[Area]);
    m_city=QString::fromStdString(customerData[City]);
    m_pincode=QString::fromStdString(customerData[Pincode]);
    m_latitude=QString::fromStdString(customerData[Latitude]);
    m_longitude=QString::fromStdString(customerData[Longitude]);


}

QString Customer::name() const
{
    return m_name;
}

void Customer::setName(const QString &newName)
{
    m_name = newName;
}

QString Customer::phoneNumber() const
{
    return m_phoneNumber;
}

void Customer::setPhoneNumber(const QString &newPhoneNumber)
{
    m_phoneNumber = newPhoneNumber;
}

QString Customer::milkQuantity() const
{
    return m_milkQuantity;
}

void Customer::setMilkQuantity(const QString &newMilkQuantity)
{
    m_milkQuantity = newMilkQuantity;
}

QString Customer::houseNumber() const
{
    return m_houseNumber;
}

void Customer::setHouseNumber(const QString &newHouseNumber)
{
    m_houseNumber = newHouseNumber;
}

QString Customer::area() const
{
    return m_area;
}

void Customer::setArea(const QString &newArea)
{
    m_area = newArea;
}

QString Customer::city() const
{
    return m_city;
}

void Customer::setCity(const QString &newCity)
{
    m_city = newCity;
}

QString Customer::pincode() const
{
    return m_pincode;
}

void Customer::setPincode(const QString &newPincode)
{
    m_pincode = newPincode;
}

QString Customer::latitude() const
{
    return m_latitude;
}

void Customer::setLatitude(const QString &newLatitude)
{
    m_latitude = newLatitude;
}

QString Customer::longitude() const
{
    return m_longitude;
}

void Customer::setLongitude(const QString &newLongitude)
{
    m_longitude = newLongitude;
}

QString Customer::CId() const
{
    return m_CId;
}

void Customer::setCId(const QString &newCId)
{
    m_CId = newCId;
}

QString Customer::deliveryStatus() const
{
    return m_deliveryStatus;
}

void Customer::setDeliveryStatus(const QString &newDeliveryStatus)
{
    m_deliveryStatus = newDeliveryStatus;
}

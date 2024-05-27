#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QObject>
#include <vector>
#include <string>
#include <QString>

class Customer : public QObject
{
    Q_OBJECT
public:
    explicit Customer(QObject *parent = nullptr);
    Customer(std::vector<std::string>& customerData);

    QString name() const;
    void setName(const QString &newName);

    QString phoneNumber() const;
    void setPhoneNumber(const QString &newPhoneNumber);

    QString milkQuantity() const;
    void setMilkQuantity(const QString &newMilkQuantity);

    QString houseNumber() const;
    void setHouseNumber(const QString &newHouseNumber);

    QString area() const;
    void setArea(const QString &newArea);

    QString city() const;
    void setCity(const QString &newCity);

    QString pincode() const;
    void setPincode(const QString &newPincode);

    QString latitude() const;
    void setLatitude(const QString &newLatitude);

    QString longitude() const;
    void setLongitude(const QString &newLongitude);

    QString CId() const;
    void setCId(const QString &newCId);

    QString deliveryStatus() const;
    void setDeliveryStatus(const QString &newDeliveryStatus);

    void init(std::vector<std::string> &customerData);
signals:
private:
    QString m_CId;
    QString m_name;
    QString m_phoneNumber;
    QString m_milkQuantity;
    QString m_deliveryStatus;
    QString m_houseNumber;
    QString m_area;
    QString m_city;
    QString m_pincode;

    QString m_latitude;
    QString m_longitude;

};

#endif // CUSTOMER_H

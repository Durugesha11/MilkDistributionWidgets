#ifndef MYCUSTOMERTABMODEL_H
#define MYCUSTOMERTABMODEL_H

#include <QAbstractTableModel>
#include "customer.h"
#include <QList>
#include <string>
#include <regex>
#include <sstream>
#include <QDebug>
#include <fstream>
#include <QVariant>
class MyCustomerTabModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit MyCustomerTabModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool readCustomerFile();
    std::string getCurrentDate();
private:
    QList<Customer*> m_myCustomers;
};

#endif // MYCUSTOMERTABMODEL_H

#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QList>
#include "constants.h"
#include "customer.h"
#include "purchases.h"
#include <QSqlDatabase>
#include <QDebug>

class dbManager
{
private:
    dbManager();
    ~dbManager();

    QSqlDatabase myDB;

public:
    static dbManager& instance();
    bool isOpen() const;

    dbManager(const dbManager&) = delete; //delete copy constructor.
    void operator =(const dbManager&) = delete; //delete = operator.

    // functions that deal with add/deleting/verifying customers to the database
    bool customerExists(const Customer& customer);
    bool addCustomer(const Customer& newCustomer);
    bool deleteCustomer(const Customer& customer);

    // function to add a purchase to the database
    bool addPurchase(const Purchases& newPurchase);
};

#endif // DBMANAGER_H

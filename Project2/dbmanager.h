#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QList>
#include "constants.h"
#include "customer.h"
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

    bool customerExists(const Customer& customer);
    bool addCustomer(const Customer& newCustomer);
    bool deleteCustomer(const Customer& customer);
};

#endif // DBMANAGER_H

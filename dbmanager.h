#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QList>
#include "constants.h"
#include <QSqlDatabase>

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
};

#endif // DBMANAGER_H

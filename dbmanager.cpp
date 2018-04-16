#include "dbManager.h"

dbManager::dbManager()
{
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(DB_PATH);

    if( QFile::exists(DB_PATH) )
    {
        if (!myDB.open()) //be careful, SQLITE will create the db if it doesn't exist and return true.
        {
            qDebug() << "Error: could not open connection to database.";
        }
        else
        {
            qDebug() << "Database connection opened.";
        }
    }
    else
    {
        qDebug() << "Cannot open database because the DB Path does not exist.";
    }
}

dbManager::~dbManager()
{
     myDB = QSqlDatabase::addDatabase("QSQLITE");
    if (myDB.isOpen())
    {
        myDB.close();
    }

    qDebug() << "Destroying Databasemanager";
}

bool dbManager::isOpen() const
{
    return myDB.isOpen();
}

dbManager& dbManager::instance()
{
    static dbManager dmInstance;

    return dmInstance;
}

#include "dbmanager.h"

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

bool dbManager::customerExists(const Customer& customer)
{
    bool exists = false;
    QSqlQuery query;
    QString name = customer.getCustomerName();

    query.prepare("SELECT name FROM customers WHERE name = (:name)");
    query.bindValue(":name", name);

    if(query.exec())
    {
        if(query.next())
        {
            exists = true;
        }
    }

    return exists;
}

bool dbManager::addCustomer(const Customer& newCustomer)
{
    if(newCustomer.getCustomerName().isEmpty() || newCustomer.getCustomerAddress().isEmpty() ||
       newCustomer.getCustomerInterest().isEmpty() || newCustomer.getCustomerRating().isEmpty() ||
       newCustomer.getCustomerPamphlet().isEmpty())
    {
        qDebug() << "Cannot create new customer unless all data has been given";
        return false;
    }

    QSqlQuery query;
    QString name;
    QString address;
    QString interest;
    QString rating;
    QString pamphlet;

    name = newCustomer.getCustomerName();
    address = newCustomer.getCustomerAddress();
    interest = newCustomer.getCustomerInterest();
    rating = newCustomer.getCustomerRating();
    pamphlet = newCustomer.getCustomerPamphlet();

    query.prepare("INSERT INTO customers (name, address, interest, rating, pamphlet) VALUES (:name, :address, :interest, :rating, :pamphlet)");
    query.bindValue(":name", name);
    query.bindValue(":address", address);
    query.bindValue(":interest", interest);
    query.bindValue(":rating", rating);
    query.bindValue(":pamphlet", pamphlet);

    if(query.exec())
    {
        qDebug() << "AddCustomer success:";
        return true;
    }
    else
    {
        qDebug() << "AddCustomer fail:"
                 << query.lastError();
        return false;
    }
}

bool dbManager::deleteCustomer(const Customer& customer)
{
    QSqlQuery query;
    QString name = customer.getCustomerName();

    if(customerExists(customer))
    {
        query.prepare("DELETE FROM customers WHERE name = (:name)");
        query.bindValue(":name", name);

        if( query.exec() )
        {
            qDebug() << "Customer deleted!";
            return true;
        }
        else
        {
            qDebug() << "Delete Customer failed: " << query.lastError();
            return false;
        }
    }
    return false;
}

bool dbManager::addPurchase(const Purchases& newPurchase)
{
    QSqlQuery query;
    QString name;
    int silver;
    int gold;
    int platinum;
    double total;

    name = newPurchase.getName();
    silver = newPurchase.getQtySilver();
    gold = newPurchase.getQtyGold();
    platinum = newPurchase.getQtyPlat();
    total = newPurchase.getSubTotal();

    query.prepare("INSERT INTO transactions (name, silver, gold, platinum, total) VALUES (:name, :silver, :gold, :platinum, :total)");
    query.bindValue(":name", name);
    query.bindValue(":silver", silver);
    query.bindValue(":gold", gold);
    query.bindValue(":platinum", platinum);
    query.bindValue(":total", total);

    if(query.exec())
    {
        qDebug() << "Add Customer Purchase success:";
        return true;
    }
    else
    {
        qDebug() << "Add Customer Purchase fail:"
                 << query.lastError();
        return false;
    }
}

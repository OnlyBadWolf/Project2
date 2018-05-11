#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QtSql>
#include "purchases.h"

class Customer : public Purchases
{
public:
    Customer();
    Customer(QString, QString, QString, QString, QString);

    QString getCustomerName() const;
    QString getCustomerAddress() const;
    QString getCustomerInterest() const;
    QString getCustomerRating() const;
    QString getCustomerPamphlet() const;

private:
    QString customerName;
    QString customerAddress;
    QString customerInterest;
    QString customerRating;
    QString customerPamhplet;
};

#endif // CUSTOMER_H
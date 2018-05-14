#ifndef PURCHASES_H
#define PURCHASES_H

#include <QtSql>

class Purchases
{
public:
    Purchases();
    Purchases(QString, int, int, int, double);

    QString getCustomerName() const;
    int getQtySilver() const;
    int getQtyGold() const;
    int getQtyPlat() const;
    double getSubTotal() const;

    // overloaded operators
    bool operator==(const Purchases&); // overloads == to compare names
    Purchases operator-(double); // overloads - to discount total

private:
    QString name;
    int qtySilver;
    int qtyGold;
    int qtyPlat;
    double subTotal;

};

#endif // PURCHASES_H

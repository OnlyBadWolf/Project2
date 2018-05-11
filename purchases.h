#ifndef PURCHASES_H
#define PURCHASES_H

#include <QtSql>

class Purchases
{
public:
    Purchases();
    Purchases(QString, int, int, int, double);

    QString getName() const;
    int getQtySilver() const;
    int getQtyGold() const;
    int getQtyPlat() const;
    double getSubTotal() const;

private:
    QString name;
    int qtySilver;
    int qtyGold;
    int qtyPlat;
    double subTotal;

};
#endif // PURCHASES_H

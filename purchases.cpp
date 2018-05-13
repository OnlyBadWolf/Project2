#include "purchases.h"

Purchases::Purchases()
{
     name = "";
     qtySilver = 0;
     qtyGold = 0;
     qtyPlat = 0;
     subTotal = 0.0;
}

Purchases::Purchases(QString customerName, int silver, int gold, int plat, double total)
{
    name = customerName;
    qtySilver = silver;
    qtyGold = gold;
    qtyPlat = plat;
    subTotal = total;
}

QString Purchases::getCustomerName() const
{
    return name;
}

int Purchases::getQtySilver() const
{
    return qtySilver;
}

int Purchases::getQtyGold() const
{
    return qtyGold;
}

int Purchases::getQtyPlat() const
{
    return qtyPlat;
}

double Purchases::getSubTotal() const
{
    return subTotal;
}

bool Purchases::operator==(const Purchases& compareName)
{
    return (name == compareName.name);
}

Purchases Purchases::operator-(double discount)
{
    Purchases subtractDiscount = *this;
    subtractDiscount.subTotal = subtractDiscount.subTotal - discount;
    return subtractDiscount;
}

#include"address.h"

Address::Address()
{
    street = "";
    city = "";
    state = "";
    zipcode = "";
}

Address::Address(QString uStreet, QString uCity, QString uState, QString uZipcode)
{
    street = uStreet;
    city = uCity;
    state = uState;
    zipcode = uZipcode;
}

QString Address::getStreet() const
{
    return street;
}

QString Address::getCity() const
{
    return city;
}

QString Address::getState() const
{
    return state;
}

QString Address::getZipcode() const
{
    return zipcode;
}

void Address::setStreet(QString x)
{
    street = x;
}

void Address::setCity(QString x)
{
    city = x;
}

void Address::setState(QString x)
{
    state = x;
}

void Address::setZipcode(QString x)
{
    zipcode = x;
}

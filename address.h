#ifndef ADDRESS_H
#define ADDRESS_H

#include <QtSql>

class Address
{
public:
    Address();
    Address(QString, QString, QString, QString);

    QString getStreet() const;
    QString getCity() const;
    QString getState() const;
    QString getZipcode() const;

    void setStreet(QString);
    void setCity(QString);
    void setState(QString);
    void setZipcode(QString);


private:
    QString street;
    QString city;
    QString state;
    QString zipcode;

};

#endif // ADDRESS_H

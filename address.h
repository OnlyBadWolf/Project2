#ifndef ADDRESS_H
#define ADDRESS_H

#include <QtSql>

template <class T>
class Address
{
public:
    Address()
    {
        street = "";
        city = "";
        state = "";
        zipcode = "";
    }
    Address(T uStreet,T uCity,T uState,T uZipcode)
    {
        street = uStreet;
        city = uCity;
        state = uState;
        zipcode = uZipcode;
    }

    T getStreet() const;
    T getCity() const;
    T getState() const;
    T getZipcode() const;

    void setStreet(T);
    void setCity(T);
    void setState(T);
    void setZipcode(T);


private:
    T street;
    T city;
    T state;
    T zipcode;

};


template <class T>
T Address<T>::getStreet() const
{
    return street;
}

template <class T>
T Address<T>::getCity() const
{
    return city;
}

template <class T>
T Address<T>::getState() const
{
    return state;
}

template <class T>
T Address<T>::getZipcode() const
{
    return zipcode;
}

template <class T>
void Address<T>::setStreet(T x)
{
    street = x;
}

template <class T>
void Address<T>::setCity(T x)
{
    city = x;
}

template <class T>
void Address<T>::setState(T x)
{
    state = x;
}

template <class T>
void Address<T>::setZipcode(T x)
{
    zipcode = x;
}

#endif // ADDRESS_H

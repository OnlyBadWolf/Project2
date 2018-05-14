#include"customer.h"

Customer::Customer()
{
     customerName = "";
     customerAddress = "";
     customerInterest = "";
     customerRating = "";
     customerPamhplet = "";
}

Customer::Customer(QString name, QString address, QString interest, QString rating, QString pamphlet)
{
    customerName = name;
    customerAddress = address;
    customerInterest = interest;
    customerRating = rating;
    customerPamhplet = pamphlet;
}

Customer::Customer(const Customer & otherCustomer)
{
    customerName = otherCustomer.getCustomerName();
    customerAddress = otherCustomer.getCustomerAddress();
    customerInterest = otherCustomer.getCustomerInterest();
    customerRating = otherCustomer.getCustomerRating();
    customerPamhplet = otherCustomer.getCustomerPamphlet();
}

QString Customer::getCustomerName() const
{
    return customerName;
}

QString Customer::getCustomerAddress() const
{
    return customerAddress;
}

QString Customer::getCustomerInterest() const
{
    return customerInterest;
}

QString Customer::getCustomerRating() const
{
    return customerRating;
}

QString Customer::getCustomerPamphlet() const
{
    return customerPamhplet;
}

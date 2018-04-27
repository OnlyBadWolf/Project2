#include "maininterface.h"
#include "ui_maininterface.h"
#include "dbmanager.h"

MainInterface::MainInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainInterface)
{
    ui->setupUi(this);

    if(dbManager::instance().isOpen())
    {
        ui->label_status->setText("Success! Connected to database");
    }
    else
    {
        ui->label_status->setText("Failed to connect to database");
    }
}

MainInterface::~MainInterface()
{
    delete ui;
}

void MainInterface::on_SilverProductDetails_clicked()
{
        ui->HomeWidget->setCurrentIndex(3);
}

void MainInterface::on_GoldProductDetails_clicked()
{
    ui->HomeWidget->setCurrentIndex(2);
}

void MainInterface::on_PlatinumProductDetails_clicked()
{
    ui->HomeWidget->setCurrentIndex(1);
}

void MainInterface::on_Platinum_BackToHome_clicked()
{
    ui->HomeWidget->setCurrentIndex(0);
}

void MainInterface::on_Gold_BackToHome_2_clicked()
{
    ui->HomeWidget->setCurrentIndex(0);
}

void MainInterface::on_Silver_BackToHome_clicked()
{
    ui->HomeWidget->setCurrentIndex(0);
}

void MainInterface::on_WriteReviewButton_clicked()
{
    ui->Review_Page->setCurrentIndex(1);
}

void MainInterface::on_buttonBox_accepted()
{
    ui->Review_Page->setCurrentIndex(0);

    // Add review to database
}

void MainInterface::on_buttonBox_rejected()
{
    ui->Review_Page->setCurrentIndex(0);

    // Do not add review to database
}

void MainInterface::on_BuyNowButton_clicked()
{
    ui->PaymentInformation->setCurrentIndex(2);
}

void MainInterface::on_BackButton_clicked()
{
    ui->PaymentInformation->setCurrentIndex(0);
}

void MainInterface::on_officiallyBuyNowButton_clicked()
{
    ui->PaymentInformation->setCurrentIndex(1);
}

void MainInterface::on_loginButton_clicked()
{
    QString username;
    QString password;

    username = ui->Username_lineEdit->text();
    password = ui->Password_LineEdit->text();

    if(username == "admin123" && password == "password123")
    {
        ui->Username_lineEdit->setText("");
        ui->Password_LineEdit->setText("");
        ui->label_status->setText("");
        ui->AdminWidget->setCurrentIndex(1);
    }
    else
    {

        ui->label_status->setText("Invalid Username or Password");
        ui->Password_LineEdit->setText("");
    }
}

void MainInterface::on_customer_listings_clicked()
{
    ui->AdminWidget->setCurrentIndex(2);
}

void MainInterface::on_logout_clicked()
{
    ui->AdminWidget->setCurrentIndex(0);
}

void MainInterface::on_back1_clicked()
{
    ui->AdminWidget->setCurrentIndex(1);
}

void MainInterface::on_sort_name_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT name,address,interest,rating,pamphlet FROM customers ORDER BY name ASC");
    query.exec();

    model->setQuery(query);
    ui->table_listings->setModel(model);
}

void MainInterface::on_sort_key_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT name,address,interest,rating,pamphlet FROM customers WHERE rating = 'key' ORDER BY name ASC");
    query.exec();

    model->setQuery(query);
    ui->table_listings->setModel(model);
}

void MainInterface::on_sort_purchases_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT name,purchase,price,quantity,total FROM transactions ORDER BY name ASC");
    query.exec();

    model->setQuery(query);
    ui->table_listings->setModel(model);
}

void MainInterface::on_add_customer_clicked()
{
    ui->AdminWidget->setCurrentIndex(3);
}

void MainInterface::on_pushButton_3_clicked()
{
    ui->AdminWidget->setCurrentIndex(1);
    ui->pamphlet->setCurrentIndex(0);
    ui->interest->setCurrentIndex(0);
    ui->rating->setCurrentIndex(0);
    ui->name_edit->clear();
    ui->address_edit->clear();
    ui->add_status->setText("Status");
}

void MainInterface::on_add_clicked()
{
    QString name;
    QString address;
    QString interest;
    QString rating;
    QString pamphlet;

    name = ui->name_edit->text();
    address = ui->address_edit->text();
    interest = ui->interest->currentText();
    rating = ui->rating->currentText();
    pamphlet = ui->pamphlet->currentText();

    if(!dbManager::instance().customerExists(Customer(name, address, interest, rating, pamphlet)))
    {
        if(dbManager::instance().addCustomer(Customer(name, address, interest, rating, pamphlet)))
        {
            ui->add_status->setText("Customer Added");
        }
        else
        {
            ui->add_status->setText("Failed To Add Customer");
        }
    }
    else
    {
        ui->add_status->setText("Customer already exists");
    }
}

void MainInterface::on_pushButton_5_clicked()
{
    ui->AdminWidget->setCurrentIndex(4);
}

void MainInterface::on_pushButton_6_clicked()
{
    ui->AdminWidget->setCurrentIndex(1);
    ui->name_search->clear();
    ui->delete_status->setText("Status");
}

void MainInterface::on_search_customer_clicked()
{
    QString name;
    QString address;
    QString interest;
    QString rating;
    QString pamphlet;
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    name = ui->name_search->text();

    query.prepare("SELECT name,address,interest,rating,pamphlet FROM customers WHERE name = :name");
    query.bindValue(":name", name);
    query.bindValue(":address", address);
    query.bindValue(":interest", interest);
    query.bindValue(":rating", rating);
    query.bindValue(":pamhplet", pamphlet);
    query.exec();

    if(dbManager::instance().customerExists(Customer(name, address, interest, rating, pamphlet)))
    {
        ui->delete_status->setText("Customer found");
    }
    else
    {
        ui->delete_status->setText("Sorry customer does not exists in the database");
    }

    model->setQuery(query);
    ui->table_search->setModel(model);
}

void MainInterface::on_delete_customer_clicked()
{
    QString name;
    QString address;
    QString interest;
    QString rating;
    QString pamphlet;

    name = ui->name_search->text();

    if(dbManager::instance().customerExists(Customer(name, address, interest, rating, pamphlet)))
    {
        if(dbManager::instance().deleteCustomer(Customer(name, address, interest, rating, pamphlet)))
        {
            ui->delete_status->setText("Customer Removed");
        }
        else
        {
            ui->delete_status->setText("Failed To Remove Customer'");
        }
    }
    else
    {
        ui->delete_status->setText("Customer Could Not Be Found");
    }
}

void MainInterface::on_pushButton_7_clicked()
{
    ui->AdminWidget->setCurrentIndex(5);
}

void MainInterface::on_pushButton_8_clicked()
{
    ui->AdminWidget->setCurrentIndex(1);
    ui->search_name->clear();
    ui->name_edit_2->clear();
    ui->address_edit_2->clear();
    ui->pamphlet_2->setCurrentIndex(0);
    ui->interest_2->setCurrentIndex(0);
    ui->rating_2->setCurrentIndex(0);
    ui->search_status->setText("Status");
}

void MainInterface::on_search_button_clicked()
{
    QString name;
    QString address;
    QString interest;
    QString rating;
    QString pamphlet;
    QSqlQuery query;
    int interestIndex = 0;
    int ratingIndex = 0;
    int pamphletIndex = 0;

    name = ui->search_name->text();

    query.prepare("SELECT name,address,interest,rating,pamphlet FROM customers WHERE name = :name");
    query.bindValue(":name", name);
    query.bindValue(":address", address);
    query.bindValue(":interest", interest);
    query.bindValue(":rating", rating);
    query.bindValue(":pamhplet", pamphlet);
    query.exec();

    if(dbManager::instance().customerExists(Customer(name, address, interest, rating, pamphlet)))
    {
        ui->search_status->setText("Customer found");
    }
    else
    {
        ui->search_status->setText("Sorry customer does not exists in the database");
    }

    while(query.next())
    {
        name = query.value(0).toString();
        address = query.value(1).toString();
        interest = query.value(2).toString();
        rating = query.value(3).toString();
        pamphlet = query.value(4).toString();
    }

    if(interest == "very interested")
    {
        interestIndex = 1;
    }
    else if(interest == "somewhat interested")
    {
        interestIndex = 2;
    }
    else if(interest == "not interested")
    {
        interestIndex = 3;
    }

    if(rating == "key")
    {
        ratingIndex = 1;
    }
    else if(rating == "nice to have")
    {
        ratingIndex = 2;
    }

    if(pamphlet == "yes")
    {
        pamphletIndex = 1;
    }
    else if(pamphlet == "no")
    {
        pamphletIndex = 2;
    }

    ui->name_edit_2->setText(name);
    ui->address_edit_2->setText(address);
    ui->interest_2->setCurrentIndex(interestIndex);
    ui->rating_2->setCurrentIndex(ratingIndex);
    ui->pamphlet_2->setCurrentIndex(pamphletIndex);
}

void MainInterface::on_update_clicked()
{
    QString name;
    QString address;
    QString interest;
    QString rating;
    QString pamphlet;
    QSqlQuery query;

    query.prepare("UPDATE customers SET name = :name, address = :address, interest = :interest, rating = :rating, pamphlet = :pamphlet WHERE name = :name");
    query.bindValue(":name", ui->name_edit_2->text());
    query.bindValue(":address", ui->address_edit_2->text());
    query.bindValue(":interest", ui->interest_2->currentText());
    query.bindValue(":rating", ui->rating_2->currentText());
    query.bindValue(":pamphlet", ui->pamphlet_2->currentText());

    if(query.exec())
    {
        qDebug() << "Update Successful";
        ui->search_status->setText("Update Successful");
    }
    else
    {
        qDebug() << "Update Failed" << query.lastError();
        ui->search_status->setText("Update Failed");
    }
}

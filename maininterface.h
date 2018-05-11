#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QMainWindow>
#include <QtCore/QCoreApplication>
#include <QDebug>
#include <iostream>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "dbmanager.h"

namespace Ui {
class MainInterface;
}

class MainInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainInterface(QWidget *parent = 0);
    ~MainInterface();

private slots:


    void on_SilverProductDetails_clicked();

    void on_GoldProductDetails_clicked();

    void on_PlatinumProductDetails_clicked();

    void on_Platinum_BackToHome_clicked();

    void on_Gold_BackToHome_2_clicked();

    void on_Silver_BackToHome_clicked();

    void on_WriteReviewButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_BuyNowButton_clicked();

    void on_BackButton_clicked();

    void on_officiallyBuyNowButton_clicked();

    void on_loginButton_clicked();

    void on_customer_listings_clicked();

    void on_logout_clicked();

    void on_back1_clicked();

    void on_sort_name_clicked();

    void on_sort_key_clicked();

    void on_sort_purchases_clicked();

    void on_add_customer_clicked();

    void on_pushButton_3_clicked();

    void on_add_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_search_customer_clicked();

    //void on_AdminWidget_currentChanged(int arg1);//

    void on_delete_customer_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_search_button_clicked();

    void on_update_clicked();

    void on_BackButton_2_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainInterface *ui;
};

#endif // MAININTERFACE_H

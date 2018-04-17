#include "maininterface.h"
#include "ui_maininterface.h"

MainInterface::MainInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainInterface)
{
    ui->setupUi(this);
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

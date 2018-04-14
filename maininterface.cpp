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

void MainInterface::on_cardType_radioButton_clicked()
{

}

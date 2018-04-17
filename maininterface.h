#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QMainWindow>

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

private:
    Ui::MainInterface *ui;
};

#endif // MAININTERFACE_H

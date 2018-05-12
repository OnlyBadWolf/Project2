#include "maininterface.h"
#include "ui_maininterface.h"
#include "dbmanager.h"

MainInterface::MainInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainInterface)
{
    ui->setupUi(this);

    // CHECKING IF DATABASE WAS OPENNED"
    if(dbManager::instance().isOpen())
    {
        ui->label_status->setText("Success! Connected to database");
    }
    else
    {
        ui->label_status->setText("Failed to connect to database");
    }


    // SET ALL TABS TO THE RIGHT WIDGET PAGE
    ui->HomeWidget->setCurrentIndex(0);
    ui->Review_Page->setCurrentIndex(0);
    ui->PaymentInformation->setCurrentIndex(0);
    ui->AdminWidget->setCurrentIndex(0);

    // MAKE REVIEWS AVAILABLE
    makeReviewsAvailable();

    // SETTING PLATINUM INFO
    ui->Platinum_textEdit->setText("JOSEPHDEFENDER Antivirus SAFE is a great collection of antivirus software tools, and while it's a bit more expensive than some of the other antivirus software on this best of list, the amount of features you get makes the cost worthwhile."
                                   "\n\nWith JOSEPHDEFENDER Antivirus SAFE, you get the brilliant antivirus software from JOSEPHDEFENDER, along with banking protection for safe online shopping, family safety tools and a device finder that lets you track your lost Android or iOS device, and if needs be remotely lock or delete it as well."
                                   "\n\nThe package typically receives maximum marks for protection from AV-Test, and generally scores highly with AV-Comparatives, too. They also say it can generate significantly more false positives than most of the competition, but how that affects you will vary depending on how you use your computer."
                                   "\n\nThe interface is a major plus. It's extremely easy to use, lightweight, and for the most part you can just leave the app alone to look after your PC. The program has minimal effect on your system performance, and if you do need to intervene then you can generally solve any issues in a couple of clicks."
                                   "\n\nIn 2018, JOSEPHDEFENDER Anti-Virus SAFE remains an appealing package: fast, lightweight, and able to run alongside many other security tools without conflict.");

    ui->Platinum_textEdit->setReadOnly(1);

    // SETTING SILVER INFO
    ui->silver_textEdit->setText("In a world packed with free security software, MORGANDEFENDER Antivirus Plus 2018's annual fee may look expensive, but there's plenty of bang for your buck."
                                 "\n\nMORGANDEFENDER’s engine is one of the most accurate and reliable around, for instance, loved by all the big independent testers."
                                 "\n\nWeb filtering blocks access to malicious sites, a secure browser keeps your online financial transactions safe, and there's a password manager which auto-completes credit card details in web forms."
                                 "\n\nAn excellent anti-phishing module alerts you to malicious links in your search engine results, and blocks access to dangerous sites."
                                 "\n\nThere are one or two issues – it grabs more resources than average and might conflict with some programs – but MORGANDEFENDER Antivirus Plus 2018 is still a likeable package which offers excellent detection rates, great performance, and more than enough bonus features to justify the price."
                                 "\n\nMORGANDEFENDER Internet Security 2018 builds on AVP 2018 and triples the number of devices covered plus offers anti-spam, firewall, parental advisor, file encryption and anti-theft features."
                                 "\n\nStrangely, it's cheaper than the basic MORGANDEFENDER Antivirus Plus at the time of writing and for a little bit more you can purchase the Total Security 2018 edition. It adds all of the above and covers up to five PCs, Macs and Android devices (iOS is ‘coming soon’).");

    ui->silver_textEdit->setReadOnly(1);

    // SETTING GOLD INFO
    ui->gold_textEdit->setText("\If you judge an antivirus on the length of its feature list, NAVIDDEFENDER Antivirus 2018 Edition might be a disappointment. There’s no firewall, password manager, file shredder, vulnerability scanner or any of the bundled extras you'll often find elsewhere."
                               "\n\nThis doesn't mean the package is short on power, it's just more focused on the antivirus fundamentals. NAVIDDEFENDER Antivirus 2018 Edition comes with real-time malware protection, an anti-ransomware layer, exploit protection, URL filtering to block malicious websites, and modules to prevent attacks using PowerShell and malicious scripts."
                               "\n\nA Device Control module limits the risk of infection from other devices by controlling access to USB sticks, external hard drives, optical storage media, even devices connecting by Bluetooth and FireWire. It's an unusual extra, but could make a difference if others are regularly plugging devices into your PC."
                               "\n\nNAVIDDEFENDER Antivirus 2018 Edition isn't aimed at beginners. The interface is clumsy sometimes, some features are very advanced, and even the Help isn't always exactly helpful."
                               "\n\nExperienced users will appreciate NAVIDDEFENDER’s power and configurability, though. Above-average protection does a good job of keeping you safe, and a lightweight design ensures the package won't slow you down."
                               "\n\nOne of the new features in the 2018 Edition is the UEFI Scanner which protects you from threats that attack your PC before Windows has even started."
                               "\n\nNAVIDDEFENDER Internet Security builds on NAVIDDEFENDER and triples the number of devices covered plus offers firewall, botnet protection, webcam protection, antispam and more.");

    ui->gold_textEdit->setReadOnly(1);

    // PROGRAM OPENS TO THE HOME PAGE
    ui->tabWidget->setCurrentIndex(0);
}

MainInterface::~MainInterface()
{
    delete ui;
}

void MainInterface::on_SilverProductDetails_clicked()
{
    // GO TO SILVER INFO
    ui->HomeWidget->setCurrentIndex(3);
}

void MainInterface::on_GoldProductDetails_clicked()
{
    // GO TO GOLD INFO
    ui->HomeWidget->setCurrentIndex(2);
}

void MainInterface::on_PlatinumProductDetails_clicked()
{
    // GO TO PLATINUM INFO
    ui->HomeWidget->setCurrentIndex(1);
}

void MainInterface::on_Platinum_BackToHome_clicked()
{
    // GO BACK TO HOME
    ui->HomeWidget->setCurrentIndex(0);
}

void MainInterface::on_Gold_BackToHome_2_clicked()
{
    // GO BACK TO HOME
    ui->HomeWidget->setCurrentIndex(0);
}

void MainInterface::on_Silver_BackToHome_clicked()
{
    // GO BACK TO HOME
    ui->HomeWidget->setCurrentIndex(0);
}

void MainInterface::on_WriteReviewButton_clicked()
{
    // GO WRITE A REVIEW
    ui->Review_Page->setCurrentIndex(1);
}

void MainInterface::on_buttonBox_accepted()
{
    try
    {
        QSqlQuery query;
        QString name = ui->name_lineEdit->text();
        QString rating = ui->rate_spinBox->text();
        QString tier = ui->product_comboBox->currentText();
        QString comment =  ui->comment->text();

        if (name == NULL || comment == NULL || tier == "Select Tier")
        {
            throw QString("Not an accepted");
        }

        ui->Review_Page->setCurrentIndex(0);

        query.prepare("INSERT INTO reviews (Name, Rating, Tier, Comment) VALUES (:name, :rating, :tier, :comment)");
        query.bindValue(":name", name);
        query.bindValue(":rating", rating);
        query.bindValue(":tier", tier);
        query.bindValue(":comment", comment);

        if(query.exec())
        {
            qDebug() << "comment success:";
        }
        else
        {
            qDebug() << "comment fail:"
                     << query.lastError();
        }

        // MAKE REVIEWS AVAILABLE
        makeReviewsAvailable();
    }

    catch(QString statement)
    {
        qDebug() << statement;

        ui->reviewStatus->setText("Must include tier, nickname, and comment.");
    }

}

void MainInterface::on_buttonBox_rejected()
{
    // RETURN TO REVIEWS
    ui->Review_Page->setCurrentIndex(0);
}

void MainInterface::on_BuyNowButton_clicked()
{
    QString Silver = ui->silver_spinBox->text();
    QString Gold = ui->gold_spinBox->text();
    QString Platinum = ui->platinum_spinBox->text();

    int silverAmt = Silver.toInt();
    int goldAmt = Gold.toInt();
    int platinumAmt = Platinum.toInt();


    ui->PaymentInformation->setCurrentIndex(2);

    ui->silver_spinBox_2->setValue(silverAmt);
    ui->gold_spinBox_2->setValue(goldAmt);
    ui->platinum_spinBox_2->setValue(platinumAmt);

    // SHOW NEW PRICE
    purchaseAmt(silverAmt, goldAmt, platinumAmt);

}

void MainInterface::on_BackButton_clicked()
{
    ui->PaymentInformation->setCurrentIndex(0);
}

void MainInterface::on_officiallyBuyNowButton_clicked()
{
    QString name;
    QString silver;
    QString gold;
    QString plat;
    QString purchaseTotal;
    int qtySilver;
    int qtyGold;
    int qtyPlat;
    double total;

    try
    {
        name = ui->firstName_lineEdit->text();
        silver = ui->silver_spinBox_2->text();
        qtySilver = silver.toInt();
        gold = ui->gold_spinBox_2->text();
        qtyGold = gold.toInt();
        plat = ui->platinum_spinBox_2->text();
        qtyPlat = plat.toInt();
        purchaseTotal = ui->totalAmount->text();
        total = purchaseTotal.toDouble();

        if (name == NULL || (qtySilver == 0 && qtyGold == 0 && qtyPlat == 0))
        {
            throw QString("No name provided or did not select a quantity.");
        }

        if(dbManager::instance().addPurchase(Purchases(name, qtySilver, qtyGold, qtyPlat, total)))
        {
            qDebug() << "purchase succesful";
        }
        else
        {
            qDebug() << "purchase failed";
            ui->purchaseStatus->setText("Purchase Failed.");
        }

        ui->PaymentInformation->setCurrentIndex(1);
    }

    catch(QString statement)
    {
        qDebug() << statement;
        ui->purchaseStatus->setText("Need Failed.");
    }
}

void MainInterface::on_loginButton_clicked()
{
    QString username;
    QString password;

    username = ui->Username_lineEdit->text();
    password = ui->Password_LineEdit->text();

    if(username == "admin123" && password == "123")
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

    ui->table_listings->resizeColumnsToContents();
    ui->table_listings->resizeRowsToContents();
}

void MainInterface::on_sort_key_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT Name,Address,Interest,Rating,Pamphlet FROM customers WHERE rating = 'Key' ORDER BY name ASC");
    query.exec();

    model->setQuery(query);
    ui->table_listings->setModel(model);

    ui->table_listings->resizeColumnsToContents();
    ui->table_listings->resizeRowsToContents();
}

void MainInterface::on_sort_purchases_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT name,silver,gold,platinum,total FROM transactions ORDER BY name ASC");
    query.exec();

    model->setQuery(query);
    ui->table_listings->setModel(model);

    ui->table_listings->resizeColumnsToContents();
    ui->table_listings->resizeRowsToContents();
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
    ui->add_status->setText("Add Status");
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
        ui->add_status->setText("Customer Already Exists");
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
        ui->delete_status->setText("Customer Found");
    }
    else
    {
        ui->delete_status->setText("Customer does not exists in the Database");
    }

    model->setQuery(query);
    ui->table_search->setModel(model);

    ui->table_search->resizeColumnToContents(1);
    ui->table_search->resizeRowsToContents();
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
            ui->delete_status->setText("Failed to Remove Customer'");
        }
    }
    else
    {
        ui->delete_status->setText("Customer could not be Found");
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
        ui->search_status->setText("Customer Found");
    }
    else
    {
        ui->search_status->setText("Customer does not exists in the Database");
    }

    while(query.next())
    {
        name = query.value(0).toString();
        address = query.value(1).toString();
        interest = query.value(2).toString();
        rating = query.value(3).toString();
        pamphlet = query.value(4).toString();
    }

    if(interest == "Very Interested")
    {
        interestIndex = 1;
    }
    else if(interest == "Somewhat Interested")
    {
        interestIndex = 2;
    }
    else if(interest == "Not Interested")
    {
        interestIndex = 3;
    }

    if(rating == "Key")
    {
        ratingIndex = 1;
    }
    else if(rating == "Nice to Have")
    {
        ratingIndex = 2;
    }

    if(pamphlet == "Yes")
    {
        pamphletIndex = 1;
    }
    else if(pamphlet == "No")
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

   name =  ui->name_edit_2->text();
   address = ui->address_edit_2->text();
   interest = ui->interest_2->currentText();
   rating = ui->rating_2->currentText();
   pamphlet = ui->pamphlet_2->currentText();

   try
   {
       if (interest == "[Please Select One]" || rating == "[Please Select One]" || pamphlet == "[Please Select One]")
       {
           throw QString("Must select from opitions");
       }

       query.prepare("UPDATE customers SET name = :name, address = :address, interest = :interest, rating = :rating, pamphlet = :pamphlet WHERE name = :name");
       query.bindValue(":name", name);
       query.bindValue(":address", address);
       query.bindValue(":interest", interest);
       query.bindValue(":rating", rating);
       query.bindValue(":pamphlet", pamphlet);

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
   catch (QString statemet)
   {
       qDebug () << statemet;
       ui->search_status->setText("Update Failed");
   }

}

void MainInterface::on_BackButton_2_clicked()
{
    ui->PaymentInformation->setCurrentIndex(0);
}

void MainInterface::on_buyButton_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}

void MainInterface::on_pamplet_button_clicked()
{
    QString name;
    QString street;
    QString state;
    QString city;
    QString zip;
    QString address;
    QSqlQuery query;

    try
    {
        name = ui->firstName_lineEdit_2->text();

        street = ui->address_lineEdit_2->text();
        state = ui->state_comboBox_2->currentText();
        city = ui->city_lineEdit_2->text();
        zip = ui->zip_lineEdit_2->text();

        address = street + ", " + city + ", " + state + " " + zip;

        if (name == NULL || address == NULL)
        {
            throw QString("Nothing was inputed");
        }

        query.prepare("INSERT INTO Pamphlet (Name, Address) VALUES (:Name, :Address)");
        query.bindValue(":Name", name);
        query.bindValue(":Address", address);

        if(query.exec())
        {
            qDebug() << "pamphlet requested success:";
            ui->pampletStatus->setText("Succesful");
        }
        else
        {
            qDebug() << "pamphlet requested failed:"
                     << query.lastError();
            ui->pampletStatus->setText("Failed");
        }

    }

    catch(QString statement)
    {
        qDebug() << statement;
    }
}

void MainInterface::on_Pamplet_BackToHome_clicked()
{
    ui->HomeWidget->setCurrentIndex(0);
}

void MainInterface::on_GetPamphlet_pushButton_clicked()
{
    ui->HomeWidget->setCurrentIndex(4);
}

void MainInterface::on_SortByPampletRequest_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;


    query.prepare("SELECT name,address FROM Pamphlet ORDER BY name ASC");
    query.exec();

    model->setQuery(query);
    ui->table_listings->setModel(model);

    ui->table_listings->resizeColumnsToContents();
    ui->table_listings->resizeRowsToContents();
}

void MainInterface::on_silver_spinBox_2_valueChanged(int arg1)
{
    QString silver;
    QString gold;
    QString plat;
    int qtySilver;
    int qtyGold;
    int qtyPlat;


    qtySilver = arg1;
    gold = ui->gold_spinBox_2->text();
    qtyGold = gold.toInt();
    plat = ui->platinum_spinBox_2->text();
    qtyPlat = plat.toInt();

    // SHOW NEW PRICE
    purchaseAmt(qtySilver, qtyGold, qtyPlat);
}

void MainInterface::on_gold_spinBox_2_valueChanged(int arg1)
{
    QString silver;
    QString gold;
    QString plat;
    int qtySilver;
    int qtyGold;
    int qtyPlat;

    silver = ui->silver_spinBox_2->text();
    qtySilver = silver.toInt();
    qtyGold = arg1;
    plat = ui->platinum_spinBox_2->text();
    qtyPlat = plat.toInt();

    // SHOW NEW PRICE
    purchaseAmt(qtySilver, qtyGold, qtyPlat);

}

void MainInterface::on_platinum_spinBox_2_valueChanged(int arg1)
{
    QString silver;
    QString gold;
    QString plat;
    int qtySilver;
    int qtyGold;
    int qtyPlat;

    silver = ui->silver_spinBox_2->text();
    qtySilver = silver.toInt();
    gold = ui->gold_spinBox_2->text();
    qtyGold = gold.toInt();
    qtyPlat = arg1;

    // SHOW NEW PRICE
    purchaseAmt(qtySilver, qtyGold, qtyPlat);
}

void MainInterface::makeReviewsAvailable()
{
    // MAKE THE REVIEWS AVAILABLE
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT Name,Rating,Tier,Comment FROM reviews");
    query.exec();

    model->setQuery(query);
    ui->tableReview->setModel(model);


    // RESIZE THE REVIEW TABLE
    ui->tableReview->resizeColumnsToContents();
    ui->tableReview->resizeRowsToContents();
}

void MainInterface::purchaseAmt(double qtySilver, double qtyGold, double qtyPlat)
{
    double sub;
    double tax;
    double total;

    sub = (qtySilver * 29.99) + (qtyGold * 49.99) + (qtyPlat * 69.99);
    tax = sub * 0.07;
    total = sub + tax;

    QString subTotal = "$ " + QString::number(sub,'f',2);
    QString totalTax = "$ " + QString::number(tax,'f',2);
    QString purchaseTotal = "$ " + QString::number(total,'f',2);

    ui->subtotal->setText(subTotal);
    ui->salesTax->setText(totalTax);
    ui->totalAmount->setText(purchaseTotal);
}


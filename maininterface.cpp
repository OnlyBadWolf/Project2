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

    // MAKE RATING AUTOMATICALLY 5
    ui->rate_spinBox->setValue(5);

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
    ui->gold_textEdit->setText("If you judge an antivirus on the length of its feature list, NAVIDDEFENDER Antivirus 2018 Edition might be a disappointment. There’s no firewall, password manager, file shredder, vulnerability scanner or any of the bundled extras you'll often find elsewhere."
                               "\n\nThis doesn't mean the package is short on power, it's just more focused on the antivirus fundamentals. NAVIDDEFENDER Antivirus 2018 Edition comes with real-time malware protection, an anti-ransomware layer, exploit protection, URL filtering to block malicious websites, and modules to prevent attacks using PowerShell and malicious scripts."
                               "\n\nA Device Control module limits the risk of infection from other devices by controlling access to USB sticks, external hard drives, optical storage media, even devices connecting by Bluetooth and FireWire. It's an unusual extra, but could make a difference if others are regularly plugging devices into your PC."
                               "\n\nNAVIDDEFENDER Antivirus 2018 Edition isn't aimed at beginners. The interface is clumsy sometimes, some features are very advanced, and even the Help isn't always exactly helpful."
                               "\n\nExperienced users will appreciate NAVIDDEFENDER’s power and configurability, though. Above-average protection does a good job of keeping you safe, and a lightweight design ensures the package won't slow you down."
                               "\n\nOne of the new features in the 2018 Edition is the UEFI Scanner which protects you from threats that attack your PC before Windows has even started."
                               "\n\nNAVIDDEFENDER Internet Security builds on NAVIDDEFENDER and triples the number of devices covered plus offers firewall, botnet protection, webcam protection, antispam and more.");

    ui->gold_textEdit->setReadOnly(1);

    // SETTING ABOUT US
    ui->aboutUs_textEdit->setText("Why is cybersecurity important?"
                                  "\n\nIn today's connected world, everyone benefits from advanced cyberdefense programs. At an individual level, a cybersecurity attack can result in everything from identity theft, to extortion attempts, to the loss of important data like family photos. Everyone relies on critical infrastructure like power plants, hospitals, and financial service companies. Securing these and other organizations is essential to keeping our society functioning."
                                  "\n\nEveryone also benefits from the work of cyberthreat researchers, like the team of 250 threat researchers at Talos, who investigate new and emerging threats and cyber attack strategies. They reveal new vulnerabilities, educate the public on the importance of cybersecurity, and strengthen open source tools. Their work makes the Internet safer for everyone.");

    ui->aboutUs_textEdit->setReadOnly(1);

    // SETTING CONTACT US
    ui->contactUs_textEdit->setText("United States"
                                    "\nBusiness Support (Including ICyberSecurity  SaaS Products)"
                                    "\n\nCustomer Service"
                                    "\nFor assistance with non-technical questions, including product activations, license enquiries, grant numbers, support entitlements, and ServicePortal passwords, our Customer Support team can help online or via phone."
                                    "\nCorporate Customer Service Request Form "
                                    "\n\nTel: 1-888-847-8766\n"
                                    "\n\nTech Support"
                                    "\nCustomers requiring technical assistance on products with a valid Business Support Grant can reach our Technical Support team online or via phone."
                                    "\n\nWebsite: https://support.icybersecurity.com/ "
                                    "\n\nTel: 1-800-937-2237\n"
                                    "\n\nHome & Home Office Support"
                                    "\nOur Customer Support team is standing by to help you over the phone, through online chat, or our community forums. You can also use self-help options, including ICyberSecurity  Virtual Technician and FAQs."
                                    "\n\nWebsite: https://support.icybersecurity.com/ "
                                    "\n\nTel: 1-866-622-3911\n"
                                    "\n\nTotal Satisfaction Promise"
                                    "\nWe are committed to your complete satisfaction. If you are unhappy with your ICyberSecurity Support experience, please submit a case online to our Executive Escalations team and let us make things right. We will take ownership of your problem until it is resolved. That's the ICyberSecurity  promise!");

    ui->contactUs_textEdit->setReadOnly(1);

    // SETTING OUR PROMISE
    ui->guaranteePolicy_textEdit->setText("The number of computer security incidents related to malware and viruses and the resulting cost of business disruption and service restoration continue to escalate.  Implementing antimalware and antivirus systems, blocking unnecessary access to networks and computers, improving user security awareness, and early detection and mitigation of security incidents are best practice actions that must be taken to reduce risks and manage the computing environment."
                                          "\n\n\nLICENSING, MAINTENANCE AND SUPPORT:"
                                          "\n\nMaintenance actions (software updates, definition updates, infections, etc.) shall be logged and retained for a period aligning with [Insert Appropriate Role] and [LEP] requirements to allow proper investigations into malware related incidents."
                                          "\n\nManagement shall ensure proper licensing, tracking, and related documentation.  This shall include processes and procedures supporting:"
                                          "\n\n\t•    Antivirus software installation on all systems."
                                          "\n\n\t•    Regular threat scanning capable of detecting, removing, and protecting \n\tagainst known types of malicious software."
                                          "\n\n\t•    Annual review and re-evaluation of low-risk systems and appliances not \n\tconsidered affected by malicious software based on current best practice."
                                          "\n\n\t•    Pro-active monitoring and update mechanisms supporting this policy."
                                          "\n\n\t•    Verification that mechanisms are in place for preventing users from disabling \n\tor modifying antivirus detection tools."
                                          "\n\n\t•    Processes and procedures for exceptions to the policy exist and are followed \n\tbased on a case-by-case evaluation."
                                          "\n\n\t•    If antivirus mechanisms are disabled, additional security measures may need \n\tto be implemented for the period of time during which antivirus protection is not \n\tactive.");

    ui->guaranteePolicy_textEdit->setReadOnly(1);

    ui->Help_textEdit->setText("Frequently Asked Questions:"
                               "\n\n\nDo We Have To Uninstall The Existing Antivirus Program Before Installing A New One?"
                               "\n\nIf you are changing to a new antivirus product, you will need to uninstall the previous antivirus scanner first. After uninstalling, you must reboot your PC before installing the new scanner."
                               "If you are simply upgrading the existing antivirus software to a newer version of the same product, there is no need to uninstall the older version first. However, if the new version is two or more versions newer than the old, then you will want to uninstall the old version before installing the new. Again, anytime you uninstall an existing antivirus product, be sure to reboot the computer before installing the new scanner."
                               "\n\n\nCan Two Antivirus Scanners Be Run On The Same System At The Same Time?"
                               "\n\nIt is never a good idea to run two antivirus scanners simultaneously. However, if only one of the scanners has real-time protection enabled and the second scanner is used only to manually scan selected files, they may possible co-exist peacefully. In some cases, an antivirus scanner will not install if it detects another antivirus scanner already installed on the system."
                               "\n\n\nWhy Does One Scanner Detect A Virus But Another Does Not?"
                               "\n\nAntivirus is largely signature-based. The signatures are created by the individual vendors and are unique to their products (or the products that use those particular scanning engines. Hence one vendor may have added detection (i.e. a signature) for a particular malware while another vendor may not have."
                               "\n\n\nInstallation Freeze Solution "
                               "\n\nIf the installation stops at the step “Installing Microsoft .Net Framework 4.0…” with the progress bar notification “About five seconds left”, follow the guide below to fix the issue."
                               "\n1.    Create a restore point Click on your operating system to open the guide: "
                               "\n\t•    Windows 10"
                               "\n\t•    Windows Vista / Windows 7 / Windows 8"
                               "\n2.    Click the link corresponding to your operating system to download Microsoft .Net \n\tFramework: "
                               "\n\t•    Windows Vista / Windows 7"
                               "\n\t•    Windows XP"
                               "\n3.    In the browser window, click Download."
                               "\n4.    Run the downloaded installer."
                               "\n5.    Read the license agreement terms and select the check box for I have read and \n\taccept the license terms."
                               "\n6.    Click Install."
                               "\n\n\n\n\nTerms & conditions:"
                               "\n\nIcyberSecurity  Virus Protection Promise Virus Protection Promise includes a virus removal service provided by a Symantec service representative. In the unlikely event that Symantec is unable to remove the virus from your device, You may be entitled to a refund of the IcyberSecurity  subscription or IcyberSecurity  bundle (as applicable). In order to be entitled for a refund, the following terms and condition apply: (a) You must purchase, renew, or upgrade your IcyberSecurity  subscription directly from IcyberSecurity .com, or subscribe to the IcyberSecurity  Automatic Renewal Service online; (b) Your refund will be a full refund based on the actual price paid for your current IcyberSecurity  subscription term. If you purchased a IcyberSecurity  bundle (defined as IcyberSecurity  subscriptions and/or IcyberSecurity  services), your refund will be based on the actual price paid for the term of your current IcyberSecurity  bundle. Or, if your bundled purchase contains a IcyberSecurity  subscription with a non-IcyberSecurity  subscription/product, your refund will be limited to the MSRP of your IcyberSecurity  subscription for the current term, not to exceed the total price paid for that bundle. The refund will be net of any discounts or refunds received and less any shipping, handling and any applicable taxes, except in certain states and countries where shipping, handling and taxes are refundable; (c) If You have purchased the IcyberSecurity  subscription from a retailer, proof of purchase is required; (d) You must have the purchased IcyberSecurity  subscription installed and activated on Your device prior to the time it being infected by viruses.");

    ui->Help_textEdit->setReadOnly(1);

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
        QString retrieveComment =  ui->review_textEdit->toPlainText();
        QString comment;
        int count = 0;
        int i = 0;

        if (name == NULL || retrieveComment == NULL || tier == "Select Tier")
        {
            throw QString("Not an accepted");
        }

        while (retrieveComment[count] != NULL)
        {
            if (count % 55 != 0 || count == 0)
            {
                comment[count + i] = retrieveComment[count - i];
            }
            else
            {
                if (comment[count + i] == " ")
                {
                    comment.insert(count + i,'\n');
                    i++;
                }
                else
                {
                    comment.insert(count + i,"-\n");
                    i++;
                }
            }

            count++;

            qDebug() << comment << endl;
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
            ui->name_lineEdit->clear();
            ui->rate_spinBox->setValue(5);
            ui->product_comboBox->setCurrentIndex(0);
            ui->review_textEdit->clear();
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

    ui->name_lineEdit->clear();
    ui->rate_spinBox->setValue(5);
    ui->product_comboBox->setCurrentIndex(0);
    ui->review_textEdit->clear();
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
    ui->silver_spinBox->setValue(0);
    ui->gold_spinBox->setValue(0);
    ui->platinum_spinBox->setValue(0);
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
            ui->silverQtyPurchased->setText(silver);
            ui->goldQtyPurchased->setText(gold);
            ui->PlatinumQtyPurchased->setText(plat);
            ui->PaymentInformation->setCurrentIndex(1);

            double sub;
            double tax;
            double total;

            sub = (qtySilver * 29.99) + (qtyGold * 49.99) + (qtyPlat * 69.99);
            tax = sub * 0.07;
            total = sub + tax;

            QString subTotal = "$ " + QString::number(sub,'f',2);
            QString totalTax = "$ " + QString::number(tax,'f',2);
            QString purchaseTotal = "$ " + QString::number(total,'f',2);

            ui->subtotal_2->setText(subTotal);
            ui->salesTax_2->setText(totalTax);
            ui->totalAmount_2->setText(purchaseTotal);
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
        ui->purchaseStatus->setText("Purchase Failed.");
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


    query.prepare("SELECT Name,Address,Interest,Rating,Pamphlet FROM customers ORDER BY Name ASC");
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

    query.prepare("SELECT Name,Address,Interest,Rating,Pamphlet FROM customers WHERE rating = 'Key' ORDER BY Name ASC");
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

    query.prepare("SELECT Name,Silver,Gold,Platinum,Total FROM transactions ORDER BY Name ASC");
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
    ui->tabWidget->setCurrentIndex(3);
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


    query.prepare("SELECT Name,Address FROM Pamphlet ORDER BY Name ASC");
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


void MainInterface::on_tabWidget_currentChanged()
{
    // RESET THE REVIEW PAGE
    ui->Review_Page->setCurrentIndex(0);
    ui->name_lineEdit->clear();
    ui->rate_spinBox->setValue(5);
    ui->product_comboBox->setCurrentIndex(0);
    ui->review_textEdit->clear();

    // DISPLAY THE HOME SCREEN
    ui->HomeWidget->setCurrentIndex(0);
}


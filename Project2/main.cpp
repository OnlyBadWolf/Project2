#include "maininterface.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << QCoreApplication::applicationDirPath();

    dbManager::instance();
    dbManager::instance();
    dbManager::instance();

    MainInterface w;
    w.show();

    return a.exec();
}

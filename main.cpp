#include <QCoreApplication>
#include <QDebug>
#include "sysupdate.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // D:/dataBase/MySQL/temp.txt
    QString path = "D:/dataBase";
    Bit64 size = SysUpdate::SysGetSize(path);
    qDebug() << QString("%1 总大小 %2").arg(path).arg(size);

    return a.exec();
}

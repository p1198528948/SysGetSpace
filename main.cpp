#include <QCoreApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QDebug>
#include "sysupdate.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // TODO: 需要实现解析命令行参数功能
    // 解析一个命令行参数
    // 必须是一个合法的路径
    // // -a="C:/A B/Demo.exe"
    QCommandLineOption op1("a");
    op1.setValueName("path"); // 期望值是路径，设置了ValueName后，解析器会认为此命令带值
    QCommandLineParser parser;
    parser.addOption(op1);
    parser.process(a);
    //qDebug() << parser.value(op1);// "C:/A B/Demo.exe"

    QString path = parser.value(op1);

    if(path.isNull() || path.isEmpty())
    {
        // D:/dataBase/MySQL/temp.txt
        path = "D:/dataBase";
    }

    Bit64 size = SysUpdate::SysGetSize(path);
    qDebug() << QString("%1 总大小 %2").arg(path).arg(size);

    return a.exec();
}

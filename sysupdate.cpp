#include <QDir>
#include <QDebug>

#include "sysupdate.h"

SysUpdate::SysUpdate()
{

}

Bit64 SysUpdate::SysGetDirSize(const QString &path)
{
    QDir dir(path);
    Bit64 size = 0;

    //返回文件信息
    foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Files))
    {
        //计算文件大小
        size += fileInfo.size();
        qDebug() << QString("[SysGetSize] %1 %2").arg(size).arg(fileInfo.fileName());
    }
    //返回所有子目录，并进行过滤
    foreach(QString subDir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        //若存在子目录，则递归调用SysGetDirSize()函数
        size += SysGetDirSize(path + QDir::separator() + subDir);
    }

    return size;
}

Bit64 SysUpdate::SysGetFileSize(const QString &path)
{
    QFileInfo info(path);
    if (info.exists())
    {
        return info.size();
    }

    return -1;
}

Bit64 SysUpdate::SysGetSize(const QString &path)
{
    QFileInfo info(path);
    Bit64 size = 0;

    if(info.exists())
    {
        if(info.isFile())
        {
            size = SysGetFileSize(path);
            return size;
        }
        else if(info.isDir())
        {
            size = SysGetDirSize(path);
            return size;
        }
    }
    return -1;
}

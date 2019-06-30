#ifndef SYSUPDATE_H
#define SYSUPDATE_H

#include <QObject>

typedef long long int Bit64;
typedef double fBit64;

class SysUpdate
{
public:
    SysUpdate();
    ~SysUpdate();


    static Bit64 SysGetDirSize(const QString &path);
    static Bit64 SysGetFileSize(const QString &path);
    static Bit64 SysGetSize(const QString &path);
};

#endif // SYSUPDATE_H

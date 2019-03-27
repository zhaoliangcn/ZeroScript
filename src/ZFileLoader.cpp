#include "ZFileLoader.h"
#include <windows.h>
ZFileLoader::ZFileLoader()
{
    //ctor
}

ZFileLoader::~ZFileLoader()
{
    //dtor
}
ZString ZFileLoader::LoadFile(const char * FilePathName)
{
    ZString zRet;
    #ifdef _WIN32
    HANDLE hFile = CreateFile(FilePathName,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    if(hFile!=INVALID_HANDLE_VALUE)
    {
        DWORD dwSize = GetFileSize(hFile,NULL);
        unsigned char * buffer = (unsigned char *)malloc(dwSize);
        memset(buffer,0,dwSize);
        DWORD ReadCount = 0;
        ReadFile(hFile,buffer,dwSize,&ReadCount,NULL);
        zRet=(char * )buffer,
        CloseHandle(hFile);
    }

    #endif // _WIN32
    return zRet;
}

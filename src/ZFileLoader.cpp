#include "ZFileLoader.h"
#include <windows.h>
#include <iostream>
#include <fstream>
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
    HANDLE hFile = CreateFileA(FilePathName,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
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
    #else
    std::ifstream infile(FilePathName,std::ios::binary);
    infile.seekg(0,std::ios::end);
    size_t size = infile.tellg();
    infile.seekg(2,std::ios::beg);
    char * buffer =(char*) malloc(size);
    memset(buffer,0,size);
    infile.read(buffer,size);
    zRet=buffer;
    free(buffer);
    #endif // _WIN32
    return zRet;
}

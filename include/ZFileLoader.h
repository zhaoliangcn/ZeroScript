#ifndef ZFILELOADER_H
#define ZFILELOADER_H
#include "zstring.h"

class ZFileLoader
{
    public:
        ZFileLoader();
        virtual ~ZFileLoader();

        ZString LoadFile(const char * FilePathName);
    protected:

    private:
};

#endif // ZFILELOADER_H

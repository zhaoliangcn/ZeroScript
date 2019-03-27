#ifndef ZEROLEX_H
#define ZEROLEX_H

#include "zstring.h"
#include "ZAst.h"
#include "ZReservedWord.h"
class ZeroLex
{
    public:
        ZeroLex();
        virtual ~ZeroLex();
    bool Parse(const char * content);
    bool Parse(ZString & content);
    ZString GetNextToken();
    ZString PeekNextToken();
    ZString PeekNextToken(int & nexttokenpos);
    void SetCurrentTokenPos(int pos);
    ZAst BuildAst(const char * content);
    ZAst BuildAst(ZString & content);
    protected:

    private:
        ZString CurrentToken;
        ZString LastToken;
        int tokenpos;
        ZString FullContent;
};

#endif // ZEROLEX_H

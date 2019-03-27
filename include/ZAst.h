#ifndef ZAST_H
#define ZAST_H

#include "ZAstNode.h"
class ZAst
{
    public:
        ZAst();
        virtual ~ZAst();

    protected:

    private:
        ZAstNode rootNode;
};

#endif // ZAST_H

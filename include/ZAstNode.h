#ifndef ZASTNODE_H
#define ZASTNODE_H


class ZAstNode
{
    public:
        ZAstNode();
        virtual ~ZAstNode();

    protected:

    private:
        ZAstNode * parentNode;
        ZAstNode * childNode;
};

#endif // ZASTNODE_H

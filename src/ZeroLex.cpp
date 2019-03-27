#include "ZeroLex.h"
#include "ZeroKeyword.h"
#include "ZTerminalChar.h"
#include <ctype.h>
#include <stdio.h>
ZeroLex::ZeroLex()
{
    //ctor
}

ZeroLex::~ZeroLex()
{
    //dtor
}
ZString ZeroLex::GetNextToken()
{
    ZString token;
    char iter;
    while(tokenpos<FullContent.GetLength())
    {
        iter = FullContent.it(tokenpos);

        if(!isspace(iter))
        {
            if(IsTerminalCharacter(iter))
            {
                if(token.IsEmpty())
                {
                    if(iter==Z_OpAdd)
                    {
                        char iter2 = FullContent.it(tokenpos+1);
                        if(iter2==Z_OpAssign)
                        {
                            token=Z_OpAddAndAssign;
                            tokenpos+=2;
                            break;
                        }
                        else if(iter2==Z_OpAdd)
                        {
                            token = Z_OpSelfAdd;
                            tokenpos+=2;
                            break;
                        }

                    }
                    else if(iter==Z_OpSub)
                    {
                        char iter2= FullContent.it(tokenpos+1);
                        if(iter2==Z_OpAssign)
                        {
                            token=Z_OpSubAndAssign;
                            tokenpos+=2;
                            break;
                        }
                        else if(iter2==Z_OpSub)
                        {
                            token = Z_OpSelfSub;
                            tokenpos+=2;
                            break;
                        }
                    }
                    else if(iter==Z_OpMul)
                    {
                        char iter2= FullContent.it(tokenpos+1);
                        if(iter2==Z_OpAssign)
                        {
                            token=Z_OpMulAndAssing;
                            tokenpos+=2;
                            break;
                        }
                        else if(iter2==Z_OpDiv)
                        {
                            token=Z_CommentCEnd;
                            tokenpos+=2;
                            break;
                        }
                    }
                    else if(iter==Z_OpDiv)
                    {
                        char iter2= FullContent.it(tokenpos+1);
                        if(iter2==Z_OpAssign)
                        {
                            token=Z_OpDivAndAssign;
                            tokenpos+=2;
                            break;
                        }
                        else if(iter2==Z_OpDiv)
                        {
                            token=Z_CommentCpp;
                            tokenpos+=2;
                            break;
                        }
                        else if(iter2==Z_OpMul)
                        {
                            token = Z_CommentCStart;
                            tokenpos+=2;
                            break;
                        }
                    }
                    else if(iter==Z_OpBitAnd)
                    {
                        char iter2= FullContent.it(tokenpos+1);
                        if(iter2==Z_OpAssign)
                        {
                            token=Z_OpBitAndAndAssign;
                            tokenpos+=2;
                            break;
                        }
                    }
                    else if(iter==Z_OpBitXor)
                    {
                        char iter2= FullContent.it(tokenpos+1);
                        if(iter2==Z_OpAssign)
                        {
                            token=Z_OpBitXorAndAssign;
                            tokenpos+=2;
                            break;
                        }
                    }
                    else if(iter==Z_OpBitOr)
                    {
                        char iter2= FullContent.it(tokenpos+1);
                        if(iter2==Z_OpAssign)
                        {
                            token=Z_OpBitOrAndAssgin;
                            tokenpos+=2;
                            break;
                        }
                    }
                    else if(iter==Z_OpAssign)
                    {
                        char iter2= FullContent.it(tokenpos+1);
                        if(iter2==Z_OpAssign)
                        {
                            token=Z_OpEqual;
                            tokenpos+=2;
                            break;
                        }
                    }
                    else if(iter==Z_OpLessthan)
                    {
                        char iter2= FullContent.it(tokenpos+1);
                        if(iter2==Z_OpAssign)
                        {
                            token=Z_OpLessOrEqual;
                            tokenpos+=2;
                            break;
                        }
                        else if(iter2==Z_OpLessthan)
                        {
                            char iter3=FullContent.it(tokenpos+2);
                            if(iter3==Z_OpAssign)
                            {
                                token= Z_OpBitShiftLeftAndAssign;
                                tokenpos+=3;
                                break;
                            }
                            else
                            {
                                token=Z_OpBitShiftLeft;
                                tokenpos+=2;
                                break;
                            }
                        }
                    }
                    else if(iter==Z_OpBigthan)
                    {
                        char iter2= FullContent.it(tokenpos+1);
                        if(iter2==Z_OpAssign)
                        {
                            token=Z_OpBigOrEqual;
                            tokenpos+=2;
                            break;
                        }
                        else if(iter2==Z_OpBigthan)
                        {
                            char iter3=FullContent.it(tokenpos+2);
                            if(iter3==Z_OpAssign)
                            {
                                token= Z_OpBitShiftRightAndAssign;
                                tokenpos+=3;
                                break;
                            }
                            else
                            {
                                token = Z_OpBitShiftRight;
                                tokenpos+=2;
                                break;
                            }
                        }
                    }
                    else if(iter==Z_OpNot)
                    {
                        char iter2= FullContent.it(tokenpos+1);
                        if(iter2==Z_OpAssign)
                        {
                            token=Z_OpNotEqual;
                            tokenpos+=2;
                            break;
                        }
                    }
                    else if(iter==Z_OpBitAnd)
                    {
                        char iter2= FullContent.it(tokenpos+1);
                        if(iter2==Z_OpBitAnd)
                        {
                            token=Z_OpLogicalAnd;
                            tokenpos+=2;
                            break;
                        }
                    }
                    else if(iter==Z_OpBitOr)
                    {
                        char iter2= FullContent.it(tokenpos+1);
                        if(iter2==Z_OpBitOr)
                        {
                            token=Z_OpLogicalOr;
                            tokenpos+=2;
                            break;
                        }
                    }


                    token+=FullContent.it(tokenpos);
                    tokenpos++;
                }
                break;
            }
            token+=FullContent.it(tokenpos);
            tokenpos++;
        }
        else
        {
            if(token.IsEmpty())
            {
                token = iter;
            }
            tokenpos++;
            break;
        }
    }
    if(tokenpos>=FullContent.GetLength() && token.IsEmpty())
    {
        token =Z_Eof;
    }
    return token;
}
ZString ZeroLex::PeekNextToken()
{
    int temptokenpos=tokenpos;
    ZString token=GetNextToken();
    tokenpos=temptokenpos;
    return token;
}
ZString ZeroLex::PeekNextToken(int & nexttokenpos)
{
    int temptokenpos=tokenpos;
    ZString token=GetNextToken();
    nexttokenpos=tokenpos;
    tokenpos=temptokenpos;
    return token;
}
void ZeroLex::SetCurrentTokenPos(int pos)
{
    if(pos>=0 && pos<FullContent.GetLength())
        tokenpos = pos;
}
bool ZeroLex::Parse(const char * content)
{
    bool bret = false;
    tokenpos = 0;
    FullContent = content;

    ZString token = GetNextToken();
    bool gotonext_Z_DoubleQuote=false;;
    while(token!=Z_Eof)
    {
        //处理C++风格的注释
        if(token==Z_CommentCpp)
        {
            ZString CommentToken;
            while(token!=Z_EndOfLine && token!=Z_Eof)
            {
                CommentToken+=token;
                token=GetNextToken();
            }
            CommentToken+=token;
            token =CommentToken;
        }
        //处理C语言风格的注释
        else if(token==Z_CommentCStart && token!=Z_Eof)
        {
            ZString CommentToken;
            while(token!=Z_CommentCEnd)
            {
                CommentToken+=token;
                token=GetNextToken();
            }
            CommentToken+=token;
            token =CommentToken;
        }
        else if(token==Z_BlackSlash)
        {
            //  '\"' 这样的情况，不能认为是字符串的开始
            int pos=0;
            ZString token1=PeekNextToken(pos);
            if(token1==Z_DoubleQuote)
            {
                if(!token.IsEmpty() && !isspace(token.it(0)))
                    printf("%s\n",*token);
                token=token1;
                SetCurrentTokenPos(pos);
            }
            //如果后面紧跟换行，说明这是一个续行符,直接把回车换行去掉
            else if(token1==Z_CarriageReturn)
            {
                int pos2=0;
                SetCurrentTokenPos(pos);
                ZString token2=PeekNextToken(pos2);
                if(token2==Z_EndOfLine)
                {
                     if(!token.IsEmpty() && !isspace(token.it(0)))
                        printf("%s\n",*token);
                    SetCurrentTokenPos(pos2);
                }
                else
                {
                    token = token2;
                }
            }
            else if(token1==Z_EndOfLine)
            {
                 if(!token.IsEmpty() && !isspace(token.it(0)))
                        printf("%s\n",*token);
                     SetCurrentTokenPos(pos);
            }
        }
        else if(token==Z_DoubleQuote)
        {
            //字符串开始 ，除非是字符串结束，否则都合并为一个token
            if(gotonext_Z_DoubleQuote==false)
                gotonext_Z_DoubleQuote= true;
            else
                gotonext_Z_DoubleQuote = false;
        }

        {
            if(gotonext_Z_DoubleQuote)
            {
                ZString token1=PeekNextToken();
                while(token1!=Z_DoubleQuote )
                {
                    token1=GetNextToken();
                    token+=token1;
                    if(token1==Z_BlackSlash)
                    {
                        ZString token2=PeekNextToken();
                        if(token2==Z_DoubleQuote)
                        {
                            token1=GetNextToken();
                            token+=token1;
                            ZString token3=PeekNextToken();
                            if(IsTerminalCharacter(token3.it(0)) || token3==Z_EndOfLine)
                            {
                                break;
                            }
                            token1=GetNextToken();
                            continue;
                        }
                        else
                        {
                            token1=GetNextToken();
                            token+=token1;
                        }
                    }
                    token1=PeekNextToken();
                }
            }
        }


        if(!token.IsEmpty() && !isspace(token.it(0)))
            printf("%s\n",*token);
//        if(IsReservedWord(token.c_str()))
//        {
//            printf("%s is reserved\n");
//        }
        token=GetNextToken();
    }
    return bret;
}
bool ZeroLex::Parse(ZString & content)
{
    return Parse(*content);
}
ZAst ZeroLex::BuildAst(const char * content)
{
    ZAst ast;
    return ast;
}
ZAst ZeroLex::BuildAst(ZString & content)
{
    ZAst ast;
    return ast;
}

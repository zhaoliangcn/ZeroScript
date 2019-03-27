#ifndef ZTERMINALCHAR_H_INCLUDED
#define ZTERMINALCHAR_H_INCLUDED

const char Z_LeftBrace ='{';
const char Z_RightBrace = '}';
const char Z_Comma = ',';
const char Z_LeftParentheses ='(';
const char Z_RightParentheses =')';
const char Z_LeftBracket ='[';
const char Z_RgithBracket =']';
const char Z_PathTag = '\\';
const char Z_BlackSlash = '\\';
const char Z_Comment ='#';
const char Z_DoubleQuote = '\"';
const char Z_Colon =':';
const char Z_Semicolon=';';
const char Z_Slash ='/';

const char Z_OpAdd ='+';
const char Z_OpSub = '-';
const char Z_OpMinus = '-';
const char Z_OpMul = '*';
const char Z_OpDiv = '/';
const char Z_OpMod ='%';
const char Z_OpAssign = '=';
const char Z_OpLessthan = '<';
const char Z_OpBigthan ='>';
const char Z_OpNot ='!';
const char Z_OpBitAnd ='&';
const char Z_OpBitOr = '|';
const char Z_OpBitNot ='~';
const char Z_OpBitXor = '^';
const char Z_OpObjectRefrence='.';
const char Z_EndOfLine ='\n';
const char Z_CarriageReturn ='\r';

const char * Z_OpAddAndAssign = "+=";
const char * Z_OpSubAndAssign ="-=";
const char * Z_OpMulAndAssing ="*=";
const char * Z_OpDivAndAssign ="/=";
const char * Z_OpBitShiftLeftAndAssign = "<<=";
const char * Z_OpBitShiftRightAndAssign =">>=";
const char * Z_OpBitAndAndAssign = "&=";
const char * Z_OpBitXorAndAssign = "^=";
const char * Z_OpBitOrAndAssgin = "|=";
const char * Z_OpEqual ="==";
const char * Z_OpLessOrEqual = "<=";
const char * Z_OpBigOrEqual =">=";
const char * Z_OpNotEqual ="!=";
const char * Z_OpSelfAdd="++";
const char * Z_OpSelfSub = "--";
const char * Z_OpBitShiftLeft ="<<";
const char * Z_OpBitShiftRight =">>";
const char * Z_OpLogicalAnd ="&&";
const char * Z_OpLogicalOr ="||";
const char * Z_CommentCpp ="//";
const char * Z_CommentCStart ="/*";
const char * Z_CommentCEnd = "*/";


const char * Z_Eof ="$ZEROEOF$";


static bool IsTerminalCharacter(const char Character)
{
    bool bret = false;
    if(Character==Z_OpAdd||
       Character==Z_OpSub ||
       Character==Z_OpMul ||
       Character==Z_OpDiv ||
       Character==Z_OpMod ||
       Character==Z_OpAssign ||
       Character==Z_OpLessthan ||
       Character==Z_OpBigthan ||
       Character==Z_OpNot ||
       Character==Z_OpBitAnd ||
       Character==Z_OpBitOr ||
       Character==Z_OpBitNot ||
       Character==Z_OpBitXor ||
       Character==Z_OpObjectRefrence ||
       Character==Z_LeftBrace ||
       Character==Z_RightBrace ||
       Character==Z_Comma ||
       Character==Z_LeftParentheses ||
       Character==Z_RightParentheses||
       Character==Z_LeftBracket||
       Character==Z_RgithBracket ||
       Character==Z_BlackSlash||
       Character==Z_Comment ||
       Character==Z_DoubleQuote ||
       Character==Z_Colon||
       Character==Z_Semicolon ||
       Character==Z_Slash   )
    {
        bret =true;
    }
    return bret;
}


#endif // ZTERMINALCHAR_H_INCLUDED

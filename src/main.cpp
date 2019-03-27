// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#include <iostream>

using namespace std;
#include "zstring.h"
#include "zerolex.h"
#include "ZFileLoader.h"
void ZStringTest()
{
    ZString z1 ;
    z1 = "HELLO ZERO";
    ZString z2 ;
    z2 = z1;
    ZString z3;
    z3=z1.Sub(0,2);
    int pos = z1.Find("LE");
    char it=z1.it(0);

    ZString z4 = z1.Sub(9,1);
    cout<<(z2 ==z1)<<endl;
    cout<<z1.c_str()<<endl;
    cout<<z2.c_str()<<endl;
    cout<<z3.c_str()<<endl;
    cout<<z4.c_str()<<endl;
    cout<<pos<<endl;
    cout<<z1.Match(".*RO$")<<endl;
    cout<<it<<endl;
    z1.ToLower();
    cout<<z1.c_str()<<endl;
    cout<<(z1.approximate(z2))<<endl;
    z1.Replace('B',0);
    cout<<z1.c_str()<<endl;
    z1.Replace(0,5,z2);
    cout<<z1.c_str()<<endl;
    ZString z5;
    z5="A";
    z1.Replaceall("O",z5);
    cout<<z1.c_str()<<endl;
    int pos2=z1.RFind("ZERA");
    cout<<pos2<<endl;
    z1.Reverse();
    cout<<z1.c_str()<<endl;

    ZString z6("Zero");
    cout<<z6.c_str()<<endl;
    ZString z7(z6);
    cout<<z7.c_str()<<endl;
    ZString z8=z6;
    cout<<z8.c_str()<<endl;

    ZString z9="one";
    cout<<z9.c_str()<<endl;
    cout<<*z9<<endl;
    z9+=z1;
    cout<<z9.c_str()<<endl;


    z8=z3+z1;
    cout<<z8.c_str()<<endl;
    cout << "Hello world!" << endl;
}
int main(int argc,char ** argv)
{
    ZStringTest();

    ZeroLex lex;
    //lex.Parse("define(int,number1,100)\r\n define(int,number2,97) \r\n number1+=1\r\n number2=number1*number2\r\n define(string,str1,\"hello\")");
    //lex.Parse("number<<=1");
    // lex.Parse("{number1!=number2;number1+=number2,number1+=1;}");
    //lex.Parse("define(function,Add,x,y){return x+y;}");
    //lex.Parse("int Add(int x,int y){return x+y;}");
    //lex.Parse("define(function,loop,x){while(x>0){print(x) \r\n x--\r\n}}");
    //lex.Parse("int Test(x){if(x>0)print(\"%s\",x) return x;}");

    if(argc==2)
    {
        ZFileLoader zl;
        ZString zs = zl.LoadFile(argv[1]);
        lex.Parse(zs);
    }

    return 0;
}

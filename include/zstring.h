#ifndef ZSTRING_H
#define ZSTRING_H
#include "zstringbase.h"

class ZString :public ZStringBase
{
    public:
        /** Default constructor */
        ZString();
        /** Default destructor */
        virtual ~ZString();
        /** Copy constructor
        *  \param other Object to copy from
        */
        ZString(const ZString& other);
        /** Assignment operator
        *  \param other Object to assign from
        *  \return A reference to this
        */
        ZString(const char * initial);
        ZString(const char initial);
        ZString& operator=(const ZString& other);
        ZString& operator=(const char * source);
        ZString& operator=(const char source);
        ZString& operator=(const wchar_t * source);
        const char * operator*();
        ZString operator+(const ZString& other);
        ZString& operator+=(const ZString& other);
        ZString& operator+=(const char * other);
        ZString& operator+=(const char  other);
        /*
        截取子串
        */
        ZString Sub(int start,int len);
        /*
        查找子串
        */
        int Find(const ZString& sub);
        int Find(const char * sub);
        /*
        从右侧查找子串
        */
        int RFind(const char * sub);
        int RFind(const ZString& sub);
        /*
        本字符串是否于正则表达式匹配
        */
        #if __cplusplus >= 201103L
        bool Match(const ZString& sub);
        bool Match(const char * sub);
        #endif

        int GetLength();

        bool operator ==(const ZString & other);
        bool operator ==(const char other);
        bool operator !=(const char * other);
        bool operator !=(const ZString & other);
        bool operator !=(const char other);
        /*
        近似于 (大小写不敏感的比较)
        */
        bool approximate(const ZString & other);
        /*
        提取单个字符
        */
        const char it(int pos);
        /*
        返回指向缓冲区的指针
        */
        const char * c_str();
        void ToUpper();
        void ToLower();
        bool Replace(int pos,char c);
        bool Replace(int start,int count ,const char * other);
        bool Replace(int start,int count ,ZString & other);
        bool Replaceall(const char * substring,const char *  other);
        bool Replaceall(const char * substring,ZString & other);
        void Reverse();
        bool IsEmpty();
        void ToUtf8(char * utf8,size_t buffersize);
        int ToUtf8(wchar_t wchar, char *utf8);
        void ToUnicode(wchar_t * buffer,size_t& buffersize);

    protected:

    private:
        char * Buffer;
        int length;
        int spacesize;
};

#endif // ZSTRING_H

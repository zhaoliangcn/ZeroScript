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
        ��ȡ�Ӵ�
        */
        ZString Sub(int start,int len);
        /*
        �����Ӵ�
        */
        int Find(const ZString& sub);
        int Find(const char * sub);
        /*
        ���Ҳ�����Ӵ�
        */
        int RFind(const char * sub);
        int RFind(const ZString& sub);
        /*
        ���ַ����Ƿ���������ʽƥ��
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
        ������ (��Сд�����еıȽ�)
        */
        bool approximate(const ZString & other);
        /*
        ��ȡ�����ַ�
        */
        const char it(int pos);
        /*
        ����ָ�򻺳�����ָ��
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

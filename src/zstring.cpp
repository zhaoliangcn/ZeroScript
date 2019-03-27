// *** ADDED BY HEADER FIXUP ***
#include <string>
// *** END ***
#include "zstring.h"
#if __cplusplus >= 201103L
#include <regex>
#endif
#include <string.h>
using namespace std;
ZString::ZString()
{
    //ctor
    Buffer = NULL;
    length = 0;
    spacesize = 0;
}

ZString::~ZString()
{
    //dtor
    if(Buffer)
    {
        free(Buffer);
    }
}
ZString::ZString(const ZString& other)
{
    Buffer = NULL;
    length = 0;
    spacesize = 0;
    *this = other;
}
ZString::ZString(const char * initial)
{
    Buffer = NULL;
    length = 0;
    spacesize = 0;
    *this=initial;
}
ZString::ZString(const char initial)
{
    Buffer = NULL;
    length = 0;
    spacesize = 0;
    *this=initial;
}
bool ZString::operator !=(const char * other)
{
    ZString ztemp=other;
    return !(*this==ztemp);
}
bool ZString::operator !=(const ZString & other)
{
    return !(*this==other);
}
 bool ZString::operator !=(const char other)
 {
     ZString ztemp;
     ztemp = other;
    return !(*this==ztemp);
 }
bool ZString::operator ==(const ZString & other)
{
    if(length==other.length)
    {
        if(length>0)
        {
            if(strcmp(this->Buffer,other.Buffer)==0)
            {
                return true;
            }
        }
        else if(length==0)
        {
            return true;
        }
    }
    return false;
}
bool ZString::operator ==(const char other)
{
    ZString zs1;
    zs1=other;
    return (*this==zs1);
}
ZString& ZString::operator=(const wchar_t * source)
{
    return *this;
}
ZString& ZString::operator=(const char * source)
{
    if(source!=NULL )
    {
        if(this->Buffer!=NULL)
        {
            free(this->Buffer);
        }
        this->length = strlen(source);
        this->spacesize = this->length+2;
        this->Buffer = (char *)malloc(this->spacesize);
        if(Buffer)
        {
            memset(this->Buffer,0,this->spacesize);
            strcpy(this->Buffer,source);
        }
    }
    return *this;
}
ZString& ZString::operator=(const char  source)
{
    this->length = 1;
    if(this->Buffer==NULL)
    {
        this->spacesize = this->length+2;
        this->Buffer = (char *)malloc(this->spacesize);
    }
    if(this->Buffer)
    {
        memset(this->Buffer,0,this->spacesize);
        this->Buffer[0]=source;
    }
    return *this;
}
ZString& ZString::operator=(const ZString& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    if(this->spacesize<rhs.length)
    {
        free(this->Buffer);
        this->length = rhs.length;
        this->spacesize= this->length+2;
        this->Buffer = (char *)malloc(this->spacesize);
    }
    if(this->Buffer)
    {
        memset(this->Buffer,0,this->spacesize);
        if(rhs.Buffer)
            strcpy(this->Buffer,rhs.Buffer);
        this->length = rhs.length;
    }
    return *this;
}

const char * ZString::operator*()
{
    return Buffer;
}
ZString ZString::operator+(const ZString& other)
{
    ZString ztemp=*this;
    ztemp+=other;
    return ztemp;
}
ZString& ZString::operator+=(const ZString& other)
{

    int length2=length +other.length;
    if((spacesize-1)<length2)
    {
        spacesize = length2*2;
        char *temp = (char *)malloc(spacesize);
        if(temp)
        {
            memset(temp,0,spacesize);
            if(Buffer)
            {
                strcpy(temp,Buffer);
                free(Buffer);
            }
            strcat(temp,other.Buffer);
            length=length2;
            Buffer=temp;
        }
    }
    else
    {
        strcat(Buffer,other.Buffer);
        length=length2;
    }
    return *this;
}
ZString& ZString::operator+=(const char * other)
{
    char *temp ;
    int length3=strlen(other);
    int length2=length +length3;
    if((spacesize-1)<length2)
    {
        spacesize = length2*2;
        temp= (char *)malloc(spacesize);
        if(temp)
        {
            memset(temp,0,spacesize);
            if(Buffer)
            {
                strcpy(temp,Buffer);
                free(Buffer);
            }
            strcat(temp,other);
            length=length2;
            Buffer=temp;
        }
    }
    else
    {
        strcat(Buffer,other);
        length=length2;
    }
    return *this;
}
ZString& ZString::operator+=(const char other)
{
    char ztemp[2]={0};
    ztemp[0]= other;
    (*this)+=ztemp;
    return *this;
}
ZString ZString::Sub(int start,int len)
{
    ZString temp;

    if(this->Buffer)
    {
        if(start>=0 && start <this->length)
        {
            if(len>=0 && (start+len)<=length)
            {
                temp.length=len;
                temp.spacesize = len+2;
                temp.Buffer = (char *)malloc(temp.spacesize);
                memset(temp.Buffer,0,temp.spacesize);
                strncpy(temp.Buffer,this->Buffer+start,len);
            }
        }
    }
    return temp;
}
int ZString::Find(const ZString& sub)
{
    if(this->Buffer)
    {
        char * psub=  strstr(this->Buffer,sub.Buffer);
        if(psub)
        {
            return int(psub-this->Buffer);
        }
    }
    return -1;
}
int ZString::Find(const char * sub)
{
    if(this->Buffer)
    {
        char * psub=  strstr(this->Buffer,sub);
        if(psub)
        {
            return int(psub-this->Buffer);
        }
    }
    return -1;
}
int ZString::RFind(const char * sub)
{
    int pos=-1;
    int length2=strlen(sub);
    if(length2>0 && length2<=length)
    {
        char *pBuffer=Buffer+length;
        while(pBuffer>Buffer)
        {
            char * psub=  strstr(pBuffer,sub);
            if(psub)
            {
                pos =  int(psub-Buffer);
            }
            pBuffer-=1;
        }
    }
    return pos;

}

int ZString::RFind(const ZString& sub)
{
    return RFind(sub.Buffer);
}
#if __cplusplus >= 201103L
bool ZString::Match(const ZString& sub)
{
    bool bret=false;
    regex rex(sub.Buffer);
    bret = regex_match(this->Buffer,rex);
    return bret;
}
bool ZString::Match(const char * sub)
{
    bool bret=false;
    regex rex(sub);
    bret = regex_match(this->Buffer,rex);
    return bret;
}
#endif
int ZString::GetLength()
{
    return length;
}
const char ZString::it(int pos)
{
    if(pos>=0 && pos<length)
        return this->Buffer[pos];
    return '\0';
}
const char * ZString::c_str()
{
    return Buffer;
}
void ZString::ToUpper()
{
    if(Buffer)
    {
        char * pBuffer =Buffer;
        for (; *pBuffer!='\0'; pBuffer++)
            *pBuffer = toupper(*pBuffer);
    }
}
void ZString::ToLower()
{
    if(Buffer)
    {
        char * pBuffer =Buffer;
        for (; *pBuffer!='\0'; pBuffer++)
            *pBuffer = tolower(*pBuffer);
    }
}
bool ZString::approximate(const ZString & other)
{
    bool bret = false;
    ZString z1,z2;
    z1=*this;
    z2=other;
    z1.ToLower();
    z2.ToLower();
    return z1==z2;

}
bool ZString::Replace(int pos,char c)
{
    bool bret = false;
    if(pos>=0 && pos<length)
    {
        Buffer[pos]=c;
        bret =true;
    }
    return bret;
}
bool ZString::Replace(int start,int count,const char * other)
{
    bool bret = false;
    int length2 =strlen(other);
    if(start>=0 && start<length &&length2>0)
    {
        if((start+count)<=length)
        {
            int length1 = (length-count)+length2;
            char * temp =(char*)malloc(length1+2);
            if(temp)
            {
                memset(temp,0,length1+2);
                strncpy(temp,&Buffer[0],start);
                strcat(temp,other);
                strncat(temp,&Buffer[start+count],length-(start+count));
                length = length1;
                spacesize = length+2;
                free(Buffer);
                Buffer = temp;
                bret =true;
            }

        }
    }
    return bret;
}
bool ZString::Replace(int start,int count,ZString & other)
{
    bool bret = false;
    if(start>=0 && start<length)
    {
        if((start+count)<=length)
        {
            int length1 = (length-count)+other.length;
            char * temp =(char*)malloc(length1+2);
            if(temp)
            {
                memset(temp,0,length1+2);
                strncpy(temp,&Buffer[0],start);
                strcat(temp,other.Buffer);
                strncat(temp,&Buffer[start+count],length-(start+count));
                length = length1;
                spacesize = length+2;
                free(Buffer);
                Buffer = temp;
                bret =true;
            }

        }
    }
    return bret;
}
bool ZString::Replaceall(const char * substring,const char *  other)
{
    bool bret = false;
    int pos = Find(substring);
    while(pos>=0)
    {
        Replace(pos,strlen(substring),other);
        pos = Find(substring);
        bret =true;
    }
    return bret;
}
bool ZString::Replaceall(const char * substring,ZString & other)
{
    bool bret = false;
    int pos = Find(substring);
    while(pos>=0)
    {
        Replace(pos,strlen(substring),other);
        pos = Find(substring);
        bret =true;
    }
    return bret;
}
void ZString::Reverse()
{
    char *str = Buffer;
    char *left = Buffer;
    char ch;
    while (*str++)                 /* find end of string */
        ;
    str -= 2;
    while (left < str)
    {
        ch = *left;
        *left++ = *str;
        *str-- = ch;
    }
}
bool ZString::IsEmpty()
{
    return (length<=0 || Buffer==NULL);
}
int ZString::ToUtf8(wchar_t wchar, char *utf8)
{
    if (utf8 == NULL) {
			return -1;
		}
		int len = 0;
		int size_d = 8;

		if (wchar < 0x80)
		{  //
			//length = 1;
			utf8[len++] = (char)wchar;
		}
		else if(wchar < 0x800)
		{
			//length = 2;

			if (len + 1 >= size_d)
				return -1;

			utf8[len++] = 0xc0 | ( wchar >> 6 );
			utf8[len++] = 0x80 | ( wchar & 0x3f );
		}
		else if(wchar < 0x10000 )
		{
			//length = 3;
			if (len + 2 >= size_d)
				return -1;

			utf8[len++] = 0xe0 | ( wchar >> 12 );
			utf8[len++] = 0x80 | ( (wchar >> 6) & 0x3f );
			utf8[len++] = 0x80 | ( wchar & 0x3f );
		}
		else if( wchar < 0x200000 )
		{
			//length = 4;
			if (len + 3 >= size_d)
				return -1;

			utf8[len++] = 0xf0 | ( (int)wchar >> 18 );
			utf8[len++] = 0x80 | ( (wchar >> 12) & 0x3f );
			utf8[len++] = 0x80 | ( (wchar >> 6) & 0x3f );
			utf8[len++] = 0x80 | ( wchar & 0x3f );
		}
		return len;
}
void ZString::ToUtf8(char * utf8,size_t buffersize)
{
    ZString temp;
    int len = this->GetLength();
    char buffer[8]={0};
    for(int i=0;i<len;i++)
    {
        memset(buffer,0,sizeof(buffer));
        ToUtf8(this->Sub(i,1).it(0),buffer);
        temp+=(char*)buffer;
    }
    strcpy(utf8,this->c_str());

}
void ZString::ToUnicode(wchar_t * buffer,size_t& buffersize)
{
    wchar_t *	Buffer	=	NULL;

#ifdef _WIN32
		DWORD	nChBuf = MultiByteToWideChar(CP_ACP,0,this->c_str(),-1,NULL,0);
		Buffer = (wchar_t *)malloc(nChBuf * sizeof(wchar_t));
		nChBuf = MultiByteToWideChar(CP_ACP,0,this->c_str(),-1,Buffer,nChBuf);
#else
		setlocale(LC_ALL,"chs");
		int len = mbstowcs(NULL,this->c_str(),0)+1;
		len=len*sizeof(wchar_t);
		Buffer = (wchar_t *)malloc(len);
		memset(Buffer,0,len);
		mbstowcs(Buffer,this->c_str(),len);
#endif
		wcscpy(buffer,Buffer);
		free(Buffer);
}

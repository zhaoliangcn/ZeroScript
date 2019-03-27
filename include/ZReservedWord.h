#ifndef ZRESERVEDWORD_H_INCLUDED
#define ZRESERVEDWORD_H_INCLUDED

#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))

enum ReservedToken
{
    vl_invalid = 0 ,

    vl_clear = 1 ,

    vl_reserved = 2 ,

    vl_shutdown = 3 ,

    vl_reboot = 4 ,

    vl_popup = 5 ,

    vl_print = 6 ,

    vl_show = 7 ,

    vl_open = 8 ,

    vl_run = 9 ,

    vl_capture = 10 ,

    vl_delete = 11 ,

    vl_read = 12 ,

    vl_write = 13 ,

    vl_copy = 14 ,

    vl_seek = 15 ,

    vl_do = 16 ,

    vl_compare = 17 ,

    vl_compute = 18 ,

    vl_connect = 19 ,

    vl_acquire = 20 ,

    vl_release = 21 ,

    vl_define = 22 ,

    vl_test = 23 ,

    vl_start = 24 ,

    vl_end = 25 ,

    vl_call = 26 ,

    vl_find = 27 ,

    vl_replace = 28 ,

    vl_getsubstring = 29 ,

    vl_insert = 30 ,

    vl_match = 31 ,

    vl_import = 32,

    vl_while = 33,

    vl_move = 34,

    vl_getsize = 35,

    vl_getlength =36 ,

    vl_register = 37,

    vl_send = 38,

    vl_receive = 39,

    vl_watch = 40,

    vl_set = 41 ,

    vl_sleep = 42,

    vl_wait = 43,

    vl_enum = 44,

    vl_otherwise = 45,

    vl_refresh = 46,

    vl_generate = 47 ,

    vl_suspend=48,

    vl_getelement=49,

    vl_traverse = 50 ,

    vl_sort = 51 ,

    vl_format = 52 ,

    vl_clone = 53 ,

    vl_get = 54,

    vl_inherit = 55,

    vl_encrypt = 56 ,

    vl_decrypt = 57 ,

    vl_hash = 58 ,

    vl_transform = 59,

    vl_split = 60,

    vl_post = 61,

    vl_load = 62,

    vl_exit = 63,

    vl_draw = 64,

    vl_push = 65,

    vl_continue = 66,

    vl_break = 67 ,

    vl_switch = 68 ,

    vl_case = 69 ,

    vl_lock = 70 ,

    vl_unlock = 71 ,

    vl_compress = 72 ,

    vl_uncompress = 73 ,

    vl_create = 74 ,

    vl_loop = 75 ,

    vl_public = 76 ,

    vl_private = 77 ,

    vl_save = 78 ,

    vl_return = 79,

    vl_encode = 80,

    vl_decode = 81,
};

const static char * Z_INVALID = "invalid";

const static char * Z_CLEAR = "clear";

const static char * Z_RESERVED = "reserved";

const static char * Z_SHUTDOWN = "shutdown";

const static char * Z_REBOOT = "reboot";

const static char * Z_POPUP = "popup";

const static char * Z_PRINT = "print";

const static char * Z_SHOW = "show";

const static char * Z_OPEN = "open";

const static char * Z_RUN = "run";

const static char * Z_CAPTURE = "capture";

const static char * Z_DELETE = "delete";

const static char * Z_READ= "read";

const static char * Z_WRITE = "write";

const static char * Z_COPY = "copy";

const static char * Z_SEEK = "seek";

const static char * Z_DO = "do";

const static char * Z_COMPARE = "compare";

const static char * Z_COMPUTE = "compute";

const static char * Z_CONNECT = "connect";

const static char * Z_ACQUIRE = "acquire";

const static char * Z_RELEASE = "release";

const static char * Z_DEFINE = "define";

const static char * Z_TEST = "test";

const static char * Z_start = "start";

const static char * Z_end = "end";

const static char * Z_CALL = "cal";

const static char * Z_FIND = "find";

const static char * Z_REPLACE = "replace";

const static char * Z_GETSUBSTRING = "getsubstring";

const static char * Z_INSERT = "insert";

const static char * Z_MATCH = "match";

const static char * Z_IMPORT ="import";

const static char * Z_WHILE = "while";

const static char * Z_MOVE = "move";

const static char * Z_GETSIZE = "getsize";

const static char * Z_GETLENGTH = "getlength";

const static char * Z_REGISTER ="register";

const static char * Z_SEND ="send";

const static char * Z_RECEIVE ="receive";

const static char * Z_WATCH ="watch";

const static char * Z_SET ="set";

const static char * Z_SLEEP ="sleep";

const static char * Z_WAIT ="wait";

const static char * Z_ENUM = "enum";

const static char * Z_OTHERWISE = "otherwise";

const static char * Z_REFRESH = "refresh";

const static char * Z_GENERATE ="generate";

const static char * Z_SUSPEND = "suspend";

const static char * Z_GETELEMENT = "getelement";

const static char * Z_TRAVERSE = "traverse";

const static char * Z_SORT = "sort";

const static char * Z_FORMAT = "format";

const static char * Z_CLONE = "clone";

const static char * Z_GET = "get";

const static char * Z_INHERIT = "inherit";

const static char * Z_ENCRYPT = "encrypt";

const static char * Z_DECRYPT = "decrypt";

const static char * Z_HASH = "hash";

const static char * Z_TRANSFORM = "transform";

const static char * Z_SPLIT = "split";

const static char * Z_POST = "post";

const static char * Z_LOAD = "load";

const static char * Z_EXIT = "exit";

const static char * Z_DRAW = "draw";

const static char * Z_PUSH = "push";

const static char * Z_CONTINUE = "continue";

const static char * Z_BREAK = "break";

const static char * Z_SWITCH = "switch";

const static char * Z_CASE = "case";

const static char * Z_LOCK = "lock";

const static char * Z_UNLOCK = "unlock";

const static char * Z_COMPRESS = "compress";

const static char * Z_UNCOMPRESS = "uncompress";

const static char * Z_CREATE = "create";

const static char * Z_LOOP = "loop";

const static char * Z_PUBLIC = "public";

const static char * Z_PRIVATE = "private";

const static char * Z_SAVE = "save";

const static char * Z_RETURN = "return";

const static char * Z_ENCODE ="encode";

const static char * Z_DECODE = "decode";


struct ZReservedWord
{
    const char * word;
    enum ReservedToken token;
};
static struct ZReservedWord ZReservedWords[] =
{
    { Z_INVALID, vl_invalid },
    { Z_CLEAR, vl_clear },
    { Z_RESERVED, vl_reserved},
    { Z_SHUTDOWN  ,vl_shutdown },
    { Z_REBOOT  ,vl_reboot},
    { Z_POPUP  ,vl_popup},
    { Z_PRINT  ,vl_print},
    { Z_SHOW  ,vl_show},
    { Z_OPEN  ,vl_open},
    { Z_RUN  ,vl_run},
    { Z_CAPTURE  ,vl_capture},
    { Z_DELETE  ,vl_delete},
    { Z_READ ,vl_read},
    {Z_WRITE  ,vl_write},
    {Z_COPY  ,vl_copy},
    {Z_SEEK  ,vl_seek},
    {Z_DO  ,vl_do},
    {Z_COMPARE  ,vl_compare},
    {Z_COMPUTE  ,vl_compute},
    {Z_CONNECT  ,vl_connect},
    {Z_ACQUIRE  ,vl_acquire},
    {Z_RELEASE  ,vl_release},
    {Z_DEFINE  ,vl_define},
    {Z_TEST  ,vl_test},
    {Z_start  ,vl_start},
    {Z_end  ,vl_end},
    {Z_CALL  ,vl_call},
    {Z_FIND  ,vl_find},
    {Z_REPLACE  ,vl_replace},
    {Z_GETSUBSTRING  ,vl_getsubstring},
    {Z_INSERT  ,vl_insert},
    {Z_MATCH  ,vl_match},
    {Z_IMPORT  ,vl_import},
    {Z_WHILE  ,vl_while},
    {Z_MOVE  ,vl_move},
    {Z_GETSIZE  ,vl_getsize},
    {Z_GETLENGTH  ,vl_getlength},
    {Z_REGISTER  ,vl_register},
    {Z_SEND  ,vl_send},
    {Z_RECEIVE  ,vl_receive},
    {Z_WATCH  ,vl_watch},
    {Z_SET  ,vl_set},
    {Z_SLEEP  ,vl_sleep},
    {Z_WAIT  ,vl_wait},
    {Z_ENUM  ,vl_enum},
    {Z_OTHERWISE  ,vl_otherwise},
    {Z_REFRESH  ,vl_refresh},
    {Z_GENERATE  ,vl_generate},
    {Z_SUSPEND  ,vl_suspend},
    {Z_GETELEMENT  ,vl_getelement},
    {Z_TRAVERSE  ,vl_traverse},
    {Z_SORT  ,vl_sort},
    {Z_FORMAT  ,vl_format},
    {Z_CLONE  ,vl_clone},
    {Z_GET  ,vl_get},
    {Z_INHERIT  ,vl_inherit},
    {Z_ENCRYPT  ,vl_encrypt},
    {Z_DECRYPT  ,vl_decrypt},
    {Z_HASH  ,vl_hash},
    {Z_TRANSFORM  ,vl_transform},
    {Z_SPLIT  ,vl_split},
    {Z_POST  ,vl_post},
    {Z_LOAD  ,vl_load},
    {Z_EXIT  ,vl_exit},
    {Z_DRAW  ,vl_draw},
    {Z_PUSH  ,vl_push},
    {Z_CONTINUE  ,vl_continue},
    {Z_BREAK  ,vl_break},
    {Z_SWITCH  ,vl_switch},
    {Z_CASE  ,vl_case},
    {Z_LOCK  ,vl_lock},
    {Z_UNLOCK  ,vl_unlock},
    {Z_COMPRESS  ,vl_compress},
    {Z_UNCOMPRESS  ,vl_uncompress},
    {Z_CREATE  ,vl_create},
    {Z_LOOP  ,vl_loop},
    {Z_PUBLIC  ,vl_public},
    {Z_PRIVATE  ,vl_private},
    {Z_SAVE  ,vl_save},
    {Z_RETURN  ,vl_return},
    {Z_ENCODE  ,vl_encode},
    {Z_DECODE  ,vl_decode},
};
static bool IsReservedWord(const char * word)
{
    bool bret = false;
    for(int i=0;i<_countof(ZReservedWords);i++)
    {
        if(strcmp(word,ZReservedWords[i].word)==0)
        {
            bret = true;
            break;
        }
    }
    return bret;
}

#endif // ZRESERVEDWORD_H_INCLUDED

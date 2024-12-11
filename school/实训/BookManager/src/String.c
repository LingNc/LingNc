#include"../include/String.h"

char *_string_c_str(string pthis){
    return pthis->str;
}
string _string_add(string pthis,string other){
    strcat(pthis->c_str,other->c_str);
    return other;
}
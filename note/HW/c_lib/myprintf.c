#include <stdio.h>
#include <stdarg.h>
#include "myprintf.h"

void myprintf(char *fmt, ...){
    va_list valist;
    va_start(valist, fmt);
    for(int i = 0; (fmt[i] & 0xff) != 0; i+=2){
        switch(fmt[i+1]){
            case 'd':
                printf("%d", va_arg(valist, int));
                break;
            case 'c':
                printf("%c", va_arg(valist, int));
                break;
            case 's':
                printf("%s", va_arg(valist, char*));
                break;
        }
    }
}

void myassert(){

}

void mymemcpy(void *str1, void *str2, size_t len){
    char *s1 = (char *)str1;
    char *s2 = (char *)str2;
    for(int i = 0; i < len; i++){
        s1[i] = s2[i];
    }
}
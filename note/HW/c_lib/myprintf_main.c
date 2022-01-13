#include "myprintf.h"

int main(){ // %c,%s,%d
    int num = 10;
    char c = 'A';
    char *s = "ABC";
    int n = sizeof(s)/sizeof(char);
    char s2[n];
    mymemcpy(s2, s, n);
    myprintf("%s", s2);
}
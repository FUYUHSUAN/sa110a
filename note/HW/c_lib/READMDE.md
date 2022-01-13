## 實作printf
>* 看錯題目以為是printf，少看了s
>* 本作品為自己寫的作品
>* 其中程式部分參考了鍾誠老師的risc2vos裡面的[printf.c](https://github.com/riscv2os/riscv2os/blob/master/xv6/kernel/printf.c)結合上課交的方式來寫
>* 使用了 `#include <stdio.h>`和`#include <stdarg.h>`來協助撰寫

---

* 主要是模擬printf的標準函式庫

* 測試程式`myprintf.c`
```c
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
```

* `myprintf.h`
```c
void myprint();
void myassert();
void mymemcpy();
```

* 主要的程式區域`myprintf_main.c`
```c
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
```

* 先編譯`gcc myprintf.c myprintf_main.c -o myprintf_main`
* 接下來執行`./myprintf_main.exe`

* 執行結果
```c
s1108@DESKTOP-IJI9NA5 MINGW64 /d/Vscode/sa110/sa110a/note/HW/c_lib (master)
$ ./myprintf_main.exe 
ABC
```

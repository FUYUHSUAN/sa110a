# TeamHomwork
* teammember: 
    1. 傅于軒 (擁有者) (initial.ts)
    2. 林妍汝 (要求合併者)
    3. 魏美亞 (要求合併者) (takeright.ts)

* 目前已經嘗試將其發佈到deno中[發布位置](https://deno.land/x/nubletz_fu_lin_lodash)

## 過程
* 一開始我創建initial.ts接著美亞先git clone我的專案，然後將她的專案給一個pull request
* 
## example
```
import * as _ from 'https://deno.land/x/nubletz_fu_lin_lodash/mod.ts'
//import * as _ from "../mod.ts";
console.log("_.initial([1, 2, 3])",_.initial([1, 2, 3]))
```

## result
```
PS D:\Vscode\sa110\deno\nubletz_fu_lin_lodash\example> deno run ex1.ts
Check file:///D:/Vscode/sa110/deno/nubletz_fu_lin_lodash/example/ex1.ts
_.initial([1, 2, 3]) [ 1, 2 ]
```
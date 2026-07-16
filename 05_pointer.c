#include <stdio.h>
int main (){
    int var_n = 10;
    int *p; // 声明 p 是指针（专门存地址的变量），* 是跟着变量走的，不是跟着类型走的！
    p = &var_n; // & 取出 var_n 的地址，塞给 p
    // & 在这里是 取地址运算符（address-of operator），作用是获取变量在内存中的地址。
    int  *ptr = NULL; // ptr 声明为指针，初始化为 NULL（啥也不指）

    printf("value of p: %p\n", p); // 输出指针的值（即 var_n 的地址）
    printf("value of var_n: %p\n", &var_n); // 输出变量的值
    printf("value of *p: %d\n", *p); // *p = "去 p 存的地址，把里面的东西拿出来" → 得到 10
    printf("ptr 的地址是 %p\n", ptr );
    
    // 变量值  var_n / *p    →  %d，%d 配变量值
    // 地址    &var_n / p    →  %p，%p 配地址
    //int *p,q;  这里 p 是指针，q 是普通整型变量
    //int* p1, p2; 这里 p1 是指针，p2 是普通整型变量
    // 两者效果完全一样——都声明了一个指针和一个普通 int：
    return 0;
}

/*
指针声明
int    *ip;     一个整型的指针 
double *dp;     一个 double 型的指针 
float  *fp;     一个浮点型的指针 
*/
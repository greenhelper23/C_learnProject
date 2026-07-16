#include <stdio.h>

// 阶乘
/*
 double     func       (unsigned int n)
   ↑         ↑              ↑
 返回类型   函数名        参数列表
*/
double func (unsigned int n) {  
    if (n == 0) {
        return 1;  // 阶乘的定义：0! = 1
    } else {
        return n * func(n - 1);  // 递归调用计算阶乘
    }
}
/*
房子 = func(n) { ... }
家具 = if、for、printf 等语句
家具只能放在房子里，不能扔在门口马路上。
*/

int main(){
    int n = 18;  // 定义一个整数 n，表示要计算的阶乘数
    printf("value of n!: %f", func(n));
    return 0;
}

/*
类型	            字节	范围
int	                4	-2,147,483,648 ~ 2,147,483,647（约 ±21 亿）
unsigned int	    4	0 ~ 4,294,967,295（约 42 亿）
short	            2	-32,768 ~ 32,767
long long	        8	±9.2×10??
unsigned long long	8	0 ~ 1.8×10??
*/
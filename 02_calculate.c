#include <stdio.h>   // 头文件包含
const double PI = 3.14159;    // 宏定义

// 函数定义--各种运算（放在 main 前面，编译器才能先看到）
int multi(int a, int b) {  // 函数定义：乘法
    return a * b;      // 返回两个整数的乘积
}

int quyu(int a, int b) {  // 函数定义：取余
    return a % b;      // 返回两个整数的余数
}

typedef int (*quyuFunc)(int, int); 
// 定义函数指针类型 calcFunc，指向返回类型为 int，参数为两个 int 的函数

int zijian(int a) {  // 函数定义：自减
    return --a;      // 返回自减后的值
}

double area(double r) {  // 函数定义：圆面积
    return PI * r * r;      // 返回圆的面积
}

int main() {         // 主函数
    // 变量声明
    int num1, num2, output1, output2, output3;
    double output4;
    // 用户输入
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    /*
    （1）scanf：标准输入函数，从键盘读取数据
    （2）"%d %d"：格式控制字符串，%d：读取int 整数
    中间空格：代表输入时两个数字之间可以用空格、回车、Tab分隔
    （3）&num1、&num2  
    &取地址符，必须加！
    作用：把读到的数字存入变量对应的内存，不加 & 会程序出错、崩溃
    */
    // 函数调用
    output1 = multi(num1, num2);
    output2 = quyu(num1, num2);
    output3 = zijian(num1);
    output4 = area(num1);  // 调用圆面积函数，半径为5
    // 输出结果
    printf("Product: %d\n", output1);
    printf("Remainder: %d\n", output2);
    printf("Decrement: %d\n", output3);  
    printf("Area of circle with radius 5: %.2f\n", output4);  // 输出圆面积，保留两位小数
    // %d 格式化输出占位符，用于输出int 整型数字。 \n换行转义字符，输出后光标换到下一行。
    
    quyuFunc f = quyu; // 函数指针 f 指向 quyu 函数
    printf("Using function pointer to calculate remainder: %d\n", f(num1, num2)); // 使用函数指针调用 quyu 函数
    return 0;        // 返回 0 表示程序成功执行
}
/*
格式化输出占位符：

%d / %i	有符号十进制整数
%p	指针地址，打印这地址本身 如：0x7ffe5c8a。0x代表十六进制，后面跟着地址的十六进制数值
*p	就是指针指向的那个字符
%c	单个字符
%s	字符串 ，功能是把地址当字符串起点，打印出内容



%f	浮点数 (float/double)，默认6位；    %.2f，保留两位小数
%x	十六进制整数
% i：功能等同于 % d，输出十进制 int
% u：输出无符号十进制 unsigned int
% hd：输出 short 短整型
% hhd：输出 char 类型整数
% ld：输出 long 长整型
% lld：输出 long long 长长整型
% o：输出无符号八进制整数
% x：小写格式输出十六进制
% X：大写格式输出十六进制
宽度修饰：
%5d：固定占 5 字符，右对齐，空位补空格
%05d：固定 5 位，不足高位补 0
%-5d：左对齐，右侧补空格
%+d：正数强制显示正号
*/
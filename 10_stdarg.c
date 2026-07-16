#include <stdio.h>
#include <stdarg.h>
/*
<stdarg.h>  可变参数标准头文件（Standard Arguments Header）
宏	                        作用
va_list	                    声明存参数列表的变量类型
va_start(list, last)	    初始化，指向第一个可变参数
va_arg(list, type)	        取出下一个参数，指针后移
va_end(list)	            清理
*/

double average(int num, ...) {   // num=参数个数, ...=后面跟的可变参数
    va_list valist;              // ① 声明一个"手柄"，用来遍历参数
    double sum = 0.0;            // double 用 0.0 初始化.累加和，用 double 防溢出
    int i;

    va_start(valist, num);       // ② 初始化：把手柄指向 num 后面的第一个参数
    //          ↑      ↑
    //       手柄    最后一个固定参数名（告诉编译器从哪开始）

    for (i = 0; i < num; i++) {            // ③ num 次循环
        sum += va_arg(valist, int);        // ④ 取出下一个参数（指定 int），手柄自动后移
        //              ↑
        //        每次取的时候要告诉类型（这里是 int）
    }
     /*
    va_arg(valist, int) 干了什么？
    调用 average(4, 2, 3, 4, 5)
    参数列表:  [2] [3] [4] [5] ...
                ↑
    第一次 va_arg → 取出 2，指针自动移到 3
    第二次 va_arg → 取出 3，指针自动移到 4
    第三次 va_arg → 取出 4，指针自动移到 5
    第四次 va_arg → 取出 5*/

    va_end(valist);              // ⑤ 清理，收回手柄

    return sum / num;            // 平均值。num=参数个数
}

int main()
{
   printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
   printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));
}
#include <stdio.h>
#include <string.h>

// union 只有一个坑，写完赶紧读，晚了就被踩了。 
// 想同时保留所有值，用 struct 别用 union。  共用体的优点：省内存

union Data
{
   int i;
   float f;
   char  str[20];
};
//   int main( )
// {
//    union Data data;        
 
//    data.i = 10;   写入 i
//    data.f = 220.5;  踩掉 i
//    strcpy( data.str, "C Programming");  踩掉 f
//  此时内存里只有 "C Programming"
 
//    printf( "data.i : %d\n", data.i);
//    printf( "data.f : %f\n", data.f);
//    printf( "data.str : %s\n", data.str);
 
//    return 0;
// }
//   结果：
// data.i : 1917853763
// data.f : 4122360580327794860452759994368.000000
// data.str : C Programming
// 这个错误结果是因为 union 所有成员住同一个房间，后来的踩掉先来的，三次赋值，三次踩踏

int main( )
{
   union Data data;        

   data.i = 10;
   printf( "data.i : %d\n", data.i);
   
   data.f = 220.5;
   printf( "data.f : %.2f\n", data.f);
   
   strcpy( data.str, "C Programming");
   printf( "data.str : %s\n", data.str);
 
   return 0;
}

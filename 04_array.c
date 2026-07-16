#include <stdio.h>
#define LENGTH(array) (sizeof(array) / sizeof(array[0]))

int main ()
{
    // 声明一个数组，需要指定元素的类型和元素的数量，如下所示：type arrayName [ arraySize ];
   int n[ 10 ]; /* n 是一个包含 10 个整数的数组 */
   int i,j;
   int length = LENGTH(n);
 
   /* 初始化数组元素 */         
   for ( i = 0; i < 10; i++ )
   {
      n[ i ] = i * 100; /* 设置元素 i 为 i + 100 */
   }
     printf("arrayLength: %d\n", length);
   /* 输出数组中每个元素的值 */
   for (j = 0; j < 10; j++ )
   {
      printf("Element[%d] = %d\n", j, n[j] );
   }
  
   return 0;
}
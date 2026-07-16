#include <stdio.h>
#include <string.h>
 
int main ()
{
    // 两种方式定义字符串
   char str1[20] = {'r', 'u', 'n', 'o', 'o', 'b', '\0'};
   char str2[14] = "google123";
   char str3[14];
  
 
   /* 复制 str1（源） 到 str3（目的） */
   strcpy(str3, str1);
   printf("strcpy( str3, str1) :  %s\n", str3 );
   /* 连接 str1 和 str2 */
   strcat( str1, str2);
   printf("strcat( str1, str2):   %s\n", str1 );
   /* 连接后，str1 的总长度 */
   int len1 = strlen(str1);
    printf("strlen(str1) :  %d\n", len1);
    printf("strlen(str2) :  %d\n", strlen(str2));
    printf("sizeof(str2) :  %d\n", sizeof(str2)); //数组总容量是14，不管里面装了多少
    printf("--------------------------\n");

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);
   printf("--------------------------\n");
// %s 不是打印单个字符.遇到一个地址，就从那里开始，一路打印到 \0：
/*
(1)strchr(str, 'a') 函数返回一个指针，指向字符串 str 中第一次出现字符 a 的位置。
如果在 str 中没有找到 a，则返回 NULL。
(2)strstr(str, "abc") 函数返回一个指针，指向字符串 str 中第一次出现子字符串 "abc" 的位置。
如果在 str 中没有找到 "abc"，则返回 NULL。 
*/
   char *result2 = strstr(str1, "oo");
   printf("strstr(str1,'oo'): %p\n", result2 );
   printf("strstr(str1,'oo'): %s\n", result2 );
   printf("strstr(str1,'oo'): %d\n", *result2 );
   // 地址 = 门牌号        内容 = 房子里的人
   // printf("%p", result2);  → 告诉你门牌号是多少
   // printf("%s", result2);  → 走到那个门牌号，把里面的人念出来
   // 若printf里是*result2，*result2是解引用，是一个字符 'o'（ASCII 值 111）：程序把 111 当成地址去访问 → 访问非法地址 → 崩溃/乱码

   char *result3 = strstr(str2, "og");
   printf("strstr(str2,'og'): %s\n", result3 );

   char *result = strchr(str3, 'g');
   printf("strchr(str3, 'g') : %s\n", result );

   return 0;
}
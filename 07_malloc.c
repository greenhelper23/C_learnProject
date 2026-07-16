#include <stdio.h>
#include <stdlib.h>       // malloc, realloc, free
#include <string.h>       // strcpy, strcat

int main() {
    char name[100];                        // ① 静态数组：栈上，100 字节
    char *ptr;                     // ② 指针，还没指向任何地方

    strcpy(name, "switzerland");              // ③ 把名字拷到 name 数组

    /* ---------- 第一次分配：malloc ---------- */
    ptr = (char*)malloc(30 * sizeof(char));  // ④ 堆上申请 30 字节
    //       (char*)     把 void* 强转成 char*，C 里可以省掉

    if (ptr == NULL) {             // ⑤ 必须检查！申请可能失败
        fprintf(stderr, "Error - unable to allocate required memory\n");
        //       ↑ stderr = 标准错误输出，专门打错误信息
    } else {
        strcpy(ptr, "apple mint,");  // ⑥ 往堆上拷字符串（26 个字符 + \0）
    }

    /* ---------- 第二次分配：realloc（扩容） ---------- */
    ptr = (char*)realloc(ptr, 100 * sizeof(char));
    //            ↑ realloc(原指针, 新大小): 保持原有内容，扩到 100 字节
    //   30 字节 → 100 字节

    if (ptr == NULL) {             // ⑦ 再次检查
        fprintf(stderr, "Error - unable to allocate required memory\n");
    } else {
        strcat(ptr, " ricola");
        // strcat = 拼接到末尾（ptr 现在有足够空间了）
    }

    /* ---------- 输出 ---------- */
    printf("Name ： %s\n", name);            // 静态数组的内容
    printf("Description: %s\n", ptr); // 堆上的字符串

    /* ---------- 释放 ---------- */
    free(ptr);                      // ⑧ 有 malloc 就得有 free
    // 注意：name 数组不用 free，它是栈上的，自动释放

    return 0;
}

/*
malloc  = 先租个小单间（30 ㎡）
realloc = 后来东西多了，换个 100 ㎡ 大房子，旧家具搬过去
strcat  = 新家够大，接着往里塞东西
free    = 退租走人
*/
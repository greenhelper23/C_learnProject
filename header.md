# C 语言头文件

## 概念

`#include` 是预处理指令，**编译前**把头文件内容复制到代码里。头文件只放**函数声明**和**类型定义**，不参与编译。

```c
#include <stdio.h>      // 标准库用尖括号
#include "myHeader.h"   // 自己写的用双引号
```

---

## 常用标准头文件

### `<stdio.h>` — 输入输出

| 函数/类型 | 说明 |
|-----------|------|
| `printf` | 格式化输出 |
| `scanf` | 格式化输入 |
| `getchar` | 读一个字符 |
| `putchar` | 写一个字符 |
| `fopen` | 打开文件 |
| `fclose` | 关闭文件 |
| `fgetc` / `fputc` | 文件读写字符 |
| `fprintf` / `fscanf` | 文件格式化读写 |
| `FILE` | 文件指针类型 |
| `stdin` / `stdout` / `stderr` | 标准输入/输出/错误流 |
| `EOF` | 文件结束标记 |

---

### `<stdlib.h>` — 通用工具

| 函数 | 说明 |
|------|------|
| `malloc(n)` | 分配 n 字节内存 |
| `calloc(n, s)` | 分配 n 个元素，每个 s 字节，初始化为 0 |
| `realloc(p, n)` | 调整已分配内存大小 |
| `free(p)` | 释放内存 |
| `atoi(s)` | 字符串 → int |
| `atof(s)` | 字符串 → double |
| `rand()` | 生成随机数 |
| `srand(seed)` | 设置随机种子 |
| `exit(code)` | 终止程序 |
| `abs(n)` | int 绝对值 |

---

### `<string.h>` — 字符串操作

| 函数 | 说明 |
|------|------|
| `strlen(s)` | 求字符串长度（不含 \0） |
| `strcpy(dst, src)` | 复制字符串 |
| `strncpy(dst, src, n)` | 复制最多 n 个字符 |
| `strcat(dst, src)` | 拼接字符串 |
| `strncat(dst, src, n)` | 拼接最多 n 个字符 |
| `strcmp(a, b)` | 比较字符串（相等返回 0） |
| `strchr(s, c)` | 查找字符，返回指针 |
| `strstr(hay, needle)` | 查找子串，返回指针 |

---

### `<math.h>` — 数学函数

编译时加 `-lm` 链接数学库。

| 函数 | 说明 |
|------|------|
| `sqrt(x)` | 平方根 |
| `pow(x, y)` | x 的 y 次方 |
| `sin(x)` / `cos(x)` | 正弦/余弦 |
| `log(x)` | 自然对数 |
| `fabs(x)` | double 绝对值 |
| `ceil(x)` / `floor(x)` | 向上/向下取整 |

---

### `<ctype.h>` — 字符判断

| 函数 | 说明 |
|------|------|
| `isalpha(c)` | 是否字母 |
| `isdigit(c)` | 是否数字 |
| `isupper(c)` | 是否大写字母 |
| `islower(c)` | 是否小写字母 |
| `isspace(c)` | 是否空白字符 |
| `toupper(c)` | 转大写 |
| `tolower(c)` | 转小写 |

---

### `<time.h>` — 时间

| 函数/类型 | 说明 |
|-----------|------|
| `time_t` | 时间类型 |
| `time(&t)` | 获取当前时间 |
| `clock()` | CPU 时钟计数 |
| `difftime(a, b)` | 时间差（秒） |

---

### `<limits.h>` — 类型范围

| 宏 | 含义 |
|----|------|
| `INT_MAX` | int 最大值 |
| `INT_MIN` | int 最小值 |
| `LONG_MAX` | long 最大值 |
| `CHAR_BIT` | char 的位数 |

---

### `<stdbool.h>` — 布尔类型

```c
#include <stdbool.h>
bool flag = true;       // 有了 bool / true / false
```

---

## 当前项目用到的头文件

| 文件 | 用到的头文件 |
|------|------------|
| `00_testtt.c` | `<stdio.h>` `<stdlib.h>` |
| `02_calculate.c` | `<stdio.h>` |
| `07_malloc.c` | `<stdio.h>` `<stdlib.h>` |
| `08_char.c` | `<stdio.h>` `<string.h>` |
| `09_struct.c` | `<stdio.h>` `<string.h>` |

# C 语言学习笔记
## 文件索引

| 文件 | 知识点 | 内容 |
|------|--------|------|
| [01_helloo.c](01_helloo.c) | Hello World | 程序入口、`printf` 输出 |
| [02_calculate.c](02_calculate.c) | 函数与运算 | 自定义函数、`scanf` 输入、加减乘除取余、函数指针 `typedef` |
| [03_if.c](03_if.c) | 条件分支 | `if` / `else if` / `else` 判断正数零负数 |
| [03.5_fib.c](03.5_fib.c) | 递归 | Fibonacci 数列的递归实现 |
| [04_array.c](04_array.c) | 数组 | 数组声明、`for` 遍历、`sizeof` 求长度、宏定义 |
| [05_pointer.c](05_pointer.c) | 指针基础 | `&` 取地址、`*` 解引用、`NULL` 空指针、野指针 |
| [06_min_max.c](06_min_max.c) | 指针参数 | 指针作为函数参数"返回"多个值、`const` 修饰 |
| [06.5.c](06.5.c) | 函数声明 | 函数原型前置声明，min/max 的另一种实现 |
| [07_malloc.c](07_malloc.c) | 动态内存 | `malloc` / `realloc` / `free` 分配堆内存扩容 |
| [08_char.c](08_char.c) | 字符串 | `strcpy` `strcat` `strlen` `sizeof` `strchr` `strstr` |
| [09_struct.c](09_struct.c) | 结构体 | 结构体定义、`typedef` 别名、`->` 访问、指针传参 |
| [09.5_union.c](09.5_union.c) | 共用体 | `union` 内存共享、覆盖机制、与 `struct` 对比 |
| [10_stdarg.c](10_stdarg.c) | 可变参数 | `stdarg.h`、`va_list/va_start/va_arg/va_end` 实现可变参数函数 |
| [11_stdlib.c](11_stdlib.c) | 标准库 | `malloc`/`realloc`/`free` 实战、`stderr` 错误输出 |
| [12_bubble sort.c](12_bubble%20sort.c) | 排序算法 | 冒泡排序原理与实现、复杂度分析 |
| [00_testtt.c](00_testtt.c) | 综合练习 | 两数之和(LeetCode)、命令行参数、阶乘递归等 |

---

## 配套笔记

| 文件 | 内容 |
|------|------|
| [const.md](const.md) | `const` 修饰符详解（指针 / 变量 / 函数参数） |
| [malloc.md](malloc.md) | 动态内存分配详解（malloc/calloc/realloc/free） |
| [header.md](header.md) | C 标准库头文件速查（stdio/stdlib/string/math…） |


## 核心速查

### 格式占位符

| 占位符 | 含义 | 占位符 | 含义 |
|:--:|------|:--:|------|
| `%d` | 有符号整数 | `%f` | 浮点数 |
| `%c` | 字符 | `%s` | 字符串 |
| `%p` | 指针/地址 | `%x` | 十六进制 |
| `%u` | 无符号整数 | `%lld` | long long |

### 指针

```c
int *p = &a;       // p 存 a 的地址
*p = 10;           // 通过 p 改 a 的值
p->member          // 结构体指针访问成员（等价 (*p).member）
```


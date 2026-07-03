# C 语言学习笔记

> 从零开始系统学习 C 语言，每个文件聚焦一个知识点，代码 + 注释即教程。

## 目录

| 序号 | 文件 | 知识点 | 一句话 |
|:---:|------|--------|--------|
| 01 | [01_helloo.c](01_helloo.c) | Hello World | C 程序入口，`printf` 输出 |
| 02 | [02_calculate.c](02_calculate.c) | 函数与运算 | 自定义函数、`scanf` 输入、算术运算、格式占位符 |
| 03 | [03_if.c](03_if.c) | 条件分支 | `if` / `else if` / `else` 判断正负数 |
| 04 | [04_array.c](04_array.c) | 数组 | 数组声明、`for` 遍历、`sizeof` 求长度、宏定义 |
| 05 | [05_pointer.c](05_pointer.c) | 指针基础 | `&` 取地址、`*` 解引用、`NULL` 空指针 |
| 06 | [06_min_max.c](06_min_max.c) | 指针应用 | 指针参数"返回"多个值、`const` 修饰、求最值 |
| — | [06.5.c](06.5.c) | 函数声明 | 函数原型前置声明，min/max 的另一种写法 |
| 07 | [07_malloc.c](07_malloc.c) | 动态内存 | `malloc` 分配堆内存、内存压力测试 |
| 08 | [08_char.c](08_char.c) | 字符串 | `strcpy` `strcat` `strlen` `strchr` `strstr` |
| 09 | [09_struct.c](09_struct.c) | 结构体 | 结构体定义、指针传参、`->` 访问成员 |
| — | [09.5_union.c](09.5_union.c) | 共用体 | `union` 内存共享、覆盖机制、与 struct 对比 |
| — | [testtt.c](testtt.c) | 结构体数组 | 结构体数组 + 指针遍历 |

## 配套笔记

- [const.md](const.md) — `const` 修饰符用法详解
- [malloc.md](malloc.md) — 动态内存分配详解（malloc / calloc / realloc / free）

## 学习路线

```
Hello World → 变量/运算 → 条件判断 → 数组
    → 指针（基础 → 应用 → 动态内存）
    → 字符串 → 结构体 → 共用体
```

## 运行环境

- **编译器**: GCC（MinGW / MSYS2）
- **系统**: Windows
- **编码**: UTF-8（编译时加 `-fexec-charset=GBK` 避免终端中文乱码）

```bash
# 编译运行
gcc 文件名.c -o 文件名.exe -fexec-charset=GBK
./文件名.exe
```

## 核心知识速查

### 格式占位符

| 占位符 | 含义 |
|--------|------|
| `%d` | 整数 |
| `%f` | 浮点数 |
| `%c` | 字符 |
| `%s` | 字符串 |
| `%p` | 地址/指针 |
| `%x` | 十六进制 |

### 指针

```c
int *p = &a;    // p 存 a 的地址
*p = 10;        // 通过 p 改 a 的值
p->member       // 结构体指针访问成员（等价 (*p).member）
```

### 值 vs 地址

```
变量值  a / *p    → 用 %d
地址    &a / p    → 用 %p
```

### 内存

| | 静态 | 动态 |
|--|------|------|
| 关键字 | `int a[10]` | `malloc(n)` |
| 位置 | 栈 | 堆 |
| 释放 | 自动 | 手动 `free` |

### struct vs union

| | struct | union |
|--|:--:|:--:|
| 成员内存 | 各占各的 | 共享一块 |
| 同时有效 | ✅ | ❌ 只有一个 |
| 大小 | 成员之和 | 最大成员 |
| 用途 | 组合数据 | 省内存 |

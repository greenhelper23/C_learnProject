# 动态内存分配

## 静态 vs 动态

```c
// 静态数组：大小编译时定死
int arr[10];                    // 只能存 10 个

// 动态分配：大小运行时决定
int n;
scanf("%d", &n);                // 用户输入要多少
int *arr = malloc(n * sizeof(int));  // 按需分配
```

| | 静态数组 | 动态分配 |
|------|:---:|:---:|
| 大小决定时机 | 编译时 | 运行时 |
| 存储位置 | 栈 | 堆 |
| 生命周期 | 自动释放 | 手动 free |
| 大小可变 | ❌ | ✅ (realloc) |

---

## 四个核心函数

| 函数 | 作用 | 初始化 |
|------|------|:---:|
| `malloc(n)` | 分配 n 字节 | 垃圾值 |
| `calloc(n, s)` | 分配 n 个元素，每个 s 字节 | 全 0 |
| `realloc(p, n)` | 扩容/缩容 | 保留原数据 |
| `free(p)` | 释放内存 | — |

---

## 标准使用流程

```c
#include <stdio.h>
#include <stdlib.h>   // malloc, free

int main() {
    int n;
    printf("输入数组大小: ");
    scanf("%d", &n);

    // ① 分配
    int *arr = (int*)malloc(n * sizeof(int));

    // ② 检查（分配失败返回 NULL）
    if (arr == NULL) {
        printf("分配失败\n");
        return 1;
    }

    // ③ 使用（和普通数组一样）
    for (int i = 0; i < n; i++)
        arr[i] = i * 10;

    // ④ 释放
    free(arr);
    arr = NULL;   // 置空，避免野指针

    return 0;
}
```

---

## malloc vs calloc

```c
int *p1 = malloc(5 * sizeof(int));   // 值是垃圾值
int *p2 = calloc(5, sizeof(int));    // 值全是 0
```

---

## realloc：调整大小

```c
int *p = malloc(5 * sizeof(int));    // 先分配 5 个

p = realloc(p, 10 * sizeof(int));    // 扩到 10 个（原数据保留）

p = realloc(p, 3 * sizeof(int));     // 缩到 3 个（多余数据丢弃）
```

---

## 图解

```
静态数组（栈）                     动态分配（堆）
┌──────────┐                    ┌──────────┐
│ int a[3] │  函数结束自动释放    │  malloc  │  必须手动 free
│  编译时  │                    │  运行时  │  忘了 = 内存泄漏
│  定大小  │                    │  定大小  │
└──────────┘                    └──────────┘
```

---

## ⚠️ 常见错误

```c
// ① 忘记释放 —— 内存泄漏
int *p = malloc(100);
// ... 用完没 free，指针丢了，内存永远回不来

// ② 释放后继续用 —— 野指针
free(p);
*p = 10;    // ❌ 内存已被回收

// ③ 重复释放
free(p);
free(p);    // ❌ 程序崩溃

// ④ 没检查 NULL
int *p = malloc(1000000000000);  // 可能失败
*p = 10;    // ❌ 如果 p 是 NULL，程序崩溃
```

---

## 核心规则

```
malloc / free 必须一一配对
每次 malloc 都需要一个对应的 free
释放后立即置 NULL
```

```c
free(p);
p = NULL;   // 好习惯
```

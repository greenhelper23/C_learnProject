# const 修饰符

`const` 告诉编译器"这个值不能被修改"，修改会直接编译报错。
const = 只读保护，防止代码误改数据，让程序更稳定。

---

## 1. 修饰普通变量

```c
const int x = 10;
x = 20;   // ❌ 编译报错
```

---

## 2. 修饰指针（四种组合）

> 口诀：**const 离谁近，谁就不能变**

| 写法 | 指针可变？ | 指向的值可变？ |
|------|:---:|:---:|
| `int *p` | √ | √ |
| `const int *p` | √ | ❌ |
| `int * const p` | ❌ | √ |
| `const int * const p` | ❌ | ❌ |
```c
int * const p
锁死了遥控器：遥控器被牢牢固定住，不能对着另一台电视（p 不能更换地址）。
节目不受限制：你可以换台、调画质，电视里的内容可以随便修改（*p 可以修改值）
const int *p
遥控器可以随便挪动，可以对准别的电视机（p 可以改地址）；
但是电视被锁住了，不能修改画面内容（*p 不能改）。
const int * const p
遥控器钉死不能移动，电视画面也被锁定。
既不能换电视机，也不能更改节目，两者全都动不了。
```
# 速记：int * const p;    // * 在 const 前 → 指针不能改

# const int *p;     //  * 在 const 后 → 值不能改
```c
int a = 10, b = 20;

// ① 指向的值不能改（只读指针）
const int *p1 = &a;
p1 = &b;       // √ 可以指向别处
*p1 = 999;     // ❌ 报错

// ② 指针不能改（固定指向）
int * const p2 = &a;
p2 = &b;       // ❌ 报错
*p2 = 999;     // ✅ 可以改值

// ③ 都不能改
const int * const p3 = &a;
p3 = &b;       // ❌ 报错
*p3 = 999;     // ❌ 报错
```

---

## 3. 修饰函数参数

```c
// 承诺：只读数组，绝不修改内容
void printArray(const int arr[], int size) {
    // arr[i] = 0;  ❌ 编译器拦住了
    printf("%d ", arr[i]);  // ✅ 只读没问题
}

// 承诺：只读字符串
size_t strlen(const char *str);
```

好处：函数签名一目了然，调用者知道数据不会被改。

---

## 4. 区分两个容易混淆的写法

```c
const int *p;    // 东西不能改
int * const p;   // 指针不能改
```

从右往左读：
- `const int *p` → p is a pointer to **int that is const**
- `int * const p` → p is a **const pointer** to int




#include <stdio.h>
#include <string.h>
struct  Books   //  (1)结构体标签叫 Books，标签用大写开头
{
    char title[50];     //  (2)结构体成员变量
    char author[50];
    char subject[100];
    double price;
};
typedef struct Books Boook; //Boook（是 struct Books 的别名)

/*
typedef struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Boook;    Boook 完全等价于 struct Books
 也可用typedef 这样写。后续定义 对应的变量时就可以直接使用 Boook，如 Boook Book2;
 */
void outputBook(struct Books *book);  //函数参数是结构体类型
int main(void){
    struct Books Book1;  //  (3)局部变量，结构体变量
    Boook Book2;  //用别名，省掉 struct 关键字
    strcpy(Book1.title, "C Programming");
    strcpy(Book1.author, "yc");   
    strcpy(Book1.subject, "C Programming Tutorial");
    // 只有数组才需要 strcpy  ； 普通变量用 = 就行
    Book1.price = 65.99;
    strcpy(Book2.title, "java Programming");
    strcpy(Book2.author, "cy");
    strcpy(Book2.subject, "java Tutorial");
    Book2.price = 23.99;

    outputBook(&Book1);  //传递结构体变量的地址
    outputBook(&Book2);
    return 0;
}

void outputBook(struct Books *book)  //函数参数是结构体类型,传指针：只传 8 字节（地址）
// struct Books *book   接收一个指针，指向某个 struct Books
{
    printf("--------------------------\n");
    printf("Book title : %s\n", (*book).title);
    printf("Book author : %s\n", book->author);
    printf("Book subject : %s\n", book->subject);
    printf("Book price : %.2f\n", book->price);
    // b.title	拷贝整个结构体;     b->title	只传 8 字节
    // book->title   ←→   (*book).title     两者等价

}

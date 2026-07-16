#include <stdio.h>
#include <time.h> 
#include <stdlib.h>  
// 冒泡排序
//  https://www.runoob.com/cprogramming/c-sort-algorithm.html

void bubbleSort(int arr[],int len)
{
    for (int i = 0;i<len-1 ; i++){
        //因为每轮沉底一个元素，n-1 轮后，n-1 个都归位了，剩下的那一个也自动归位。
        //n个数进行n-1轮比较，每轮比较n-i-1次，i是当前轮数
         for (int j =0; j<len -1 - i ; j++){
        if (arr[j] > arr[j+1]){
        //冒泡的核心操作——"相邻比较、交换"
        int temp = arr[j];  // 暂存左边的
        arr[j] = arr[j+1];  // 右边挪到左边
        arr[j+1] = temp;
            }   // 暂存的放到右边
         } 
    }
}

void printArray(int arr[],int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("输入数组大小: ");
    scanf("%d", &n);

    int arr[n];

    // 生成随机数
    srand(time(NULL));                // 用当前时间做种子，每次运行不一样
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;        // 0~99 的随机数

    printf("原始数组: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("排序后:   ");
    printArray(arr, n);

    return 0;
}



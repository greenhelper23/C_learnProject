#include <stdio.h>

// 通过指针返回最小值和最大值
// int arr[] 等价于指针，真数组，有完整大小
// int *arr 真指针，只存地址
void findMinMax(const int arr[],int size, int *min, int *max) {
    *min = *max = arr[0];   // 假设第一个元素既是最大也是最小

    for (int i = 1; i < size; i++) {
        if (arr[i] < *min)
            *min = arr[i];  // *min 顺着地址改写外面的 min 变量
        if (arr[i] > *max)
            *max = arr[i];
    }
}

int main() {
    int nums[] = {23, 5, 87, 12, 56, 1, 99, 41};
    int size = sizeof(nums) / sizeof(nums[0]);
    int min, max;

    findMinMax(nums, size, &min, &max);  // & 传地址，函数才能修改它们

    printf("array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", nums[i]);
    printf("\nmin = %d\n", min);
    printf("max = %d\n", max);

    return 0;
}

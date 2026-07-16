#include <stdio.h>

void minmax(int a[], int len, int *max, int *min);
int main(void)
{
    int a[] = {1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55,};
    int min,max;
    minmax(a, sizeof(a)/sizeof(a[0]), &min, &max);
    
// C 语言没有直接一次性打印整个数组的语句，必须用循环。
    printf("array:");
    for (int i=0; i<sizeof(a)/sizeof(a[0]); i++){
    printf("%d ", a[i]);
    }
    printf("\nmin=%d\nmax=%d\n", min, max);

}

void minmax(int a[], int len, int *min, int *max)
{
    int i;
    *min = *max=a[0];
    for (i=1; i<len; i++) {
        if ( a[i] < *min ) {
            *min = a[i];
        }
        if ( a[i] > *max ) {
            *max = a[i];
        }
    }
}
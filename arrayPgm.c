#include<stdio.h>
#include<stdlib.h>
#define max 50

void main(){
     int arr1[max], arr2[max], arr3[max];
    int num1, num2, num3;
    printf("\nEnter the number of elements in array1: ");
    scanf("%d", &num1);
    printf("\nEnter the elements in array1: ");
    for (int i = 0; i < num1; i++)
    {
        printf("\narr1[%d]:", i);
        scanf("%d", &arr1[i]);
    }
    printf("\nEnter the number of elements in array2: ");
    scanf("%d", &num2);
    printf("\nEnter the elements in array2: ");
    for (int i = 0; i < num2; i++)
    {
        printf("\narr2[%d]:", i);
        scanf("%d", &arr2[i]);
    }

    num3 = num1 + num2;
    merge(arr1, arr2, arr3, num1, num2);

    for (int i = 0; i < num3; i++)
        printf("%d\t", arr3[i]);
}
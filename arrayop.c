#include <stdio.h>
#include <stdlib.h>
#define max 30
void merge1(int arr1[], int arr2[], int arr3[], int num1, int num2)
{
    // merge[1,2,3,4,5,6]
    int num3 = num1 + num2;
    for (int i = 0; i < num3; i++)
    {
        if (i < num1)
        {
            arr3[i] = arr1[i];
        }
        else
        {
            arr3[i] = arr2[i - num1];
        }
    }
}
void merge2(int arr1[], int arr2[], int arr3[], int num1, int num2)
{
    // merge[1,2,3,7,6,5,4]
    int num3 = num1 + num2;
    for (int i = 0; i < num3; i++)
    {
        if (i < num1)
        {
            arr3[i] = arr1[i];
        }
        else
        {
            arr3[i] = arr2[num3 - 1 - i];
        }
    }
}
void merge3(int arr1[], int arr2[], int arr3[], int num1, int num2)
{
    // merge[1,4,2,5,3,6]
    int num3 = num1 + num2;
    int i=0,j = 0,k=0;
    while (i<num1 && j<num2)
    {
        arr3[k++]=arr1[i++];
        arr3[k++]=arr2[j++];
    }
     
     while(i<num1){
        arr3[k++]=arr1[i++];
     }

     while(j<num2){
        arr3[k++]=arr2[j++];
     }

}

void main()
{
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
    merge3(arr1, arr2, arr3, num1, num2);

    for (int i = 0; i < num3; i++)
        printf("%d\t", arr3[i]);
}
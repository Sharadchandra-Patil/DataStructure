#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void AcceptArray(int a[], int size);
void DisplayArray(int *a, int size);
int asc(const void *p1, const void *p2);
int desc(const void *p1, const void *p2);
int main()
{
    int arr[SIZE];
    
    int (*funptr)(const void *, const void *);
    printf("\nEnter elements of array::\n");
    AcceptArray(arr, SIZE);

    printf("\n elements of array before sort::\n ");
    DisplayArray(arr, SIZE);
    funptr=asc;
 
    qsort(arr, SIZE, sizeof(int), funptr);
    printf("\n elements of array after asc sort::\n ");
    DisplayArray(arr, SIZE);


    funptr=desc;
    qsort(arr, SIZE, sizeof(int), funptr);
    printf("\n elements of array after desc sort::\n ");
    DisplayArray(arr, SIZE);
    
    return;
}
int asc(const void *p1, const void *p2)
{
    int *ptr1=(int*)p1;
    int *ptr2=(int*)p2;
    return *ptr1-*ptr2;
}

int desc(const void *p1, const void *p2)
{
    int *ptr1=(int*)p1;
    int *ptr2=(int*)p2;
    return *ptr2-*ptr1;
}

void AcceptArray(int a[], int size)
{
    int index;
    for(index=0; index<size; index++)
    {
        printf("arr[%d]::", index);
        scanf("%d", &a[index]);
    }
    return ;
}
void DisplayArray(int *a, int size)
{
    int index;
    for(index=0; index<size; index++)
    {
        printf("\n a[%d] %d [%u]",index, a[index],&a[index] );
    }
    return ;
}

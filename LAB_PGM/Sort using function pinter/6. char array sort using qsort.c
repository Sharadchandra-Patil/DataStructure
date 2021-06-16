#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void AcceptArray(char a[], int size);
void DisplayArray(char *a, int size);
int asc(const void *p1, const void *p2);
int desc(const void *p1, const void *p2);
int main()
{
    char arr[SIZE];
    
    int (*funptr)(const void *, const void *);
    printf("\nEnter elements of array::\n");
    AcceptArray(arr, SIZE);

    printf("\n elements of array before sort::\n ");
    DisplayArray(arr, SIZE);
    funptr=asc;
 
    qsort(arr, SIZE, sizeof(char), funptr);
    printf("\n elements of array after asc sort::\n ");
    DisplayArray(arr, SIZE);


    funptr=desc;
    qsort(arr, SIZE, sizeof(char), funptr);
    printf("\n elements of array after desc sort::\n ");
    DisplayArray(arr, SIZE);
    
    return;
}
int asc(const void *p1, const void *p2)
{
    char *ptr1=(char*)p1;
    char *ptr2=(char*)p2;
    printf("\ncall asc\n");
    return *ptr1-*ptr2;
}

int desc(const void *p1, const void *p2)
{
    
    char *ptr1=(char*)p1;
    char *ptr2=(char*)p2;
    printf("\ncall desc\n");
    return *ptr2-*ptr1;
}

void AcceptArray(char a[], int size)
{
    int index;
    for(index=0; index<size; index++)
    {
        printf("arr[%d]::", index);
        scanf("%c%*c", &a[index]);
    }
    return ;
}
void DisplayArray(char *a, int size)
{
    int index;
    for(index=0; index<size; index++)
    {
        printf("\n a[%d] %c [%u]",index, a[index],&a[index] );
    }
    return ;
}

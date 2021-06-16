#include<stdio.h>
#define SIZE 5
void AcceptArray(int a[], int size);
int DisplayArray(int *a, int size);
void Sort(int a[], int size);
int main()
{
    int arr[SIZE];
    printf("\nEnter elements of array::\n");
    AcceptArray(arr, SIZE);
    
    printf("\n elements of array before sort::\n ");
    DisplayArray(arr, SIZE);
    Sort(arr, SIZE);
    printf("\n elements of array after sort::\n ");
    DisplayArray(arr, SIZE);
    return 0;
    
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
int DisplayArray(int *a, int size)
{
    int index;
    for(index=0; index<size; index++)
    {
        printf("\n a[%d] %d [%u]",index, a[index],&a[index] );
    }
    return 0;
}

void Sort(int a[], int size)
{
    int i,  j, temp;
    for(i=0; i<size-1; i++)
    {
        for(j=i+1; j<size; j++)
        {
            printf("\na[%d]=%d a[%d]=%d\n", i, a[i], j, a[j]);
           // if(a[i]>a[j])// asc
            if(a[i]<a[j])// desc
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        if(i<size-1)
            printf("\n\t pass[%d]\n", i+1);
    }
    return;
}
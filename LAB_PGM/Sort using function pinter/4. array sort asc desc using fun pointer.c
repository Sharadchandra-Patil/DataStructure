#include<stdio.h>
#define SIZE 5
void AcceptArray(int a[], int size);
void DisplayArray(int *a, int size);
void Sort(int a[], int (*fp)(int num1, int num2),int size);
int asc(int n1, int n2);
int desc(int n1, int n2);
int main()
{
    int arr[SIZE];
    int (*funptr)(int num1, int num2);
    printf("\nEnter elements of array::\n");
    AcceptArray(arr, SIZE);

    printf("\n elements of array before sort::\n ");
    DisplayArray(arr, SIZE);
    funptr=asc;
    Sort(arr,funptr, SIZE);
    printf("\n elements of array after asc sort::\n ");
    DisplayArray(arr, SIZE);


    funptr=desc;
    Sort(arr,funptr, SIZE);
    printf("\n elements of array after desc sort::\n ");
    DisplayArray(arr, SIZE);
    
    return 0;
}
int asc(int n1, int n2)
{
    return n1-n2;
}

int desc(int n1, int n2)
{
    return n2-n1;
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

void Sort(int a[], int (*fp)(int num1, int num2),int size)
{
    int i,  j, temp;
    for(i=0; i<size+1; i++)
    {
        for(j=i+1; j<size; j++)
        {
            printf("\na[%d]=%d a[%d]=%d\n", i, a[i], j, a[j]);
           if(fp(a[i], a[j])>0) // asc desc
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
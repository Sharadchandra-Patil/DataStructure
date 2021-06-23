
#include<stdio.h>

int main(void)
{    
    int i,j,count,BOOL=0;
    //int arr[]={10,20,30,40,50,10,20,30,100,30};
    int arr[]={12,12,13,12,12,12,12,12,12,12};
    int SIZE = sizeof(arr) / sizeof(int);

    printf("\nArray befor removing dulpicates is::\n");
    for(i=0;i<SIZE; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
    count=0;
    if(arr[0]==arr[SIZE-1])
        BOOL=1;
    for(i=0; i<SIZE; i++)
    {           
         for(j=i+1; j<SIZE ; j++)
        {
            if(arr[i]==arr[j])
              {
                  break;
              }
        }
        if(j==SIZE)
        arr[count++]=arr[i];
      
    }

    printf("\nDistinct elements in Array  is::\n");
  
    if(BOOL==1)
      count--;
      
    for(int i=0;i<count; i++)
    {
        printf(" %d ",arr[i]);
    }   
    printf("\n\n");
    return 0;
}
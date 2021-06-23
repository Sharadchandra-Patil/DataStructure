
#include<stdio.h>

#define SWAP(A,B) {A=A^B; B=A^B; A=A^B;}
int main(void)
{    
    int i,j,count,BOOL=0;
    //int arr[]={10,20,30,40,50,10,20,30,100,30};
    int arr[]={12,12,13,12,12,12,12,12,12,12};
    int SIZE = sizeof(arr) / sizeof(int);

    printf("\nArray befor removing dulpicates is::\n");
    for(i=0;i<SIZE; i++)
    {
        printf(" %d-->",arr[i]);
    }
    printf("End\n");
    count=0;
    if(arr[0]==arr[SIZE-1])
        BOOL=1;
    for(i=0; i<SIZE; i++)
    {   
        /*count=1;
        for(j=i+1; j<SIZE ; j++)
        {
            if(arr[i]==arr[j])
              {
                SWAP(arr[j],arr[SIZE-1]);
                SIZE--;
                count++;
                j--;
            }
        }*/
         for(j=i+1; j<SIZE ; j++)
        {
            if(arr[i]==arr[j])
              {
                  break;
              }
        }
        if(j==SIZE)
        arr[count++]=arr[i];
       // printf("\nElement %d is occured %d number of times in given array..arr "
          //      ,arr[i],count);
    }

    printf("\n\nArray after removing duplicates is::\n");
    //for(int i=0;i<SIZE; i++)
    if(BOOL==1)
      count--;
      
    for(int i=0;i<count; i++)
    {
        printf(" %d-->",arr[i]);
    }   
    printf("End\n\n");
    return 0;
}
//implementation of array operations:
#include<stdio.h>
#define SIZE 10

#define true 1
#define false 0

typedef int bool_t;

int comparisons = 0;//global vars can be accessed from anywhere in a program

void display_array_elements(int arr[]);//arr is a pointer to 1-d array
bool_t linear_search(int arr[], int key);


int main(void)
{
    int arr[ SIZE ] = { 30, 10, 70, 80, 90, 100, 50, 40, 20, 60 };
    int key;

    printf("array ele's are: ");
    display_array_elements(arr);

    //accept the value of key from user
    printf("enter the key: ");
    scanf("%d", &key);

    if( linear_search(arr, key) )
        printf("%d is found in an array, no. of comparisons = %d\n", key, comparisons);
    else
        printf("%d is not found in an array, no. of comparisons = %d\n", key, comparisons);


    return 0;
}

void display_array_elements(int arr[])
{
    int index=0;
    for( index = 0 ; index < SIZE ; index++ ){
        printf("%4d", arr[ index ]);       
    }
    printf("\n");
}

bool_t linear_search(int arr[], int key)
{
    int index = 0;
    comparisons=0;

    for( index = 0 ; index < SIZE ; index++ ){
        comparisons++;
        if( key == arr[ index ] )//if key matches with any array ele
            return true;//key is found
    }
    
    return false;//if key do not matches with any array ele return false -> key is not found
}






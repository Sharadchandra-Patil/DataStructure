//implementation of array operations: sorting algorithms
#include<stdio.h>
#define SIZE 10


#define SWAP(a, b) { int t = a; a = b ; b = t; }

void display_array_elements(int arr[]);//arr is a pointer to 1-d array
void selection_sort(int arr[]);//arr is a pointer to 1-d array


int main(void)
{
    //int arr[ SIZE ] = { 30, 10, 70, 80, 90, 100, 50, 40, 20, 60 };
    int arr[ SIZE ] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    //int arr[ SIZE ] = { 30, 20, 60, 50,10, 40 };
    printf("bfore sorting : "); display_array_elements(arr);
    
    selection_sort(arr);

    printf("after sorting : "); display_array_elements(arr);


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

void selection_sort(int arr[])
{
    int sel_pos;
    int pos;
    int iterations=0;
    int comparisons=0;

    for( sel_pos = 0 ; sel_pos < SIZE-1 ; sel_pos++ )//outer for loop is for iterations
    {
        iterations++;
        for( pos = sel_pos + 1 ; pos < SIZE ; pos++ )//inner for loop for pos
        {
            comparisons++;
            //if ele at sel_pos found greater than ele at pos -> swap them
            if( arr[ sel_pos ] > arr[ pos ] )
                SWAP(arr[sel_pos], arr[ pos ] );
        }
    }

    printf("no. of iterations are: %d\n", iterations);
    printf("no. of comparisons are: %d\n", comparisons);
}


















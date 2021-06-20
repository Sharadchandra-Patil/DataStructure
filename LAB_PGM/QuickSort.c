//implementation of array operations: sorting algorithms
#include<stdio.h>
#define SIZE 10


#define SWAP(a, b) { int t = a; a = b ; b = t; }

void display_array_elements(int arr[]);//arr is a pointer to 1-d array
void selection_sort(int arr[]);//arr is a pointer to 1-d array
void bubble_sort(int arr[]);
void insertion_sort(int arr[]);
void Quicksort(int arr[],int start,int end);
int partition(int arr[],int start,int end);

int main(void)
{
    int arr[ SIZE ] = { 30, 10, 70, 80, 90, 100, 50, 40, 20, 60 };
    //int arr[ SIZE ] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    //int arr[ SIZE ] = { 30, 20, 60, 50,10, 40 };
    printf("bfore sorting : "); 
    display_array_elements(arr);
    
    //selection_sort(arr);
    //bubble_sort(arr);
    //insertion_sort(arr);
    Quicksort(arr,0,SIZE-1);

    printf("after sorting : "); 
    display_array_elements(arr);


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

//efficient implementation of bubble sort algorithm:
void bubble_sort(int arr[])
{   
    int pos;
    int iterations=0;
    int comparisons=0;
    int flag = 1;


    for(int it = 0 ; it < SIZE-1 && flag == 1 ; it++ )//outer for loop is for iterations
    {
        flag = 0;
        iterations++;
        for( pos = 0 ; pos < SIZE-1-it ; pos++ )//inner for loop is for pos
        {
            comparisons++;
            //if ele's are not in order => if( prev pos ele > its next pos ele) --> swap them
            if( arr[ pos ] > arr[ pos+1 ] )
            {
                SWAP(arr[ pos ], arr[pos+1] );
                flag = 1;
            }
        }
    }

    printf("no. of iterations are: %d\n", iterations);
    printf("no. of comparisons are: %d\n", comparisons);

}

/* basic bubble sort algorithm:
void bubble_sort(int arr[])
{
    int it = 0;
    int pos;
    int iterations=0;
    int comparisons=0;


    for( it = 0 ; it < SIZE-1 ; it++ )//outer for loop is for iterations
    {
        iterations++;
        for( pos = 0 ; pos < SIZE-1-it ; pos++ )//inner for loop is for pos
        {
            comparisons++;
            //if ele's are not in order => if( prev pos ele > its next pos ele) --> swap them
            if( arr[ pos ] > arr[ pos+1 ] )
                SWAP(arr[ pos ], arr[pos+1] );
        }
    }

    printf("no. of iterations are: %d\n", iterations);
    printf("no. of comparisons are: %d\n", comparisons);

}
*/

void insertion_sort(int arr[])
{
    int i;
    int iterations=0;
    
    for( i = 1 ; i < SIZE ; i++ )
    {
        iterations++;
	    int key = arr[ i ];
	    int j = i-1;

	    while( j >= 0 && key < arr[ j ] )
        {
            arr[ j+1 ] = arr[ j ];//shift ele towards its right
		    j--;//goto the prev ele
	    }	

        //insert key into an array at its appropriate position
	    arr[ j+1 ] = key;
    }
    printf("no. of iterations are: %d\n", iterations);
    
}


void Quicksort(int arr[],int start,int end)
{
    if(start < end)
    {
    int pindex = partition(arr,start ,end);
    Quicksort(arr,start,pindex-1);
    Quicksort(arr,pindex+1,end);
    }
    return;
}

int partition(int arr[],int start,int end)
{
    int pivot=arr[end];
    int pindex=start;
    int i;

    for(i=start;i<end;i++)
    {
        if(arr[i] < pivot)
            {
                SWAP(arr[i],arr[pindex]);
                pindex++;
            }
    }
   
    SWAP(arr[pindex],arr[end]);  
    return pindex;       
}











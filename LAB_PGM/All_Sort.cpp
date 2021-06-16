
#include<iostream>
using namespace std;

#define SIZE 10
#define swap(a,b) {a=a^b; b=a^b; a=a^b;}

int iteration=0,comparision=0;    

void DisplayArrayElements(int *arr);
void Selection_sort(int *arr);
void Insertion_sort(int *arr);
void BubbleSort(int arr[]);

int main(void)
{
    //int arr[SIZE] = { 10 , 30 , 40 , 20 , 60 , 80 ,50 ,70 ,100 ,90 };
    int arr[SIZE] = {100,90,80,70,60,50,40,30,20,10};
    //int arr[SIZE] = { 10,20,30,40,50,60,70,80,90,100};
    
    cout<<'\n'<<"*This is implementation of Bubble sort algorithm*"<<'\n'<<endl ;
    cout<<"Following are the array elements before sort:: "<<endl;
    DisplayArrayElements(arr);

    //Selection_sort(arr);
    Insertion_sort(arr);
    //BubbleSort(arr);   
        
    cout<<'\n'<<"Following are the array elements after sort:: "<<'\n';
    DisplayArrayElements(arr);
    cout<<'\n'<<"Iterations="<<iteration<<"   comparisions="<<comparision<<endl;
   
    cout<<'\n'<<'\n';
    return 0;
}

void DisplayArrayElements(int *arr)
{
    for(int i=0 ; i<SIZE ; i++)
    {
        cout<<"   arr[" << i << "]=" << arr[i] ;
    }
    cout<<'\n';
    return ;
}

void Selection_sort(int *arr)
{
    for(int i=0 ; i<SIZE-1; i++)
    {
        for(int j=i+1 ; j<SIZE ; j++)
        {
            if(arr[i] > arr[j])
                 swap(arr[i] , arr[j]);
        }
    }
}

void Insertion_sort(int *arr)
{
    int flag=1;
    for(int i=1;i<SIZE;i++)
    {   
        iteration++;
        int key=arr[i];
        int j;
        //int j=i-1;
        for(j=i-1;j>=0 && key<arr[j];j--)
        //while(j>=0 && key<arr[j])
        {
            comparision++;
            arr[j+1]=arr[j];
            flag=0;
           // j--;
        }

        arr[j+1]=key;
    }
    if(flag==1)
      comparision = SIZE-1;
      return;
}

void BubbleSort(int arr[])
{   
    int flag=1;
    for(int itr=SIZE-1  ; itr>0 && flag==1 ; itr--)
    {
        flag=0;
        iteration++;
        for(int pos=0 ; pos<itr ; pos++)
        {
            comparision++;
            if(arr[pos] > arr[pos+1])
            {
                flag=1;
                swap(arr[pos] , arr[pos+1]);
            }
        }                 
    }
    return;
}


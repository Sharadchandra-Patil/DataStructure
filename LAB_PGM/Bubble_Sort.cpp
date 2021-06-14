
#include<iostream>
using namespace std;

#define SIZE 10
#define swap(a,b) {a=a^b; b=a^b; a=a^b;}
int flag=0;
int iteration=0,comparision=0;    

void DisplayArrayElements(int *arr);
void BubbleSort(int arr[]);

int main(void)
{
    //int arr[SIZE] = { 10 , 30 , 40 , 20 , 60 , 80 ,50 ,70 ,100 ,90 };
   // int arr[SIZE] = {100,90,80,70,60,50,40,30,20,10};
    int arr[SIZE] = { 10,20,30,40,50,60,70,80,90,100};
    
    cout<<'\n'<<"*This is implementation of Bubble sort algorithm*"<<'\n'<<endl ;
    cout<<"Following are the array elements before sort:: "<<endl;
    DisplayArrayElements(arr);

    BubbleSort(arr);   

    if(flag==0)
    cout<<'\n'<<"Given Array is already sorted in ascending order "<<endl;
    
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

void BubbleSort(int arr[])
{   
    for(int itr=SIZE-1 ; itr>0 ; itr--)
    {
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
        
        if(flag==0)
            return;         
    }
    
}

#include<iostream>
using namespace std;

#define SIZE 10
#define swap(a,b) {a=a^b; b=a^b; a=a^b;}
int flag=0;
int iteration=0,comparision=0; 

class MyBubbleSort
{
    private: 
    int* ar;
    int arr[SIZE];
   
    public:

    MyBubbleSort()
    { }
   
    void Acceptarray(int* ar);
    void Acceptarray();
    void DisplayArrayElements();
    void BubbleSort();
    ~MyBubbleSort()
    {
        cout<<"Destructor called....Memory released....Dangling pointer avoided by setting ptr to NULL...."<<'\n'<<endl;
        delete []ar;
        ar=NULL;
    }
};

int main(void)
{
    int arr[SIZE] = { 10 , 30 , 40 , 20 , 60 , 80 ,50 ,70 ,100 ,90 };
    MyBubbleSort s1;
    
    cout<<'\n'<<"*This is implementation of Bubble sort algorithm*"<<'\n'<<endl ;
   // s1.Acceptarray(arr);
    s1.Acceptarray();
    cout<<"Following are the array elements before sort:: "<<endl;
    s1.DisplayArrayElements();
    s1.BubbleSort();   

    if(flag==0)
    cout<<'\n'<<"Given Array is already sorted in ascending order "<<endl;
    
    cout<<'\n'<<"Following are the array elements after sort:: "<<'\n';
    s1.DisplayArrayElements();
    cout<<'\n'<<"Iterations="<<iteration<<"   comparisions="<<comparision<<endl;
    cout<<'\n';
    
    return 0;
}

void MyBubbleSort::Acceptarray(int* arr)
{
    this->ar=arr;
}

void MyBubbleSort::Acceptarray()
{
    cout<<'\n'<<"Enter "<<SIZE<<" arrray ELEMENTS:: "<<endl;
    for(int i=0 ; i<SIZE ; i++)
    {
        cin>>this->arr[i];
    }
}

void MyBubbleSort::DisplayArrayElements()
{
    for(int i=0 ; i<SIZE ; i++)
    {
        cout<<"   arr[" << i << "]=" <<this->arr[i] ;
    }
    cout<<'\n';
    return ;
}

void MyBubbleSort::BubbleSort()
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
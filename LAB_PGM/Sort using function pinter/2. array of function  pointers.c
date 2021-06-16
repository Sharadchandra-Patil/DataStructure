#include<stdio.h>
int sum(int n1, int n2);
int minus(int n1, int n2);
int multiply(int n1, int n2);
int main()
{
    int no1=10, no2=20, ans=0, index;
    int (*funptr[3])(int num1, int num2);
    // funptr is  array of function 3 pointers where each fun recives 2
    // arguements of int type and return type is also int
    funptr[2]=sum;
    funptr[1]=minus;
    funptr[0]=multiply;

    for(index=0; index<3; index++)
    {
        printf("\n calculation using function pointer old way = %d", (*funptr[index])(no1, no2));
        printf("\n calculation using function pointer new way = %d", funptr[index](no1, no2));
    }
    return 0;
}
int sum(int n1, int n2)
{
    return n1+n2;
}
int minus(int n1, int n2)
{
    return n1-n2;
}
int multiply(int n1, int n2)
{
    return n1*n2;
}

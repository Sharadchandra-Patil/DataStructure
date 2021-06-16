#include<stdio.h>
int sum(int n1, int n2);
int main()
{
    int no1=10, no2=20, ans=0;
    int (*funptr)(int num1, int num2);
    // funptr is pointer to function which recives 2
    // arguements of int type and return type is also int
    funptr=sum;
    printf("\n sum using function call =%d", sum(no1, no2));
    printf("\n sum using function pointer old way = %d", (*funptr)(no1, no2));
    printf("\n sum using function pointer new way = %d", funptr(no1, no2));
    return 0;
}
int sum(int n1, int n2)
{
    return n1+n2;
}
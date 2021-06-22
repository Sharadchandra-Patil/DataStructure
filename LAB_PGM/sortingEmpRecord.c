#include<stdio.h>
#pragma pack(1)
#define SIZE 5
#define SWAP(a, b , type){type temp; temp=a;a=b; b=temp;}
struct date
{
    int mm, dd, yy;
};
struct emp
{
    int empno;
    char name[10];
    float sal;
    struct date doj;
};// slack bytes added 

void AcceptEmp(struct emp e[], int size);
void SortEmp(struct emp e[], int size);
void PrintEmp(const struct emp e[], int size);
void swap(struct emp *e1, struct emp *e2);
int main(void)
{
    struct emp e1[SIZE];

    printf("\n Enter Emp info:: \n");
    AcceptEmp(e1, SIZE);

    printf("\n  Emp info before sort:: \n");
    PrintEmp(e1, SIZE);
    
    SortEmp(e1, SIZE);

    printf("\n  Emp info after sort:: \n");
    PrintEmp(e1, SIZE);
    return 0;
}
void AcceptEmp(struct emp e[], int size)
{
    int index;
    for(index=0; index<size; index++)
    {
        printf("\n Enter emp No :: ");
        scanf("%d", &e[index].empno);
        printf("\n Enter emp name :: ");
        scanf("%s", e[index].name);
        printf("\n Enter  emp sal :: ");
        scanf("%f", &e[index].sal);
        printf("\n Enter doj in DD-MM-YYYY format::");
        scanf("%d%*c%d%*c%d", &e[index].doj.dd, &e[index].doj.mm,&e[index].doj.yy);
    }
    
    return ;
}
void PrintEmp(const struct emp e[], int size)
{
    int index;
    //e->sal=-10000; error
    printf("\nempno    name   sal \n");
    for(index=0;index<size; index++)
        printf("\n%-10d%-12s%-7.3f   %d-%d-%d ", e[index].empno, e[index].name, e[index].sal, e[index].doj.dd,e[index].doj.mm,e[index].doj.yy);
    return;
}

void SortEmp(struct emp e[], int size)
{
    int i,j;
    struct emp temp;
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
           // if(e[i].sal>e[j].sal) //sort asc sal
           // if(e[i].sal<e[j].sal) //sort desc sal
            if(e[i].doj.yy>e[j].doj.yy)
            {
            /*    temp=e[i];
                e[i]=e[j];
                e[j]=temp;*/
                SWAP(e[i], e[j], struct emp);
            }
            else if(e[i].doj.yy==e[j].doj.yy && e[i].doj.mm>e[j].doj.mm)
            {
             /*   temp=e[i];
                e[i]=e[j];
                e[j]=temp;*/
                SWAP(e[i], e[j], struct emp);
            }
            else if(e[i].doj.yy==e[j].doj.yy &&               // SWAP(e[i], e[j], struct emp);
 e[i].doj.mm==e[j].doj.mm && e[i].doj.dd>e[j].doj.dd)
            {
             /*   temp=e[i];
                e[i]=e[j];
                e[j]=temp;*/
               // SWAP(e[i], e[j], struct emp); macro
               swap(&e[i], &e[j]);  // fun
            }
        }
    }
    return;
}

void swap(struct emp *e1, struct emp *e2)
{
    struct emp temp;
    temp=*e1;
    *e1=*e2;
    *e2=temp;
}
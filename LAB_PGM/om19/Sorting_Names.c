#include<stdio.h>
#include<string.h>
#define NO 5
#define LEN 10
int main()
{
    //char names[NO][LEN];
    char temp[LEN];
     char *names[NO]={"sf","fgg","ddd","dd","er"}; // array of char pointer
    // char **name;// pointer to pointer
    int i, j;

    printf("\n Enter students info::\n");
    
    
 for(i=0; i<NO; i++)
    {
        char a[10];
        printf("\n student[%d]", i);
        gets(a);
        names[i]=a;
        printf("\n%s\n",names[i]);
       // scanf("%s", names[i]);
       
    }
    printf("\n  students info before sort::\n");
    for(i=0; i<NO; i++)
    {
        printf("\n names[%d] %-10s [%u]",i,  names[i] , &names[i]);
    }

    for(i=0; i<NO; i++)
    {
        for(j=i+1;j<NO; j++)
        {
            //if(strcmp(names[i], names[j])>0) //asc
            if(strcmp(names[i], names[j])<0)//desc
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }   

    printf("\n  students info after sort::\n");
    for(i=0; i<NO; i++)
    {
        printf("\n names[%d] %-10s [%u]",i,  names[i] , &names[i]);
    }
    //printf("\n sizeof names=%d", sizeof(names));
    return 0;
}
/*
struct emp
{
    int empno;
    char name[10];
    float sal;
    struct date
    {
        int dd, mm, yy;
    }doj;
};
struct emp e[5];  // sort asc of doj
// sort desc of doj
*/


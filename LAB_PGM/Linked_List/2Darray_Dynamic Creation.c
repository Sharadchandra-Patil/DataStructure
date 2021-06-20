//return  10;   int
//return 10.2;  double
//return 10.3f; float
//return 'a';  char
//return "sunbeam" char*

//char* strcpy(char*d, const char *src);
//char* strcat(char*d, const char *src);
//char* strchr(const  char*s,  int key);

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int rows, cols, r,c, **ptr=NULL;

    printf("\n Enter  how many rows u want ::");
    scanf("%d", &rows);
    
    printf("\n Enter  how many cols u want ::");
    scanf("%d", &cols);

    // allocate memory for 2d array
    ptr= (int**)malloc(sizeof(int*)*rows);
    for(r=0; r<rows; r++)
    {
        ptr[r]= (int*)malloc(sizeof(int)*cols);
    }

    printf("\n enter elements of matrix::");
    for(r=0; r<rows; r++)
    {
        for(c=0; c<cols; c++)
        {
            printf("\n pte[%d][%d]", r,c);
            scanf("%d", &ptr[r][c]);
        }
    }

    printf("\nelements of matrix::");
    printf("\n &ptr=%u ptr=%u\n ",&ptr, ptr );
    for(r=0; r<rows; r++)
    {
        printf("\n &ptr[%d]%u ptr[%d]=%u\n\t",r, &ptr[r], r, ptr[r]);
        for(c=0; c<cols; c++)
        {
            printf("%5d [%u]", ptr[r][c], &ptr[r][c]);
        }
        printf("\n");
    }


    for(r=0; r<rows; r++)
    {
        free(ptr[r]);
    }
    free(ptr);
    ptr=NULL;

    
    return 0;
}
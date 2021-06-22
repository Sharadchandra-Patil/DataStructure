#include<stdio.h>
#include<string.h>
#define SIZE 40
int main(void)
{
    char src[SIZE],del;
    int i, j;

    printf("\n Enter string::");
    scanf("%s", src);

    printf("\n Enter char to del :: ");
    scanf("%*c%c", &del);

    i=0;
    while(src[i]!='\0')
    {
        if(src[i]==del)
        {
            j=i;
            while(src[j]!='\0')
            {
                src[j]=src[j+1];
                j++;
            }
            i--;
        }
        i++;
    }
    printf("After deleting %c final string is %s", del, src);

    return 0;
}

// lifo filo
// fifo lilo
#include<stdio.h>
#define SIZE 20
int main(void)
{
    char str[SIZE],delChr;
    int i, j,count=0;

    printf("\nEnter string :: ");
    scanf("%s", str);
    
    printf("Enter char to delete :: ");
    scanf("%*c%c", &delChr);

    i=0;
    while(str[i]!='\0')
    {
      
       if(str[i]!=delChr)
        {
            str[count++]=str[i];
        }
        i++;
    }
    str[count]='\0';
    printf("\nAfter deleting character \'%c\' final string is :: \"%s\"\n\n", delChr, str);

    return 0;
}

// lifo filo
// fifo lilo
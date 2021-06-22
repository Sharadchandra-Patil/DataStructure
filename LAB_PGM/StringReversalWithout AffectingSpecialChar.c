#include<stdio.h>
#include<string.h>
void reverse(char str[]);

int main(void)
{
    char str[10];
    gets(str);
    printf("%s\n",str);
    reverse(str);
    return 0;
}
int length(char str[])
{
    int len;

    for(len = 0; str[len]; len++);

    return len;
}

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

int isAlphabet(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

void reverse(char str[])
{
    int start = 0;
    int end   = length(str) - 1;

    while(start < end)
    {
        if(! isAlphabet(str[start]))
            start++;
        else if(! isAlphabet(str[end]))
            end--;
        else
        {
            swap(&str[start],&str[end]);
            start++;
            end--;
        }
    }
    printf("%s",str);
}

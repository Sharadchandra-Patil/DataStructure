/*  

Please enter name::SHARAD

S H A R A D D A R A H S
S H A R A     A R A H S
S H A R         R A H S
S H A             A H S
S H                 H S
S                     S

*/

#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[10];
	printf("Please enter name::");
	gets(a);
	int len = strlen(a);

	for(int i=len ; i>=1 ; i--)
	{
		for(int j=0 ; j<i ; j++)
		{
			printf("%c ",a[j]);
		}

		for(int k=i; k<len ; k++)
		{
			printf("  ");
		}

		//for(int k=i+1; k<len ; k++)
		for(int k=i ; k<len ; k++)
		{
			printf("  ");
		}

		for(int k=i-1; k>=0 ; k--)
		{
			//if(k==len-1)
			// continue;
			printf("%c ",a[k]);
		}
		printf("\n");
	}
}
#include <stdio.h>
#define SIZE 11

void bubble_sort(int *, int n);

void bubble_sort(int a[], int n)
{
	int i, j, tmp;

	for (j = 1; j < n; j++)
	{

		for (i = 0; i < n-j; i++) 
		{

			if(a[i] > a[i+1])
			{
				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
			}

		}
		printf("%d",j);
		printf("%d",i);
		printf("\n");
	}


}

int main(int argc, char const* argv[])
{
	int bubble[SIZE] = {94,45,15,78,84,51,24,12,2,5,3};

	bubble_sort(bubble,SIZE);

	for (int i = 0; i < SIZE; i++)
	{

		printf("%d\n",bubble[i] );

	}
	
	return 0;
}

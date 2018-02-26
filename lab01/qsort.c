#include <stdio.h>

// Function to print the array.
void display(int *a, int n)
{
	printf("[ ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("]\n");
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void qsort(int *a, int n)
{
	if (n < 2)
		return;
	int pivot = a[0];
	int *left = a;
	int *right = a + n - 1;
	display(a, n);
	while (left <= right)
	{
		if (*left < pivot)
			left++;
		else if (*right > pivot)
			right--;
		else
		{
			swap(left, right);
			left++;
			right--;
		}
	}
	qsort(a, right - a + 1);
	qsort(left, a + n - left);
}
 
int main(int argc, char ** argv)
{
	// initialize array
	int a[] = {65, 2, -31, 0, 99, 2, 83, 782, 1};
	// size, or number of elements, of the array
	// n = 9. 0 - 8
	int n = sizeof(a)/sizeof(a[0]);
	display(a, n);
	qsort(a, n);
	display(a, n);
    return 0;
}
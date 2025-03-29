#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "bubble_sort.h"

int main()
{
	int arr[] = { 3,2,1,4,7,6,8,9,0,5,9,11,57,33,65 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, size);
	for (int k = 0; k < size; k++)
	{
		printf("%d ", arr[k]);
	}
	return 0;
}
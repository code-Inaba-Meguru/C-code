#define _CRT_SECURE_NO_WARNINGS
void bubble_sort(int arr[],int size) 
{
	int box = 0;
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - j - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				box = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = box;
			}
		}
	}
}

#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int *temp, int start, int end)
{
	int begin, middle, middle_next, last, i;
	if(start == end)
		return;
	int mid = (start+end)/2;
	sort(arr, temp, start, mid);
	sort(arr, temp, mid+1, end);
	
	begin = start;
	middle_next = mid+1;
	i = start;
	while((begin <= mid) && (middle_next <= end))
		if(arr[begin] < arr[middle_next])
			temp[i++] = arr[begin++];
		else
			temp[i++] = arr[middle_next++];
	while(begin <= mid)
		temp[i++] = arr[begin++];
	while(middle_next <= end)
		temp[i++] = arr[middle_next++];
	begin = start;
	while(begin <= end)
	{
		arr[begin] = temp[begin];
		begin++;
	}
}

void merge_sort(int *arr, int len)
{
	int start = 0;
	int end = len;
	int i;
	if(len < 2)
	{
		printf("\nNothing to sort");
		return;
	}
		
	int *temp = (int *)malloc(len * sizeof(int));
	sort(arr, temp, 0, len-1);
}

int main()
{
	int i, len;
	//int arr[] = {2,4,1,3,7,6,8,9,5};
	int arr[] = {4,-2};
	//int arr[] = {4};
	//int arr[] = {};
	len = sizeof(arr)/sizeof(int);
	printf("Unsorted array is \n");
	for(i=0; i<len; i++)
		printf("%d\t", arr[i]);
	merge_sort(arr, len);
	printf("\nSorted array is \n");
	for(i=0; i<len; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	return 0;
}

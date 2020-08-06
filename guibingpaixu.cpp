#include<stdio.h>
#define ArrLen 20
void printList(int arr[], int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d\t", arr[i]);
	}
}
void merge(int arr[], int start, int mid, int end) {
	int result[ArrLen];
	int k = 0;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) {
			result[k++] = arr[i++];
		}
		else {
			result[k++] = arr[j++];
		}
	}
	if (i == mid + 1) {
		while (j <= end)
			result[k++] = arr[j++];
	}
	if (j == end + 1) {
		while (i <= mid)
			result[k++] = arr[i++];
	}
	for (j = 0, i = start; j < k; i++, j++) {
		arr[i] = result[j];
	}
}

void mergeSort(int arr[], int start, int end) {
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}
void hebing(int arr[], int start,int mid, int end)
{
	int result[20] = { 0 };
	int k = 0;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
		{
			result[k++] = arr[i++];
		}
		else
		{
			result[k++] = arr[j++];
		}
	}
	if (i == mid + 1)
	{
		while (j < end)
		{
			result[k++] = arr[j++];
		}
	}
	if (j == end)
	{
		while (i < mid + 1)
		{
			result[k++] = arr[i++];
		}
	}
	for (j = 0, i = start; j < k; i++, j++) {
		arr[i] = result[j];
	}
	
}
void mergeSort_1(int arr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int num = (end + start) / 2;
	mergeSort_1(arr, start, num );
	mergeSort_1(arr, num + 1, end);
	hebing(arr, start, num, end);
}


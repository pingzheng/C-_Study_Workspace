#include <iostream>
#include "method.h"
using namespace std;
int main()
{
	//������
	//�������������򲻶�
	
		int array[] = { 49,38,65,97,76,13,27,49,10 };
		//int array[] = { 59,25,17,36,98,14,23,83,13,28 };
		int size = sizeof(array) / sizeof(int);
		//printf("%d \n", size);
		//mergeSort(array, 0, size-1);
		//RadixSort1(array, size);//��������
		//select_sort(array, size);
		//erchashupaixu(array, size);
		//maopao_1(array, size);
		//charu_1(array, size);
		mergeSort_1(array, 0, size);
		//bucket_sort_1(array, size,size+1);
		//heapSort(array, size);
		display(array, size);
		//bucket_sort(array, size,size+1);
		//charu(array, size);
		//maopao(array, size);
		//QuickSort(array, 0, size - 1);
		//display(array, size);

		// int size = 20;
		// int array[20] = { 0 };					//�����ʼ�� 
		// for (int i = 0; i < 10; i++) {			//�������
		// 	for (int j = 0; j < size; j++) {	//�����С
		// 		array[j] = rand() % 1000;		//�����������С 0~99
		// 	}
		// 	printf("ԭ�������飺");
		// 	display(array, size);
		// 	
		// 	printf("��������飺");
		// 	display(array, size);
		// 	printf("\n");
		// }

	system("pause");
	return 0;
}
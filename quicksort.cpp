
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int getStandard(int array[], int i, int j) {
	//��׼���� 
	int key = array[i];
	while (i < j) {
		//��ΪĬ�ϻ�׼�Ǵ���߿�ʼ�����Դ��ұ߿�ʼ�Ƚ� 
		//����β��Ԫ�ش��ڵ��ڻ�׼���� ʱ,��һֱ��ǰŲ�� j ָ�� 
		while (i < j && array[j] >= key) {
			j--;
		}
		//���ҵ��� array[i] С��ʱ���ͰѺ����ֵ array[j] ������ 
		if (i < j) {
			array[i] = array[j];
		}
		//������Ԫ��С�ڵ��ڻ�׼���� ʱ,��һֱ���Ų�� i ָ�� 
		while (i < j && array[i] <= key) {
			i++;
		}
		//���ҵ��� array[j] ���ʱ���Ͱ�ǰ���ֵ array[i] ������
		if (i < j) {
			array[j] = array[i];
		}
	}
	//����ѭ��ʱ i �� j ���,��ʱ�� i �� j ���� key ����ȷ����λ��
	//�ѻ�׼���ݸ�����ȷλ�� 
	array[i] = key;
	return i;
}

void QuickSort(int array[], int low, int high) {
	//��ʼĬ�ϻ�׼Ϊ low
	if (low < high) {
		//�ֶ�λ���±� 
		int standard = getStandard(array, low, high);
		//�ݹ��������
		//������� 
		QuickSort(array, low, standard - 1);
		//�ұ����� 
		QuickSort(array, standard + 1, high);
	}
}

// �ϲ���һ���������
// void QuickSort(int array[], int low, int high) {
// 	int i = low;
// 	int j = high;  4008285656
// 	int key = array[i];
// 	if (low < high) {
// 		while (i < j) {
// 			while (i < j && array[j] >= key) {
// 				j--;
// 			}
// 			if (i < j) {
// 				array[i] = array[j];
// 			}
// 			while (i < j && array[i] <= key) {
// 				i++;
// 			}
// 			if (i < j) {
// 				array[j] = array[i];
// 			}
// 		}
// 		array[i] = key;
// 		int standard = i;
// 		QuickSort(array, low, standard - 1);
// 		QuickSort(array, standard + 1, high);
// 	}
// }

void display(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int getStandard1(int array[], int i, int j)
{
	int temp = array[i];
	while (i < j)
	{
		while (i < j && array[j] >= temp)
		{
			j--;
		}
		array[i] = array[j];
		while (i < j && array[i] <= temp)
		{
			i++;
		}
		array[j] = array[i];
	}
	array[i] = temp;
	return i;
}



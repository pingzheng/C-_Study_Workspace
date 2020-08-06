#include <stdio.h>

void swap(int array[], int x, int y) {
	int key;
	key = array[x];
	array[x] = array[y];
	array[y] = key;
}

//�Ӵ�С���� 
//void Down(int array[],int i,int n){
//	int child=2*i+1;
//	int key=array[i];
//	while (child<n){
//		if (array[child]>array[child+1] && child+1<n) {
//			child++;
//		}
//		if (key>array[child]){
//			swap(array, i, child);
//			i=child;
//		}
//		else{
//			break;
//		}
//		child=child*2+1;
//	}
//}

//��С��������
void Down(int array[], int i, int n) {						//��������Ǵ󶥶� 
	int parent = i;										//���ڵ��±�
	int child = 2 * i + 1;									//�ӽڵ��±�  
	while (child < n) {
		if (array[child] < array[child + 1] && child + 1 < n) {	//�ж��ӽڵ��Ǹ��󣬴���븸�ڵ�Ƚ� 
			child++;
		}

		if (array[parent] < array[child]) {				//�жϸ��ڵ��Ƿ�С���ӽڵ� 
			swap(array, parent, child);					//�������ڵ���ӽڵ� 
			parent = child;								//�ӽڵ��±� ���� ���ڵ��±� 
		}

		child = child * 2 + 1;								//���У��Ƚ�����ĸ��ڵ���ӽڵ� 
	}
}

void BuildHeap(int array[], int size)
{
	int i = 0;												//�����ڶ��ſ�ʼ 
	for (i = size / 2 - 1; i >= 0; i--) {							//�����󶥶ѣ�����������ϱȽ� 
		Down(array, i, size);								//�����еĲ����ϴ󶥶Ѷ��� 
	}
}

void heapSort(int array[], int size) {
	BuildHeap(array, size);								//��ʼ���� 
	printf("��ʼ�����飺");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	for (int i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);								//��������͵� i ������ 
		//��Ϊֻ��array[0]�ı䣬���������ϴ󶥶ѵĶ��壬���Կ��Դ����������½��� 
		Down(array, 0, i);								//���½����󶥶� 

		printf("��������飺");
		for (int i = 0; i < size; i++) {
			printf("%d ", array[i]);
		}
		printf("\n");
	}
}

void testduipaixu() {
	int array[] = { 49,38,65,97,76,13,27,49,10 };
	int size = sizeof(array) / sizeof(int);
	printf("%d \n", size);
	printf("����ǰ���飺");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	heapSort(array, size);

	return ;
}

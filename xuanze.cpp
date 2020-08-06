#include "method.h"
#include <iostream>

using namespace std; 
void select_sort(int* a, int length)
{
	int i, j, temp, min, pos;
	for (i = 0; i <= length - 1; i++)
	{
		min = a[i];
		for (j = i; j <= length - 1; j++)
			if (a[j] < min) {
				min = a[j];
				pos = j;//记录最小元素的位置 
				//交换最小元素和第一个元素 
				temp = a[i];
				a[i] = a[pos];
				a[pos] = temp;
			}
	}
}

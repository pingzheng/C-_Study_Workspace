#include "method.h"
#include <iostream>

using namespace std;
void shell(int array[], int size)
{
	int number = size / 2;
	int i = 0;
	int j = 0;
	int temp = 0;
	int sum1 = 0;
	int sum2 = 0;
	/*while (number >= 1)
	{
		for (i = 0; i < number; i++)
		{
			sum1++;
			if (array[i] > array[i + number])
			{
				temp = array[i + number];
				array[i + number] = array[i];
				array[i] = temp;
				sum2++;
			}
		}
		number = number / 2;
	}*/
	while (number >= 1)
	{
		for (i = number; i < size; i++)
		{
			sum1++;
			temp = array[i];
			j = i - number;
			while (j >= 0 && array[j] > temp)
			{
				array[j + number] = array[j];
				j = j - number;
				sum2++;
			}
			array[j + number] = temp;
		}
		number = number / 2;
	}
	display(array, size);
}
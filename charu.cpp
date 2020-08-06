#include "method.h"
#include <iostream>

using namespace std;
void charu(int array[], int size)
{
	display(array, size);
	int temp = array[0];
	int i = 0;
	int j = 0;
	for (i = 1; i < size; i++)
	{
		temp = array[i];
		for (j = i-1; j >=0; j--)
		{			
			if (temp < array[j])
			{
				array[j + 1] = array[j];
				array[j ] = temp;
			}			
		}
		
	}
	display(array, size);
}
void charu_1(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}
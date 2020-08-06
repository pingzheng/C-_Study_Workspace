#include "method.h"
#include <iostream>

using namespace std;
void maopao(int array[], int n)
{
	int temp = array[0];
	for (int i = 0; i < n; i++)
	{
		temp = array[i];
		for (int j = i + 1; j < n; j++)
		{
			if (array[j] < temp)
			{
				array[i] = array[j];
				array[j] = temp;
				temp = array[i];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
void maopao_1(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int temp = array[i];
			if (array[i] > array[j])
			{
				array[i] = array[j];
				array[j] = temp;
				temp = array[i];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
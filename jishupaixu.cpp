#include "method.h"
#include <iostream>

using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LENGTH 10

int GetMaxWidth(int* arr, int len)//�õ����ݵ������
{
    int max = arr[0];
    for (int i = 0; i < len; ++i)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    int width = 0;
    while (max > 0)
    {
        width++;
        max /= 10;
    }
    return width;
}

typedef struct Que  //����
{
    int* data;
    int head;
    int tail;
}Que;
int GetNumOfData(int data, int width)
{
    int num = data % 10;//��10ȡ��  
    while (width)  //��ʼwidth==0,��ʾȡ��λ��ֵ������ѭ����ֱ�ӷ���num
    {
        data /= 10;
        width--;
        num = data % 10;
    }
    return num;
}

void RadixSort(int* arr, int len)
{
    //��ȡ������ֵ�λ��
    int width = GetMaxWidth(arr, len);
    Que que[10];
    for (int i = 0; i < 10; ++i)  //��ʼ��ʮ������
    {
        que[i].data = (int*)malloc(sizeof(int) * len);
        que[i].head = que[i].tail = 0;
    }
    //i=0;��λ  i=1;ʮλ  i=2;��λ   i=3;ǧλ
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < len; ++j)//������
        {
            int num = GetNumOfData(arr[j], i);
            que[num].data[que[num].tail++] = arr[j];
        }
        int count = 0;
        for (int i = 0; i < 10; ++i)//���ݳ����н���arr��
        {
            while (que[i].head != que[i].tail)//������
            {
                arr[count++] = que[i].data[que[i].head++];
            }
            que[i].head = que[i].tail = 0;//���г�ʼ����Ϊ��һ�η�������׼��
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        free(que[i].data);
    }
}
void ShowData(int* arr)
{
    for (int i = 0; i < LENGTH; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void RadixSort1(int* arr, int len)
{
    display(arr, len);
    int width = GetMaxWidth(arr, len);
    int qNum[10] = { 0 };
    int tWidth = 0;
    int *pArray = new int[len];

    while (tWidth <width)
    {   
        
        for (int i = 0; i < 10; i++)
        {
            qNum[i] = 0;
        }
        display(qNum, 10);
        for (int i = 0; i < len; i++)
        {
            int t = GetNumOfData(arr[i], tWidth);
            qNum[t]++;
        }
        for (int i = 0; i < 9; i++)
        {
            qNum[i + 1] = qNum[i] + qNum[i + 1];
        }
        display(qNum, 10);
        for (int j = len - 1; j >= 0; j--)
        {
            int t = GetNumOfData(arr[j], tWidth);
            qNum[t]--;
            pArray[qNum[t]] = arr[j];
        }
        for (int i = 0; i < len; i++)
        {
            arr[i] = pArray[i];
        }
        display(pArray, len);
        tWidth++;
    }
    display(pArray, len);
    delete[]pArray;
}
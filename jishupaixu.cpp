#include "method.h"
#include <iostream>

using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LENGTH 10

int GetMaxWidth(int* arr, int len)//得到数据的最大宽度
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

typedef struct Que  //队列
{
    int* data;
    int head;
    int tail;
}Que;
int GetNumOfData(int data, int width)
{
    int num = data % 10;//对10取余  
    while (width)  //初始width==0,表示取个位的值，不进循环，直接返回num
    {
        data /= 10;
        width--;
        num = data % 10;
    }
    return num;
}

void RadixSort(int* arr, int len)
{
    //获取最大数字的位数
    int width = GetMaxWidth(arr, len);
    Que que[10];
    for (int i = 0; i < 10; ++i)  //初始化十个队列
    {
        que[i].data = (int*)malloc(sizeof(int) * len);
        que[i].head = que[i].tail = 0;
    }
    //i=0;个位  i=1;十位  i=2;百位   i=3;千位
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < len; ++j)//进队列
        {
            int num = GetNumOfData(arr[j], i);
            que[num].data[que[num].tail++] = arr[j];
        }
        int count = 0;
        for (int i = 0; i < 10; ++i)//数据出队列进入arr中
        {
            while (que[i].head != que[i].tail)//有数据
            {
                arr[count++] = que[i].data[que[i].head++];
            }
            que[i].head = que[i].tail = 0;//队列初始化，为下一次放数据做准备
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
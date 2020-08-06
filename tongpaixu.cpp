#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;

typedef struct node {
	int key;
	struct node* next;
}KeyNode;

void bucket_sort(int keys[], int size, int bucket_size) {
	int i, j;
	KeyNode** bucket_table = (KeyNode**)malloc(bucket_size * sizeof(KeyNode*));
	for (i = 0; i < bucket_size; i++) {
		bucket_table[i] = (KeyNode*)malloc(sizeof(KeyNode));
		bucket_table[i]->key = 0;
		bucket_table[i]->next = NULL;
	}
	for (j = 0; j < size; j++) {
		KeyNode* node = (KeyNode*)malloc(sizeof(KeyNode));
		node->key = keys[j];
		node->next = NULL;
		int index = keys[j] / 10;
		KeyNode* p = bucket_table[index];
		if (p->key == 0) {
			bucket_table[index]->next = node;
			(bucket_table[index]->key)++;
		}
		else {
			while (p->next != NULL && p->next->key <= node->key)
				p = p->next;
			node->next = p->next;
			p->next = node;
			(bucket_table[index]->key)++;
		}
	}
	//print result
	KeyNode* k = NULL;
	for (i = 0; i < bucket_size; i++)
		for (k = bucket_table[i]->next; k != NULL; k = k->next)
			printf("%d ", k->key);
	printf("\n");
}


void bucket_sort_1(int keys[], int size, int bucket_size)
{
	int max = keys[0];
	int min = keys[0];
	for (int i = 0; i < size; i++)
	{
		if (keys[i] > max)
		{
			max = keys[i];
		}
		if (keys[i] < min)
		{
			min = keys[i];
		}
	}
	int tong = (max - min) / size+1;
	set<int>* v_num = new set<int>[tong];
	for (int i = 0; i < size; i++)
	{
		int num2 = (keys[i] - min) / tong;
		v_num[num2].insert(keys[i]);
	}
	int num3 = 0;
	for (int i = 0; i < tong; i++)
	{
		while (v_num[i].size() > 0)
		{
			keys[num3] = *(v_num[i].begin());
			v_num[i].erase(v_num[i].begin());
			num3++;
		}
	}
	

}
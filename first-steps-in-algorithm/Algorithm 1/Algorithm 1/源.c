#define _CRT_SECURE_NO_WARNINGS
//
//int main(void)
//{
//
//	int arr[10] = { 0 };
//	int num = 0;
//	//����
//	int i = 0;
//	for (i = 0; i <= 9; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	scanf("%d", &num);
//	//�Ƚ�
//	int count = 0;
//	for (i = 0; i <= 9; i++)
//	{
//		if (num + 30 >= arr[i])
//			count++;
//	}
//	//���
//	printf("%d", count);
//
//
//	return 0;
//}
//#include<stdio.h>
//int main(void)
//{
//	int road[10000] = { 0 };//����ʼ��Ϊ0
//	int length;
//	typedef struct district {
//		int start;
//		int end;
//	}D;
//	D arr2[100] = {};
//	int num = 0;
//
//	//����
//
//	scanf("%d%d", &length,&num);
//
//	int i = 0;
//	for (i = 0; i <= num - 1; i++)
//	{
//		scanf("%d%d", &arr2[i].start, &arr2[i].end);
//	}
//
//	//��ż���
//	for (i = 0; i <= num - 1; i++)
//	{
//		int j;
//		for (j = arr2[i].start; j <= arr2[i].end; j++)
//		{
//			road[j] -= 1;
//		}
//	}
//
//	//����road
//	int count = 0;
//	for (i = 0; i <= length; i++)
//	{
//		if (road[i] < 0)
//			count++;
//	}
//
//	printf("%d", length - count+1);
//
//
//
//	return 0;
//}
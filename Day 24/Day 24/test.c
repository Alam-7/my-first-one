#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>






//Pratice 1
//int main(void)
//{
//	int n = 0;
//	do
//	{
//		printf("%d ", n);
//		n += 1;
//	} while (n <= 9);
//
//
//
//	return 0;
//}

//Pratice 2
//int main(void)
//{
//    int amount, next, total, i;
//    printf("This program adds certain numbers.\n");
//    printf("Enter the amount to be added:");
//    scanf("%d", &amount);
//    total = 0;//��ʼ��
//    printf("please input number ? ");
//    scanf("%d", &next);
//    total += next;
//    for (i=1;i<amount ;i++ ) 
//    {
//        printf("next number ? ");
//        scanf("%d", &next);//�������ڴ˴�����
//        total += next;//�ۼ�
//    }
//    printf("The total is %d.\n", total);//������
//    return 0;
//}

//

//Pratice 3
//int main(void) 
//{
//	int next, total;
//	printf("This program adds indeterminate numbers.\n");
//	printf("1st number? ");
//	scanf("%d", &total);
//	printf("next number?(enter '0' to stop) ");
//	scanf("%d", &next);
//	for (;next!=0;)
//	{
//		total = total + next;
//		printf("next number ?(enter '0' to stop) ");
//		scanf("%d", &next);
//	}
//	printf("The total is %d.\n", total);
//	return 0;
//}
///*printf("next number?(enter '0' to stop)");
//scanf("%d", &next);
//while (next != 0)
//{
//	total = total + next;
//	printf("next number ?(enter '0' to stop)");
//	scanf("%d", &next);
//}*/




//Pratice 4
// 
//*�ȱ������Ρ�������������������By DS__
/**
 * @file equilateral_triangle.c
 * @brief ��ӡ���Ǻ���ɵĵȱ������Σ�ÿ���߰���8���Ǻ�
 */

#include <stdio.h>

 /**
  * @brief ��ӡ�ȱ�������
  *
  * �ú���ͨ��Ƕ��ѭ����ӡһ���ȱ������Σ����У�
  *   - ������Ϊ8�У���Ӧÿ����8���Ǻţ�
  *   - ��i�а�����
  *       1. ǰ���ո��� = 7 - i��ʵ�־��ж��룩
  *       2. �Ǻ�����  = 2*i + 1���������������壩
  */
//void print_equilateral_triangle() 
//{
//	int num_rows = 8; // ������������ÿ�����Ǻ�����
//
//	// ���ѭ����������
//	for (int i = 0; i < num_rows; i++) {
//		// ��ӡǰ���ո񣨾��ж��룩
//		for (int j = 0; j < num_rows - i - 1; j++) {
//			printf(" ");
//		}
//
//		// ��ӡ��ǰ���Ǻ�
//		for (int k = 0; k < 2 * i + 1; k++) {
//			printf("*");
//		}
//
//		// ���н�����һ��
//		printf("\n");
//	}
//}
//
///**
// * @brief �������
// * @return int �����˳�״̬�루0��ʾ�ɹ���
// */
//int main()
//{
//	// ���ú�����ӡ������
//	print_equilateral_triangle();
//	return 0;
//}



//Pratice 5
//N�Ľ׳�
//int Factorial_N(int n)
//{
//	int i;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}//ѭ���۳�
//	return ret;
//}
//
//
//int main(void)
//{
//	int num = 0;
//	while (scanf("%d", &num) != EOF)//ѭ������
//	{
//		/*printf("\n");*/
//		printf("num!=%d\n", Factorial_N(num));//�׳˺���
//	}
//	return 0;

//}

//int main(void)
//{
//	float a, b;
//	b = 2.0e20 + 1.0;
//	a = b - 2.0e20;
//	printf("%f\n", a);
//
//
//	return 0;
//}



//int main(void)
//{
//
//	float salary;
//
//	printf("����������Ҫ����н�� ");
//	printf("$______\b\b\b\b\b\b");
//	scanf("%f", &salary);
//	printf("\n\t$%.2f a month is %.2f a year",salary,salary*12.0);
//	printf("\rNice!");
//
//
//
//	return 0;
//}


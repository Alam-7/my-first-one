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
//    total = 0;//初始化
//    printf("please input number ? ");
//    scanf("%d", &next);
//    total += next;
//    for (i=1;i<amount ;i++ ) 
//    {
//        printf("next number ? ");
//        scanf("%d", &next);//加数均在此处输入
//        total += next;//累加
//    }
//    printf("The total is %d.\n", total);//输出结果
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
//*等边三角形——————————By DS__
/**
 * @file equilateral_triangle.c
 * @brief 打印由星号组成的等边三角形，每条边包含8个星号
 */

#include <stdio.h>

 /**
  * @brief 打印等边三角形
  *
  * 该函数通过嵌套循环打印一个等边三角形，其中：
  *   - 总行数为8行（对应每条边8个星号）
  *   - 第i行包含：
  *       1. 前导空格数 = 7 - i（实现居中对齐）
  *       2. 星号数量  = 2*i + 1（构成三角形主体）
  */
//void print_equilateral_triangle() 
//{
//	int num_rows = 8; // 三角形行数（每条边星号数）
//
//	// 外层循环控制行数
//	for (int i = 0; i < num_rows; i++) {
//		// 打印前导空格（居中对齐）
//		for (int j = 0; j < num_rows - i - 1; j++) {
//			printf(" ");
//		}
//
//		// 打印当前行星号
//		for (int k = 0; k < 2 * i + 1; k++) {
//			printf("*");
//		}
//
//		// 换行进入下一行
//		printf("\n");
//	}
//}
//
///**
// * @brief 程序入口
// * @return int 程序退出状态码（0表示成功）
// */
//int main()
//{
//	// 调用函数打印三角形
//	print_equilateral_triangle();
//	return 0;
//}



//Pratice 5
//N的阶乘
//int Factorial_N(int n)
//{
//	int i;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}//循环累乘
//	return ret;
//}
//
//
//int main(void)
//{
//	int num = 0;
//	while (scanf("%d", &num) != EOF)//循环输入
//	{
//		/*printf("\n");*/
//		printf("num!=%d\n", Factorial_N(num));//阶乘函数
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
//	printf("请输入您想要的月薪： ");
//	printf("$______\b\b\b\b\b\b");
//	scanf("%f", &salary);
//	printf("\n\t$%.2f a month is %.2f a year",salary,salary*12.0);
//	printf("\rNice!");
//
//
//
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//Printf的相关输出功能及占位符的结合使用
//%d整数 %s字符串 %f小数  %c字符  %zd size_t类型   （双%%可保留一个%  %后跟数字可限定最小位数且默认右对齐，在左侧添加空格，%-5d即可左对齐，在右侧添加空格    %+可使正数始终保留正号）
//int main()
//{
//	//printf("%f\n", 123.456);//小数部分默认六位
	//printf("%15f\n", 123.456);
	//printf("%%d\n");
	
//小数位数的限定
	//printf("%f\n", 0.5);
	//printf("%.2f\n", 0.5);
	//printf("%.3f", 3.1415926);//四舍五入限定前n位
	//printf("%5.2f\n", 0.5);//占位符和位数限定的结合使用
	//printf("%*.*f\n",5,2, 0.5);//*的代替作用
	
	//字符串的限定输出
	/*printf("%.3s","abcdef");*/
	/*return 0;
}*/

//scanf的使用
//int main()
//{
//	int score = 0;//初始化
//	printf("请输入成绩:");//输出
//	scanf("%d", &score);//等待输入   （&为取地址符号，必须加，除了指针变量    %d后不能加\n否则出问题）
//	printf("您的成绩是:%d\n", score);//再次输出
//
//	return 0;
//}
//scanf的连续使用（1.不能使用\n  2.自动忽略空格等无意义空白，错误匹配#等其他符号   3.一次输入，连续读取，先放置缓存区，在不符合数据类型处停止，且下次从此处开始）
//int main()
//{
	/*int i = 0;
	int j = 0;
	float x = 0.0;
	float y = 0.0;
	 
	scanf("%d%d%f%f", &i, &j, &x, &y);
	printf("%d %d %f %f\n",i,j,x,y);*/


	//scanf的工作原理（代码结果计算）
	//int x = 0;
	//float y = 0.0;
	//scanf("%d%f", &x, &y);//-13.45e13#*
	//printf("%d\n%f\n", x, y);

	//scanf的返回值   三次ctrl+z返回EOF（-1）终止程序   错误匹配（遇到不符合指定数据类型的值或字符）时同样结束并返回先前已匹配的值，其他按照初始值输出
	//int a = 0;
	//int r=scanf("%d", &a);
	//printf("%d\n", a);
	//printf("r=%d", r);//r表示scanf输入值的个数


//scanf的占位符与printf大致相同如%c %d %f %lf %Lf %s但仍需注意：
//1.%c本身就读取字符（包括空格）所以其不忽略空格 如想忽略，在%c前加上空格即可 如 %c
//2.浮点数在printf中对float double不加区分 但在scanf中必须一一对应  float--%f  double--%lf  long double--%Lf
//3.%s存储的字符串末尾自动携带\0作为终止子（注意空间）

	//scanf不安全 要求输入几个就输入几个，直至遇到空格或错误匹配，可能导致内存崩盘等问题（较为强横）
	//int main()
	//{
	//	char arr[5] = { 0 };
	//	//scanf("%s", arr);//数组名arr本身即为地址（不是变量）   但凡字符串其末尾必有结束字符\0
	//	scanf("%4s", arr);//自动在第四位时终止读取（有一个末尾\0占位）
	//	printf("%s\n", arr);
	//	return 0;
	//}



//赋值忽略符*
int main()
{
	int year = 0;
	int month = 0;
	int day = 0;
	scanf("%d%*c%d%*c%d", &year, &month, &day);//%*d之类在在占位符中间插入*的数据将在读取后便丢弃
	printf("%d %d %d", year, month, day);



	return 0;
}








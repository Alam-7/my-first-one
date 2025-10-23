#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//If语句
//int main()
//{
//	int num = 0;//初始化
//	scanf("%d", &num);//输入
//	if (num % 2 == 1)//if判断（if与其后所连语句整体作为一个语句）
//		printf("%d为奇数\n",num);//输出（双引号之内语句不做任何计算处理，引号后做输出或判断处理）
//	else
//		printf("%d为偶数\n",num);
//
//	return 0;
//}//没有循环程序，无法持续执行
// 
//练习
//int main()
//{
//	int age = 0;
//	printf("请输入您的年龄:");
//	scanf("%d", &age);
//	if (age >= 18)
//		printf("成年\n");
//	else
//		printf("未成年\n");
//
//	return 0;
//}

//多重语句时一般带上大括号{}

////嵌套if
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if (num >0)
//		printf("正数\n");
//	else
//	{
//		if (num < 0)
//			printf("负数\n");
//		else
//			printf("0\n");
//	}
//
//	return 0;
///}//太复杂
//化简版：
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if (num > 0)
//		printf("正数\n");
//	else if (num < 0)//else if连用
//			printf("负数\n");
//    else
//			printf("0\n");
//
//	return 0;
//}//if else可作为一个程序块在所需要的地方添加

//例：多重if嵌套
//int main()
//{
//	int age = 0;//初始化
//	printf("请输入您的年龄:");
//	scanf("%d", &age);//输入
//	if (age < 18)
//		printf("少年");
//	else if (age < 44)
//		printf("青年");
//	else if (age < 59)
//		printf("中年");
//	else if (age < 80)
//		printf("老年");
//	else
//		printf("大寿星");
//	return 0;
//}
//悬空else问题：else遵循就近原则，与最近的if匹配

//=表示赋值  ==表示判断相等
//int main()
//{
//	int a = 2;
//	//if (a = 2)//仍能通过，有bug
//	if(2=a)//少写=会直接报错，避免bug
//		printf("hh\n");
//
//	return 0;
//}//建议判断相等时，一般把常量置于左侧

//返回值：0为假  1为真 
//int a =3   （3==a)的返回值即为1

//关系操作符不宜连用  如下常见错误
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c =1;
//	if (a < b==c)//程序首先运行a<b为真并返回值1，此后判断1==c并返回值1为真，打印hh（程序的运行逻辑可能和自己所以为的不一样，要关注程序的逐步运行逻辑）
//		printf("hh\n");
//	else
//		printf("haha\n");
//	return 0;
//}//补救：应改为&&同时成立符号，分隔开判断符

//条件操作符（化简版的if else语句）
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int m = 0;
//	scanf("%d%d", &a, &b);
//	m = (a > b ? a:b);//为真第一个，为假第二个
//	printf("%d\n", m);
//
//	return 0;
//}

//逻辑运算符：！取反   &&并且  ||或者(在表达式前加！表示相反含义 真变假）
//闰年的判断：
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		printf("闰年\n");
//	return 0;
//}

//*****短路运算（程序由左向右按照优先级运行，当运行结果已经能决定最终结果时，停止运行后续程序）
//int main()
//{
//	int a = 0, b = 1, c = 3, d = 4,i=0;
//	i = a++ && b++ && ++d;//赋值=的优先级很低，先考虑右侧表达式，运算的数值为0还是非0即表示真假，真赋值1，假赋值0，短路后侧表达式不参与计算
////	i = a++ || b++ || ++d;
//		printf("%d %d %d %d %d", a, b, c, d, i);
//
//	return 0;
//}

////switch语句（多重if else语句的代替）  选择分支逻辑   switch,case,default
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	switch (a)//switch表达式必须是整型表达式   case后必须是常量整型（可以是字符）
//	{
//	case 1://case仅仅决定程序从何处进入，break决定程序的结束，否则程序持续向下进行，case不做判断
//	case 2://case与其后的常量必须有空格
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日\n");
//		break;//break单独作为结束语句
//	case 6:
//	case 7:
//		printf("休息日\n");
//			break;
//	default://default是默认，当不满足其他情况时进行，可放置于开头或结尾，且case和default后均需加上：并与后续程序组成语句
//		printf("输入错误\n");
//		break;
//
//	}
//
//
//	return 0;
//}


//while循环

int main()
{
	int num = 0;
	scanf("%d", &num);
	do
	{
		printf("%d\n", num % 10);
	}while (num);
	{
		num /= 10;
	}
	
	return 0;
}

//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	for (num; num;num/=10)
//	{
//		printf("%d\n", num % 10);
//	}
//	return 0;
//}

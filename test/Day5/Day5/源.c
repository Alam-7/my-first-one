#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//If���
//int main()
//{
//	int num = 0;//��ʼ��
//	scanf("%d", &num);//����
//	if (num % 2 == 1)//if�жϣ�if������������������Ϊһ����䣩
//		printf("%dΪ����\n",num);//�����˫����֮����䲻���κμ��㴦�����ź���������жϴ���
//	else
//		printf("%dΪż��\n",num);
//
//	return 0;
//}//û��ѭ�������޷�����ִ��
// 
//��ϰ
//int main()
//{
//	int age = 0;
//	printf("��������������:");
//	scanf("%d", &age);
//	if (age >= 18)
//		printf("����\n");
//	else
//		printf("δ����\n");
//
//	return 0;
//}

//�������ʱһ����ϴ�����{}

////Ƕ��if
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if (num >0)
//		printf("����\n");
//	else
//	{
//		if (num < 0)
//			printf("����\n");
//		else
//			printf("0\n");
//	}
//
//	return 0;
///}//̫����
//����棺
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if (num > 0)
//		printf("����\n");
//	else if (num < 0)//else if����
//			printf("����\n");
//    else
//			printf("0\n");
//
//	return 0;
//}//if else����Ϊһ�������������Ҫ�ĵط����

//��������ifǶ��
//int main()
//{
//	int age = 0;//��ʼ��
//	printf("��������������:");
//	scanf("%d", &age);//����
//	if (age < 18)
//		printf("����");
//	else if (age < 44)
//		printf("����");
//	else if (age < 59)
//		printf("����");
//	else if (age < 80)
//		printf("����");
//	else
//		printf("������");
//	return 0;
//}
//����else���⣺else��ѭ�ͽ�ԭ���������ifƥ��

//=��ʾ��ֵ  ==��ʾ�ж����
//int main()
//{
//	int a = 2;
//	//if (a = 2)//����ͨ������bug
//	if(2=a)//��д=��ֱ�ӱ�������bug
//		printf("hh\n");
//
//	return 0;
//}//�����ж����ʱ��һ��ѳ����������

//����ֵ��0Ϊ��  1Ϊ�� 
//int a =3   ��3==a)�ķ���ֵ��Ϊ1

//��ϵ��������������  ���³�������
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c =1;
//	if (a < b==c)//������������a<bΪ�沢����ֵ1���˺��ж�1==c������ֵ1Ϊ�棬��ӡhh������������߼����ܺ��Լ�����Ϊ�Ĳ�һ����Ҫ��ע������������߼���
//		printf("hh\n");
//	else
//		printf("haha\n");
//	return 0;
//}//���ȣ�Ӧ��Ϊ&&ͬʱ�������ţ��ָ����жϷ�

//������������������if else��䣩
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int m = 0;
//	scanf("%d%d", &a, &b);
//	m = (a > b ? a:b);//Ϊ���һ����Ϊ�ٵڶ���
//	printf("%d\n", m);
//
//	return 0;
//}

//�߼����������ȡ��   &&����  ||����(�ڱ��ʽǰ�ӣ���ʾ�෴���� ���٣�
//������жϣ�
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		printf("����\n");
//	return 0;
//}

//*****��·���㣨�����������Ұ������ȼ����У������н���Ѿ��ܾ������ս��ʱ��ֹͣ���к�������
//int main()
//{
//	int a = 0, b = 1, c = 3, d = 4,i=0;
//	i = a++ && b++ && ++d;//��ֵ=�����ȼ��ܵͣ��ȿ����Ҳ���ʽ���������ֵΪ0���Ƿ�0����ʾ��٣��渳ֵ1���ٸ�ֵ0����·�����ʽ���������
////	i = a++ || b++ || ++d;
//		printf("%d %d %d %d %d", a, b, c, d, i);
//
//	return 0;
//}

////switch��䣨����if else���Ĵ��棩  ѡ���֧�߼�   switch,case,default
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	switch (a)//switch���ʽ���������ͱ��ʽ   case������ǳ������ͣ��������ַ���
//	{
//	case 1://case������������Ӻδ����룬break��������Ľ������������������½��У�case�����ж�
//	case 2://case�����ĳ��������пո�
//	case 3:
//	case 4:
//	case 5:
//		printf("������\n");
//		break;//break������Ϊ�������
//	case 6:
//	case 7:
//		printf("��Ϣ��\n");
//			break;
//	default://default��Ĭ�ϣ����������������ʱ���У��ɷ����ڿ�ͷ���β����case��default�������ϣ������������������
//		printf("�������\n");
//		break;
//
//	}
//
//
//	return 0;
//}


//whileѭ��

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

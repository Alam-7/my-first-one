//头文件包含
#include"Lab4.h"

//声明背景图全局变量
PIMAGE background = nullptr;


//画板的初始化操作
void initial(int width, int height, int bgc) {
	//bgc参数暂时未定 最后一起调整画板颜色
	initgraph(width, height);
	setfont(20, 0, "楷体");
	setbkmode(TRANSPARENT);

	//创建一个背景缓冲区 便于更新文字样式
	if (!background) background = newimage();
	getimage(background, 0, 0, getwidth(), getheight());

}


//封装出来一个画板模块
void enterDraw(void) {
	while (1)
	{

		int mune = 0;
		cleardevice();

		//作画选项菜单
		xyprintf(0, 0, "请选择您要进行的操作:");
		xyprintf(0, 20, "1.Easydraw");
		xyprintf(0, 40, "2.修改作画");
		xyprintf(0, 60, "3.删除作画");
		xyprintf(0, 80, "4.查询作画列表");
		xyprintf(0, 100, "5.保存绘画");
		xyprintf(0, 120, "0.退出作画");
		mune = getch();
		cleardevice();

		//进行的作画操作
		switch (mune)
		{
		case '1'://简单绘图
			easyDraw();
			break;

		case '2'://修改操作
			changeDraw();
			break;

		case '3'://删除操作

			deleteDraw();
			break;

		case '4'://查询作画列表
			check_list();
			break;

		case '5'://保存文件
			saveFile();
			break;

		case '0'://退出
			break;
		}

		//用mune检验是否要退出作画
		if (mune == '0')
		{
			cleardevice();
			break;
		}
	}
}





int main(void)
{


	//初始化
	initial(800, 600, 1);//此处的1是废弃的 暂时没有颜色参数
	//Part1读取文件    这里可能需要一些参数和设计  但是等到后续文件操作完整后再来设计
	readFile();


	//Part2进入画板  大改
	int re = 0;
	int mune = 0;
	xyprintf(0, 0, "欢迎您进入123画板，");
	while (1)
	{//这里获取了一份之前保留的上次作画菜单
		xyprintf(0, 20, "请根据菜单选择您想要进行的操作：");     //可以添加适当的换行操作 
		xyprintf(0, 40, "1.继续作画");
		xyprintf(0, 60, "2.重新作画");
		xyprintf(0, 80, "0.退出画板");
	
		mune = getch();
		cleardevice();

		switch (mune)
		{
		case '1':
			//这里没有进行清除操作 已经是继续作画了
			enterDraw();
			break;

		case '2':
			//这里需要清除掉上次的数据 释放空间等
			initList();
		    //tips
			xyprintf(0, 0, "已清除");
			delay_ms(1000);
			cleardevice();
			//进入画板
			enterDraw();
			break;

		case '0':
			//退出画板
			delimage(background);
			closegraph();
			break;
		}
		//检验退出
		if (mune == '0') {
			break;
		}
	}



	return 0;
}

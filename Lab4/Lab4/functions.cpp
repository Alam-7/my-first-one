#include"Lab4.h"
extern PIMAGE background;
/**************************************************************************/
/**************************************************************************/
/*************************************************************************/
//数据存储模块 （不需要暴露在外面）
//在进入作画板之前首先配置作画的结构体参数列表
//该结构体包含标识号和参数两部分
struct parament {
	//丢进去所有可能用到的参数 由于为了减少类型检查 所以似乎只能搞一个模板了
	//圆
	int circle_x;
	int circle_y;
	int circle_r;
	//直线
	int line_x1;
	int line_y1;
	int line_x2;
	int line_y2;
	//多边形
	int polygon_edges;
	int polygon_points[200];
	//填充颜色 这里需要一个枚举变量 最后再管理
	int color_fill;
};


//重构：将数组存储的数据修改为链表存储
//链表：头节点（只包含第一个元素的地址） 每个元素结构体自身：index,paras,nextNode   尾节点：null

 //重构节点
struct graphic {
	int index = 0;
	parament paraments;
	graphic* next = NULL;
};
//头节点
graphic header;
//仍然采用length 管理
int length = 0;
//任务：需要修改所有的save put check,撤销，恢复操作 之后再增添select,delete 操作 
//撤销和恢复只和put有关 使用length来管理


//封装的获取第n个节点的函数 当n为length的时候就是获取当前节点函数  并且返回的current就是第n个元素的房间号
graphic* get_node(int n) {

	if (n <= 0) {
		return &header;//返回头节点
	}
	graphic* current = header.next;
	for (int i = 1; i <= n - 1; i++) {
		current = current->next;
	}
	return current;
}
/**************************************************************************/
/**************************************************************************/
/*************************************************************************/




//Part2进入画板



//*********一系列的绘图函数（输入+保存）*************
void set_circle(graphic* current) {
	int x, y, r;
	char buf[100];
	inputbox_getline("设置半径", "请输入圆心半径", buf, 100);
	r = atoi(buf);

	//这里需要一定的检查判断 防止错误输入导致崩溃
	int flag = 1;
	//首先检查缓冲区是否有非法字符
	for (int i = 0; i <= strlen(buf) - 1; i++) {
		
		if (!(buf[i] >= 48 && buf[i] <= 57)) {
			flag = 0;//如果非法flag为假 
		}
	}
	if (!flag) {
		xyprintf(0, 0, "非法输入，请按格式输入！");
		delay_ms(1000);
		return;
	}
	//再次检查是否过大
	if (r > 600) {
		flag = 0;
	}
	if (!flag) {
		xyprintf(0, 0, "输入半径过大，请重新输入");
		delay_ms(1000);
		cleardevice();
		return;
	}

	xyprintf(0, 0, "请选择圆心");
	delay_ms(10);
	while (1) {
		if (keystate(key_mouse_l)) {
			mousepos(&x, &y);
			// 等待鼠标释放
			while (keystate(key_mouse_l));
			break;
		}
		delay(10); // 避免CPU占用过高
	}
	//添加一步  保存操作：每次保存前用length管理变量查询得到现在的空序列号   然后length++  撤销后length--即可

	graphic* Node = (graphic*)malloc(sizeof(graphic));
	Node->next = NULL;
	free(current->next);//null有影响吗？
	current->next = Node;



	Node->index = 1;//1表示圆
	Node->paraments.circle_x = x;
	Node->paraments.circle_y = y;
	Node->paraments.circle_r = r;
	length++;//注意使用完让length++  使length始终表示这个列表中我所有的元素个数

}
void set_line(graphic* current) {
	//定义两个点结构体（x1,x2,y1,y2)
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;

	xyprintf(0, 0, "请依次在画布上用左键点击两个点");
	delay_ms(10);

	// 等待第一次点击
	while (1) {
		if (keystate(key_mouse_l)) {
			mousepos(&x1, &y1);
			// 等待鼠标释放
			while (keystate(key_mouse_l));
			break;
		}
		delay(10); // 避免CPU占用过高
	}

	// 等待第二次点击
	while (1) {
		if (keystate(key_mouse_l)) {
			mousepos(&x2, &y2);
			// 等待鼠标释放
			while (keystate(key_mouse_l));
			break;
		}
		delay(10); // 避免CPU占用过高
	}
	//保存
	graphic* Node = (graphic*)malloc(sizeof(graphic));
	Node->next = NULL;
	free(current->next);//null有影响吗？
	current->next = Node;//这边直接当作截尾处理 后面有的 如果进行了作画操作就都不要了  删除节点的时候再去做两侧处理 撤销预计是回退一步 而恢复只有在连续的回退时才有效，因为 只要一作画就会截尾


	Node->index = 2;//2表示直线
	Node->paraments.line_x1 = x1;
	Node->paraments.line_y1 = y1;
	Node->paraments.line_x2 = x2;
	Node->paraments.line_y2 = y2;
	length++;

}
void set_polygon(graphic* current) {
	//同上：输入边数
	char buf[100];
	inputbox_getline("Edges and Color", "请输入您要画的多边形边数和颜色(1:RED 2:BLUE 3:GREEN) 注意用空格分隔", buf, 100);
	const char* delim = " ";
	//这里直接采用了正则检查
	std::regex pattern(R"(^\s*\d+\s+\d+\s*$)");
	if (!std::regex_match(buf, pattern)) {
		xyprintf(0, 0, "输入格式错误，请输入“边数 颜色”");
		delay_ms(1000);
		return;
	}

	int l = atoi(strtok(buf, delim));
	int color = atoi(strtok(NULL, delim));


	//设置结构体数组 存放将要输入的点的坐标
	struct point {
		int x;
		int y;
	};
	point points[100];

	//点击事件：提示  循环点击 存储点的坐标 点完之后交给fillpoly处理
	xyprintf(0, 0, "请在画布上选择该多边形的顶点(注意不要过快!）");
	delay_ms(1000);
	for (int i = 0; i <= l - 1; i++) {
		while (1) {
			if (keystate(key_mouse_l)) {
				mousepos(&points[i].x, &points[i].y);
				// 等待鼠标释放
				while (keystate(key_mouse_l));
				break;
			}
			delay(10); // 避免CPU占用过高
		}
	}
	//与原版相同的结构体数组再处理
	int arr[200];
	for (int j = 0; j < l; j++) {
		arr[2 * j] = points[j].x;
		arr[2 * j + 1] = points[j].y;
	}


	//保存
	graphic* Node = (graphic*)malloc(sizeof(graphic));
	Node->next = NULL;
	free(current->next);//null有影响吗？
	current->next = Node;


	Node->index = 3;
	Node->paraments.polygon_edges = l;
	Node->paraments.color_fill = color;
	memcpy(Node->paraments.polygon_points, arr, 2 * l * sizeof(arr[0]));
	length++;

}
//*********************************





//画布展示函数
void my_putimage(void) {
	//注意首先清除之前所有的作画 否则撤销不生效
	cleardevice(background);

	//每次在刷新之前优先检查是否超过20个 如果是就自动删去第一个
	if (length > 20) {
		graphic* p = header.next->next;//保存第二个数据的地址
		free(header.next);//释放第一个数据内存
		header.next = p;//重新指向
		length--;
		p = NULL;
	}


	//这里需要一个能够遍历所有结构体的“标识号” 然后进入到switch分支判断中执行相应画图操作的功能
	//这里的标识号似乎不需要对外展示 只需要自己这边有一个相应的对照即可  
	//通过节点的逐个查询获取各个节点
	for (int i = 0; i <= length - 1; i++) {
		//设定一个临时的参数对象 便于输入
		parament ps = get_node(i + 1)->paraments;
		switch (get_node(i + 1)->index) {
			//发现想要调用函数 必须提前在结构体列表中配置好所需的参数 便于使用 因而刚刚的作画操作其实就相当于是一个保存参数的过程 而撤销相当于是一个删除参数的过程 这里的putimage才是根据参数作画
		case 1://圆
		{
			//作圆操作
			circle(ps.circle_x, ps.circle_y, ps.circle_r, background);
			break;
		}
		case 2://直线
		{
			//连点做直线
			line(ps.line_x1, ps.line_y1, ps.line_x2, ps.line_y2, background);
			break;
		}

		case 3://多边形
		{
			switch (ps.color_fill) {
			case 1:
				setfillcolor(RED, background);
				break;
			case 2:
				setfillcolor(BLUE, background);
				break;
			case 3:
				setfillcolor(GREEN, background);
				break;
			}
			fillpoly(ps.polygon_edges, ps.polygon_points, background);
			break;
		}

		}
	}
	//等待所有作画操作完成后put画布
	putimage(0, 0, background);
}




//单独封装出来一个顶格展示列表的函数
void showList(void) {
	//首先清屏
	cleardevice();
	//怎么查询？ 遍历现有的列表中所有对象 根据index进入不同的case分支 打印相对应的数据形式 但是这里需要注意一点：可能有一些是相同类型的图形 它们打印格式相同 但是数据不同（需要显示大概数据以区分）  那么则需要一个id号（我是谁）与一个标识号（告诉程序我是啥）
	//oh no似乎不用考虑 因为length已经是一种Id了
	//1.遍历
	if (!length)
	{
		xyprintf(0, 0, "暂时还没有画图");
		delay_ms(1000);
		return;
	}
	//这里展示一下对应关系
	//1----圆
	//2----直线
	//3----多边形

	xyprintf(0, 0, "My List:");
	for (int i = 0; i <= length - 1; i++) {
		//设定一个临时的参数对象 便于输出
		parament ps = get_node(i + 1)->paraments;
		//首先检查其标识号是否为0  但是好像也不必要 因为length已经限制了现在我有多少和我能够访问多少对象 
		int now_height = (i + 1) * 20;
		switch (get_node(i + 1)->index) {//注意这里的i相当于id 而index相当于类型号也就是标识符

		case 1://圆的输出
			xyprintf(0, now_height, "%d.圆：圆心(%d,%d),半径：%d", i + 1, ps.circle_x, ps.circle_y, ps.circle_r);
			break;

		case 2://直线的输出
			xyprintf(0, now_height, "%d.直线：起点(%d,%d),终点(%d,%d)", i + 1, ps.line_x1, ps.line_y1, ps.line_x2, ps.line_y2);
			break;

		case 3://多边形的输出
			const char* color = NULL;
			switch (ps.color_fill) {
			case 1:
				color = "RED";
				break;
			case 2:
				color = "BLUE";
				break;
			case 3:
				color = "GREEN";
				break;
			default:
				color = "UNKNOWN";
				break;
			}
			xyprintf(0, now_height, "%d.多边形：边数：%d,填充颜色：%s", i + 1, ps.polygon_edges, color);
			break;
		}
	}
}
//后续如果需要再次查看并为某个对象添加修改属性也可以再调用这个函数
void check_list(void) {
	showList();
	//这里需要等待用户输入一个是否准备退出的提示
	xyprintf(0, (length + 1) * 20, "提示:键盘输入0退出查看列表");
	while (1) {
		int exit = getch();
		if (exit == '0') {
			cleardevice();
			return;
		}
	}

}
//删除操作
void deleteDraw(void) {
	//先打印列表然后提示输入要删除的id  随后调节指针指向
	showList();
	xyprintf(0, (length + 1) * 20, "请输入您要删除的作画操作(输入操作序号)：");
	char x = getch();
	graphic* p1 = get_node(atoi(&x) - 1);//这里往前多调整一位
	graphic* p2 = p1->next->next;
	free(p1->next);
	p1->next = p2;
	p1 = NULL;
	p2 = NULL;
	length--;//注意调整length管理变量
	cleardevice();
	xyprintf(0, 0, "已删除");
	delay_ms(800);
	//再次调用检查一下
	check_list();
}
//修改操作
void changeDraw(void) {  
	//调用列表查看 选择需要修改 三种index可以分别再次调用set函数来调整数据 覆盖这个位置上以前的数据（也可以删除后再追加 体现出是更新过的）
	showList();
	xyprintf(0, (length + 1) * 20, "请输入您要修改的作画操作(输入操作序号)：");
	char x = getch();//输入序号
	int index = get_node(atoi(&x))->index;//保留类型标识
	graphic* p1 = get_node(atoi(&x) - 1);//这里往前多调整一位
	graphic* p2 = p1->next->next;
	free(p1->next);
	p1->next = p2;
	p1 = NULL;
	p2 = NULL;
	length--;//注意调整length管理变量

	//此时修改后再次调用对应的set函数(注意展示画布）
	my_putimage();
	switch (index) {
	case 1:
		set_circle(get_node(length));
		break;
	case 2:
		set_line(get_node(length));
		break;
	case 3:
		set_polygon(get_node(length));
		break;
	}
	cleardevice();
	xyprintf(0, 0, "修改成功");
	my_putimage();
	delay_ms(800);
	//再次调用检查一下
	check_list();

}





//撤销操作
void back_1(void) {
	//这里需要实现一步删除上步刚刚添加进入的结构体
	//根据之前的分析 由于length变量的管理 直接将length--即可实现结构体删除 因为之后的Put中不会出现这最后一个 并且下次有新的会直接赋值覆盖掉原参数（同时修改index） 只要不去接触不该使用的参数即可
	length--;
	//需要实时检测length即list中的对象不能少于0个  防止多撤销的Bug
	if (length < 0) length = 0;
}
//恢复操作
void forward_1(graphic* current) {
	//length++;//恢复刚刚被误删的节点
	////防止多恢复了没有被设置的对象数据
	//if (current->next==NULL) length--;   //在这里只要一作画就会截尾 丢掉剩余节点 保持尾巴始终是null
	if (current->next == NULL) return;//当当前节点指向null也就是尾巴的时候无法继续增加length  否则可以增加length来访问下一个有数据的节点
	length++;
}

//保存绘画
void saveFile(void) {
	//目前先完成自动保存到最近的history文件中 使得每次保存都会刷新保存 
	FILE* pf = fopen("drawHistory.txt", "w");
	fwrite(&length, sizeof(int), 1, pf);
	//链表存储 
	graphic* p = header.next;
	for (int i = 0; i <= length - 1; i++) {
		fwrite(p, sizeof(graphic), 1, pf);
		p = p->next;
	}
	fclose(pf);
	xyprintf(0,0,"已成功保存");
	delay_ms(1000);
}



//初始化列表操作  还有就是需要清除清空一下现在已经有的画布背景
void initList(void) {
	//length归0
	length = 0;
	//释放内存
	free(header.next);
	header.next = NULL;
	//清空画布 
	cleardevice(background);

}



//Part1 读取文件
void readFile(void) {
	int f_mune = 0;
	xyprintf(0, 0, "欢迎您进入123画板，请根据菜单选择您想要进行的操作:");
	xyprintf(0, 20, "1.读取文件");
	xyprintf(0, 40, "2.不读取文件");
	xyprintf(0, 60, "请输入您的选择：");
	while (1)
	{
		f_mune = getch();
		//首先判断是否合法
		if (f_mune == '1' || f_mune == '2')
		{
			//if分支判断
			if (f_mune == '1')
			{
				cleardevice();
				xyprintf(0, 20, "正在读取...");
				delay_ms(1500);
				cleardevice();
				//在这里打印上次的作画记录
				FILE* fp = fopen("drawHistory.txt", "r");//但是这里需要注意避免没有历史的时候读取怎么办
				fread(&length, sizeof(int), 1, fp);
				if (!length) {
					xyprintf(0, 0, "暂时没有文件");
					delay_ms(1000);
					cleardevice();
					return;
				}
				//链表读取
				header.next = (graphic*)malloc(sizeof(graphic));//分配地址  否则本来是null
				graphic* p = header.next;
				for (int i = 0; i <= length - 1; i++) {
					fread(p, sizeof(graphic), 1, fp);
					p->next = (graphic*)malloc(sizeof(graphic));//重新分配新的地址
					p = p->next;
				}
				fclose(fp);
				//此处已经读取完毕 调用check函数  
				check_list();
				//但是后面的重新绘图操作需要注意将kength和现在的链表初始化
			}
			else
			{
				cleardevice();
				xyprintf(0, 0, "未读取");
				delay_ms(1000);
				cleardevice();

			}
			break;
		}
		//不合法的处理
		else {
			cleardevice();
			xyprintf(0, 0, "输入错误，请重新输入");

		}
	}


}

//Part2 简单绘画
void easyDraw(void) {
	cleardevice();
	while (1) {

		//打印菜单
		xyprintf(0, 0, "请选择您要绘制的图形：");
		xyprintf(0, 20, "1.圆");
		xyprintf(0, 40, "2.连点作直线");
		xyprintf(0, 60, "3.作多边形");
		xyprintf(0, 80, "选择0退出");
		xyprintf(0, 100, "提示：ctrl+z撤销上步画图操作");
		xyprintf(0, 120, "提示：8恢复上步画图操作");
		int mune = getch();
		//每次开始画图前都要先清除屏幕 粘贴画布 然后保存
		cleardevice();
		my_putimage();

		// 新的保存操作:每次开始作画前都查询并准备好现在所开辟的新节点 函数内部直接保存到这个节点的参数里就OK   (这个过程在每次要对节点进行修改时都是必要的 可以考虑封装一个函数)
		//需要查询到当前所在的链表尾节点（的房间号）
		graphic* current = get_node(length);
		//现在的current即为我的length所管理的第length个节点的地址   
		//将current理解为现在我最后一个要的元素的房间号
		//而Next就是下一个这个链表中下一个元素的房间号   而length则是管理我要的这个链的长度 因而链表和数组没有不同 撤销和恢复均由length管理 而修改就相当于直接覆盖
		/*graphic* Node = (graphic*)malloc(sizeof(graphic));
		Node->next = (current->next)->next;
		current->next = Node;*///注意房间号修改的顺序  至于说是否是null也不影响
		//上面的覆盖代码要丢到作画操作内部 因为有时候还没有操作 因而不能直接将下一个节点覆盖掉 否则就通过length 撤销找不到
		switch (mune) {

		case '1'://画圆
		{
			set_circle(current);
			break;
		}
		case '2'://鼠标画简单直线
		{
			set_line(current);
			break;
		}

		case '3':
		{
			set_polygon(current);
			break;
		}
		case '0'://退出
			break;
		case 26://撤销
			back_1();
			break;
		case '8'://恢复  为什么按z键突然不管用了？？？？
			forward_1(current);
			break;

		default:
			xyprintf(0, 0, "输入错误，请重新输入");
			delay_ms(1000);
			break;
		}

		//进行完作画操作后展示画布  将画布显示到window中  每次操作都是一次遍历现有的所有list中的对象 并putimage
		my_putimage();

		//检验退出
		if (mune == '0') {
			break;
		}

	}


}



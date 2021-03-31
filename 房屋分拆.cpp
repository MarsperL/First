#include<stdio.h>                 
#include<stdlib.h>               
#include<string.h>                
#define TITLE "\n(ｏ^ω^)╭->*<<<房屋分拆>>>*<-╮(＾ω＾ｏ)    MarsperL \n"       /*标题文字*/ 
#define MAX 10
#define MENU_MAIN_COUNT 2          /*主菜单的选项个数*/  
#define MENU_MANAGER_COUNT 2      /*执行分拆任务模块子函数个数*/ 
typedef struct staff
{
struct staff *next;        
}stu;
/*定义一个头节点*/
stu* head;                 /*staff结构体链表的头节点*/
/*主要处理函数声明*/
void rev();
void manager_record();
void print_menu_main();
void exit_system();
void back_record();        /*返回上级菜单*/
//主界面 
/*字符数组menu_main中储存的是主菜单要显示的字符*/
char menu_main[]=
"\n"               
"|》 1 执行分拆任务\n"     "\n"
"|》 2 退出\n"   "\n";    
/*函数指针数组menu_main_func储存的是主菜单中4个功能函数的
 *地址分别对应1-2个菜单项*/
void (*menu_main_func[])()=
{
	manager_record, 
    exit_system,
};
int main()
{
	print_menu_main();
	return 0;        //显示主菜单等待用户入
}
/*显示主菜单界面*/
void print_menu_main()
{
	int selected=0;/*用户选择的菜单项*/
	system("cls");/*清屏*/
	printf(TITLE);/*显示标题*/
	printf(menu_main);      /*显示菜单字符*/
	printf("(～￣▽￣)～(～￣▽￣)～(～￣▽￣)～(～￣▽￣)～(～￣▽￣)～\n");
	/*如果用户没有选择或者选择错误，循环等待*/
	while(!(selected>=1&&selected<=MENU_MAIN_COUNT))
	{
		printf("> 请选择：");
		scanf("%d",&selected);
		getchar();
		if(selected>=1&&selected<=MENU_MAIN_COUNT)
			break;
		printf("\n> 输入错误！（注：请选择1-%d）\n",MENU_MAIN_COUNT);
	}
	menu_main_func[selected-1]();/*调用用户选择菜单项对应的函数指针数组中的函数*/
} 
/*取得链表最后一个值函数*/
stu* get_last_staff(stu* p)
{
	if(p->next==NULL)
	{
		return p;
	}
	else 
	{ 
		return get_last_staff(p->next);
	}
} 
//执行分拆任务模块
/*字符数组menu_manager中储存的是执行分拆任务模块要显示的字符*/
char menu_manager[]=
"\n"
"|> 1 执行房屋分拆任务\n"
"\n"
"|> 2 返回主界面菜单\n"     
"\n";
void (*menu_manager_func[])()=
{  
	rev,         
	back_record, //返回主界面菜单
};
void manager_record()//执行房屋分拆任务模块 
{
	int selected=0;
	system("cls"); 
	printf("\n(ｏ^ω^)╭ >-->*执行分拆任务模块*<--＜ ╮(＾ω＾ｏ)  MarsperL\n");
	printf(menu_manager);
	printf("(～￣▽￣)～(～￣▽￣)～(～￣▽￣)～(～￣▽￣)～\n");
	while(!(selected>=1&& selected<=MENU_MANAGER_COUNT))
	{
		printf("> 请选择：");
		scanf("%d",&selected);
		getchar();      //接收最后从键盘录入的回车符
		if(selected>=1&& selected<=MENU_MANAGER_COUNT)
			break;
		printf("\n> 输入错误！（请选择1-%d)\n",MENU_MANAGER_COUNT);
 
	}
	menu_manager_func[selected-1]();
} 
//退出子菜单函数，返回到主菜单界面
void sort_exit()
{
	manager_record();
} 
//返回上级菜单 
void back_record()
{
	print_menu_main();
}
//退出系统函数
void exit_system()
{
	exit(0);
}
//房屋分拆主要代码 
typedef struct Node * Heap; /*堆结构*/
struct Node
{
	int * Data;
	int Size;
};
typedef Heap MinHeap;/*最小堆*/
Heap CreateHeap(int n)//最小堆的创建
{
	MinHeap H=(MinHeap)malloc(sizeof(struct Node));
	H->Data=(int *)malloc(2*(n+1)*sizeof(int));
	H->Size=0;//初始化 
	H->Data[0]=0;/*最小堆的哨兵*/
	return H;
}
void Insert(Heap H,int m)//建初堆
{
	int i;
	i=++H->Size;
	for(; H->Data[i/2]>m; i/=2)
		H->Data[i]=H->Data[i/2];
	H->Data[i]=m;
}
int Del(Heap H)//重建小跟堆
{
	int parent,child;
	int min,x;
	min=H->Data[1];
	x=H->Data[H->Size--];//用最后一个元素替代已经输出的堆顶元素
	for(parent=1; parent*2<=H->Size ; parent=child) //沿较小的孩子向下筛选
	{
   	child=parent*2;
	if((child!=H->Size)&&(H->Data[child]>H->Data[child+1])) child++;
	if(H->Data[child]>=x) break;
	else H->Data[parent]=H->Data[child];
   }
H->Data[parent]=x;
return min;
}
void rev()
{
	char continue_input='N';
	int n,m,i,sum=0,a,b;
	printf("请输入实验数据：\n"); 
	scanf("%d",&n);
	Heap H=CreateHeap(n);
	for(i=1; i<=n; i++)
	{
		scanf("%d",&m);
		Insert(H,m);/*将所有元素入堆(H)*/
	}
	while(H->Size!=1)
	{
		a=Del(H);//去掉最小值再重建堆
		b=Del(H);//去掉次小值再重建堆
		b=a+b;
		sum+=b;//不断累加求和
		Insert(H,b);
	}
	printf("%d",sum);
	printf("\n继续执行房屋分拆任务？（Y/y 继续，N/n 返回菜单）\n");
	getchar();
	continue_input=getchar();
	if(continue_input=='n'||continue_input=='N')
	{
		print_menu_main();/*不继续输入，将显示主菜单*/
	}
	else if(continue_input=='y'||continue_input=='Y') 
	{
		rev();/*再次调用这个函数执行房屋分拆任务*/
	} 
	else
	{
		printf("\n> 输入错误！请选择Y/y(继续)，N/n(返回菜单) \n");
		getchar();
		continue_input=getchar();
		if(continue_input=='n'||continue_input=='N')
			print_menu_main();/*不继续输入，将显示主菜单*/
		else if(continue_input=='y'||continue_input=='Y') 
			rev();/*再次调用这个函数执行房屋分拆任务*/
	}
}


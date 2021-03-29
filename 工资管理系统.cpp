#include<stdio.h>                 
#include<stdlib.h>               
#include<string.h>                
#define TITLE "\n(ｏ^ω^)╭ >-->*<<<工资管理系统>>>*<--＜ ╮(＾ω＾ｏ)    云沐灵风 19031110114\n"       /*标题文字*/ 
#define MAX 10
#define MENU_MAIN_COUNT 4          /*主菜单的选项个数*/  
#define MENU_MANAGER_COUNT 8       /*管理员模块菜单子函数个数*/ 
#define MENU_USER_COUNT 4          /*普通用户模块菜单子函数个数*/ 
#define MENU_SEARCH_COUNT 3        /*查询员工工资子菜单的选项个数*/
#define MENU_CALC_COUNT 3          /*按工号查询工资排名子菜单的选项个数*/
#define MENU_SORT_COUNT 3          /*管理员工资高低排序子菜单的选项个数*/
typedef struct staff
{
char name[MAX];            /*姓名*/
char num[MAX];             /*工号*/    
char sex[MAX];             /*性别*/
char department;           /*部门*/
int money;                 /*工资*/ 
int year;                  /*入职年份*/
struct staff *next;        /*指向下一个员工的指针*/
}stu;
/*定义一个头节点*/
stu* head;                 /*staff结构体链表的头节点*/
/*主要处理函数声明*/
//管理员菜单模块： 
void input_record();       /*录入员工信息处理*/
void show_record();        /*显示所有员工工资处理*/ 
void update_record();      /*修改员工信息*/
void delete_record();      /*删除员工信息*/
void count_record();       /*统计各入职年份工资*/
void sort();               /*员工工资排序*/
void save_to_file();       /*保存到文件的处理*/
void back_record();        /*返回上级菜单*/
//普通用户菜单模块：
void search_record();      /*查询员工工资的处理*/ 
void calculate();          /*工资排名*/ 
void save_to_file();       /*保存到文件的处理*/
void back_record();        /*退出系统*/
/*查询员工工资子函数声明*/
//普通用户模块： 
void search_by_id();       /*通过工号检索员工的处理*/
void search_by_name();     /*通过姓名检索员工的处理*/
void search_exit();        /*退出子菜单，返回上级菜单*/
/*工资排名子函数声明*/
void calc_department();    /*按所在部门排序的处理*/
void calc_year();          /*按入职年份排序的处理*/
void calc_exit();          /*退出子菜单，返回上级菜单*/
/*工资高低排序子函数声明*/
//管理员模块： 
void sort_year();          /*按入职年份排序的处理*/
void sort_department();    /*按部门排序的处理*/
void sort_exit();          /*退出子菜单，返回上级菜单*/
/*辅助函数声明*/
void create_stu_by_input(stu* pNewStu);      /*通过输入为STAFF赋值*/
stu* get_last_STAFF(stu* p);                 /*找到最后一个员工的记录*/
void clear_record(stu* p);                   /*清空所有记录*/
/*显示控制函数声明*/
void print_menu_main();                      //显示主菜单
//管理员模块菜单 
/*字符数组menu_manager中储存的是管理员模块要显示的字符*/
char menu_manager[]=
"|\n"
"|> 1 录入员工信息\n"       "\n" 
"|> 2 显示所有员工工资\n"   "\n"
"|> 3 修改员工信息\n"       "\n"
"|> 4 删除员工信息\n"       "\n"
"|> 5 统计各入职年份工资\n" "\n"
"|> 6 从高到低显示工资\n"   "\n"
"|> 7 保存到文件\n"         "\n"
"|> 8 返回主界面菜单\n"     
"|\n";
/*函数指针数组menu_manager_func储存的是管理员模块所对应的
 *8个功能函数的地址，分别对应1-8菜单项*/
void (*menu_manager_func[])()=
{  
	input_record,          //录入员工信息
	show_record,		   //显示所有员工工资
	update_record,         //修改员工信息
	delete_record,         //删除员工信息
	count_record,          //统计各入职年份工资
	sort,                  //从高到低显示工资
	save_to_file,          //保存到文件
	back_record,           //返回主界面菜单
};
void manager_record()
{
	int selected=0;
	system("cls"); 
	printf("\n(ｏ^ω^)╭ >-->*管理员模块菜单*<--＜ ╮(＾ω＾ｏ)\n");
	printf(menu_manager);
	printf("===================================================\n");
	while(!(selected>=1&& selected<=MENU_MANAGER_COUNT))
	{
		printf("> 请选择：");
		scanf("%d",&selected);
		getchar();      //接收最后从键盘录入的回车符
		if(selected>=1&& selected<=MENU_MANAGER_COUNT)
		{
			break;
		}
		printf("\n> 输入错误！（请选择1-%d)\n",MENU_MANAGER_COUNT);
 
	}
	menu_manager_func[selected-1]();
} 
//退出排序子菜单函数，返回到主菜单界面
void sort_exit()
{
	manager_record();
} 
//返回上级菜单 
void back_record()
{
	print_menu_main();
}
//普通用户模块菜单 
/*字符数组menu_user中储存的是普通用户模块要显示的字符*/
char  menu_user[]=
"|\n"
"|> 1 查询员工工资\n"           "\n"
"|> 2 按工号查询工资排名\n"     "\n"
"|> 3 保存到文件\n"             "\n"
"|> 4 返回主界面菜单\n"  
"|\n";
/*函数指针数组menu_user[]储存的是普通用户模块功能函数所对应的
 4个功能函数的地址，分别对应1-4菜单项*/
void (*menu_user_func[])()=  //普通用户模块功能函数内层调用 
{
	search_record,           //查询员工工资
	calculate,		         //工资排名
	save_to_file,            //保存到文件
	back_record,             //返回主界面菜单
};
void user_record()
{
	int selected=0;
	system("cls");
	printf("\n(ｏ^ω^)╭ >-->*普通用户模块菜单*<--＜ ╮(＾ω＾ｏ)\n");
	printf(menu_user);
	printf("===================================================\n");
	while(!(selected>=1&& selected<=MENU_USER_COUNT))
	{
		printf("> 请选择：");
		scanf("%d",&selected);
		getchar();      //接收最后从键盘录入的回车符
		if(selected>=1&& selected<=MENU_USER_COUNT)
		{
			break;
		}
		printf("\n> 输入错误！（请选择1-%d)\n",MENU_USER_COUNT);

	}
	menu_user_func[selected-1]();
}
//主界面 
/*字符数组menu_main中储存的是主菜单要显示的字符*/
char menu_main[]=
"|\n"               
"|》 1 管理员\n"     "\n"
"|》 2 普通用户\n"   "\n"
"|》 3 保存文件\n"   "\n"
"|》 4 退出系统\n"   "\n";
//退出系统函数
void exit_system()
{
	clear_record(head);    //释放整个链表
	exit(0);
}
/*清空所有记录函数*/
void clear_record(stu* p)
{
	if(p==NULL)
	{
		return;
	}
   /*如果staff结构体的next指针是空*
	*则表示没有下一条数据，删除该节点*/
	if(p->next==NULL)
	{
		free(p);
	}
    /*如果staff结构体的next指针不为空，*/
	else
	{
		clear_record(p->next);/*再次调用本函数，staff结构体next指向的节点作为参数*/
		free(p);/*删除当前节点*/
		p=NULL;/*将指针置空*/
	}
}
/*函数指针数组menu_main_func储存的是主菜单中4个功能函数的
 *地址分别对应1-4个菜单项*/
void (*menu_main_func[])()=
{
	manager_record,
	user_record,
	save_to_file,
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
	int selected=0;         /*用户选择的菜单项*/
	system("cls");          /*清屏*/
	printf(TITLE);          /*显示标题*/
	printf(menu_main);      /*显示菜单字符*/
	printf("＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n");
	/*如果用户没有选择或者选择错误，循环等待*/
	while(!(selected>=1&&selected<=MENU_MAIN_COUNT))
	{
		printf("》》》请选择：");
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
/*录入员工信息函数*/
void input_record()
{
	char continue_input='N';
	stu* pLastStu=NULL;
	stu* pNewStu=(stu*)malloc(sizeof(stu)); /*创建一个stu*/
	pNewStu->next=NULL;
	create_stu_by_input(pNewStu);           /*让用户为创建的stu赋值*/
	if(head==NULL)/*一个都没有*/
	{
		head=pNewStu;
	}
	else
	{
		pLastStu=get_last_staff(head);      /*找到最后一个*/
		pLastStu->next=pNewStu;
	}
	printf("\n继续录入员工信息？（Y/y 继续，N/n 返回菜单）\n");
	getchar();
	continue_input=getchar();
	if(continue_input=='n'||continue_input=='N')
	{
		print_menu_main();/*不继续输入，将显示主菜单*/
	}
	else
	{
		input_record();/*再次调用这个函数录入新的员工信息*/
	}
}
/*提示录入员工信息函数*/
void create_stu_by_input(stu* pNewStu)
{
	printf("> 请输入员工信息（注：最大长度是10个字符）\n");
	printf("工号：");scanf("%s",pNewStu->num);
	printf("姓名：");scanf("%s",pNewStu->name);
	printf("性别：");scanf("%s",pNewStu->sex);
	printf("工资：");scanf("%d",&(pNewStu->money));
	printf("入职年份：");scanf("%d",&(pNewStu->year));
	printf("部门：");scanf("%s",&(pNewStu->department));
}
void display()
{
    FILE *fp;
    char buff[999999];
    printf("> 请输入文件名：");
    scanf("%s",buff);
    fp=fopen(buff,"rb");    //打开文件
    char ch;
    if(fp==NULL)   
	{
           printf("cann't open file");
           exit(0);
    }
    while((ch=fgetc(fp))!=EOF)    //不到文件结束就循环
    {
    	 putchar(ch);          
	}
    fclose(fp);            //关闭文件指针   
    getchar();
}
/*显示员工信息函数*/
void show_record()
{
	stu* p=head;
    display();
	while(p!=NULL)
	{
		p=p->next;
	}
	printf("按回车键返回菜单\n");
	getchar();
      manager_record();
}
/*修改员工信息函数*/
void update_record()
{
	stu*p=head;
	char id[MAX];
	char continue_input='N';
	printf("\n请输入要修改员工信息的工号:\n");
	scanf("%s",id);
	while(p!=NULL)
	{
		if(strcmp(p->num,id)==0)
		{
			break;
		}
		p=p->next;
	}
	if(p==NULL)
	{
		printf("没有工号是[%s]的员工.\n",id);
	}
	else
	{
		create_stu_by_input(p);
	}
	printf("\n继续更新吗?(Y/y继续，N/n返回菜单)\n");
	getchar();     //接收最后从键盘录入的回车符
	continue_input=getchar();
	if(continue_input=='n'||continue_input=='N')
	{
		print_menu_main();
	}
	else
	{
		update_record();
	}
}
/*删除员工信息函数*/
void delete_record()
{
	stu *p=head;
	stu *pPre=NULL;
	char id[MAX];
	char continue_input='N';
	printf("\n请输入要删除的员工工号:\n");
	scanf("%s",id);
	while(p!=NULL)
	{
		if(strcmp(p->num,id)==0)
		{
			break;
		}
		p=p->next;
	}
	if(p==NULL)
	{
       printf("没有工号是[%s]的员工.\n",id);
	}
	else
	{
		printf("\n确定要删除工号为[%s]姓名为[%s]的员工吗？(Y/y确定,N/n取消)\n",p->num,p->name);
		getchar();
		continue_input=getchar();
		if(continue_input=='y'||continue_input=='Y')
		{
			pPre=head;
			if(pPre==p)
			{
				head=p->next;
                free(p);
			}
			else
			{
				while(pPre!=NULL)
				{
					if(pPre->next==p)
					{
						pPre->next=p->next;
						free(p);
						break;
					}
				pPre=pPre->next;
				}
			}
			printf("删除成功!\n");
		}
	}
	printf("\n继续删除吗?(Y/y继续,N/n返回菜单)\n");
	getchar();        //接收最后从键盘录入的回车符
	continue_input=getchar();
	if(continue_input=='n'||continue_input=='N')
	{
		print_menu_main();
	}
	else
	{
		delete_record();
	}
}
//统计各入职年份工资
void count_record()
{
	int i=0;
	stu *p_1,*p_2,*temp_p,temp;
	printf("\n*统计各入职年份工资*\n");
	for(p_1=p_2=head;p_1!=NULL || p_2!=NULL;p_1=p_1->next)
	{
		for(p_2=p_1->next;p_2!=NULL;p_2=p_2->next)
			if(p_1->year<p_2->year)
			{
				temp=*p_1;*p_1=*p_2;*p_2=temp;
				temp_p=p_1->next; p_1->next= p_2->next; p_2->next=temp_p;
			}	
		p_1->year=++i;	
	}
	printf("\n按回车键返回上一菜单\n");
	getchar();
	print_menu_main();
}
void search_exit()//查询员工工资子菜单返回普通用户模块菜单 
{
	user_record();//用户模块菜单 
}
//从高到低显示工资 
/*字符数组menu_sort中储存的是从高到低显示工资排序子菜单中要显示的字符*/
char menu_sort[]=
"|\n"
"|> 1 按入职年份显示排序\n"    "\n"
"|> 2 按所在部门显示排序\n"    "\n"
"|> 3 返回上级菜单\n"          
"|\n";
/*函数指针数组menu_sort_func储存的是从高到低显示工资排序子菜单项所对应的
 *3个功能函数的地址，分别对应1-3菜单项*/
void (* menu_sort_func[])()=
{	
	sort_year,
	sort_department,
	sort_exit,
};
/*从高到低显示工资的函数*/
void sort()
{
	int selected=0;
	system("cls");//清屏 
	printf("\n(ｏ^ω^)╭ >-->*从高到低显示工资*<--＜ ╮(＾ω＾ｏ)\n");
	printf(menu_sort);
	printf("===================================================\n");
	while(!(selected>=1&&selected<=MENU_SORT_COUNT))
	{
		printf("> 请选择:");
		scanf("%d",&selected);
		getchar();         //接收最后从键盘录入的回车符
		if(selected>=1&&selected<=MENU_SORT_COUNT)
		{
			break;
		}
		printf("\n> 输入错误!(请选择1-%d)\n",MENU_SORT_COUNT);
	}
	menu_sort_func[selected-1]();    //调用选择的子菜单所对应的函数
}
/*按入职年份排序函数*/
void sort_year()
{
	int i=0;
	stu *p_1,*p_2,*temp_p,temp;
	printf("\n按入职年份排序\n");
	for(p_1=p_2=head;p_1!=NULL || p_2!=NULL;p_1=p_1->next)
	{
		for(p_2=p_1->next;p_2!=NULL;p_2=p_2->next)	
			if(p_1->year<p_2->year)
			{
				temp=*p_1;*p_1=*p_2;*p_2=temp;	
				temp_p=p_1->next; p_1->next= p_2->next; p_2->next=temp_p;
			}	
		p_1->year=++i;
	}
	printf("\n按回车键返回上一菜单\n");
	getchar();
	sort();
}
/*按部门排序函数*/
void sort_department()
{
	int i=0;
	stu *p_1,*p_2,*temp_p,temp;
	printf("\n按部门排序\n");
	for(p_1=p_2=head;p_1!=NULL || p_2!=NULL;p_1=p_1->next)
	{
		for(p_2=p_1->next;p_2!=NULL;p_2=p_2->next)
			if(p_1->department<p_2->department)
			{
				temp=*p_1;*p_1=*p_2;*p_2=temp;
				temp_p=p_1->next; p_1->next= p_2->next; p_2->next=temp_p;
			}	
		p_1->department=++i;	
	}
	printf("\n按回车键返回上一菜单\n");
	getchar();
	sort();
}
//查询员工工资 
/*字符数组menu_search中储存的是查询子菜单中要显示的字符*/
char menu_search[]=
"|\n"
"|> 1 按照工号查询\n"  "\n"
"|> 2 按照姓名查询\n"  "\n"
"|> 3 返回上级菜单\n"  
"|\n";
/*函数指针数组menu_search_func储存的是查询子菜单项所对应的
 *3个功能函数的地址，分别对应1-3菜单项*/
void (*menu_search_func[])()=
{  
	search_by_id,
	search_by_name,
	search_exit,
};
/*查询员工工资函数*/
void search_record()
{
	int selected=0;
	system("cls");
	printf("\n(ｏ^ω^)╭ >-->*查询员工工资*<--＜ ╮(＾ω＾ｏ)\n");
	printf(menu_search);
	printf("===================================================\n");
	while(!(selected>=1&& selected<=MENU_SEARCH_COUNT))
	{
		printf("> 请选择：");
		scanf("%d",&selected);
		getchar();      //接收最后从键盘录入的回车符
		if(selected>=1&& selected<=MENU_SEARCH_COUNT)
		{
			break;
		}
		printf("\n> 输入错误！（请选择1-%d)\n",MENU_SEARCH_COUNT);
	}
	menu_search_func[selected-1]();
}
/*按工号查询员工工资函数*/
void search_by_id()
{
	char id[MAX];
	char continue_input='N';
	stu* p=head;
	int isfound=0;
	printf("> 请输入员工工号：");
	scanf("%s",id);
	printf("\n> 查找[%s]\n",id);
	while (p!=NULL)
	{
		if(strcmp(p->num,id)==0)
		{
			isfound=1;
			break;
		}
		p=p->next;
	}
	if(!isfound)
		printf("\n没有找到结果！\n");
	printf("继续查找？（Y/y 继续，N/n 返回）");
	getchar();
	continue_input=getchar();
	if(continue_input=='Y'||continue_input=='y')
	{
		search_by_id();
	}
	else
	{
		search_record();/*重新显示查询子菜单，即返回菜单*/
	}
}
/*按名字查询员工工资函数*/
void search_by_name()
{
	char name[MAX];
	char continue_input='N';
	stu* p=head;
	int isfound=0;
	printf("> 请输入员工姓名：");
scanf("%s",name);
	printf("\n> 查找[%s]\n",name);
	while (p!=NULL)
	{
		if(strcmp(p->name,name)==0)
		{
			isfound=1;
		}
		p=p->next;
	}
	if(!isfound)
		printf("\n没有找到结果！\n");
	printf("\n继续查找？（Y/y 继续，N/n 返回）\n");
	getchar();
	continue_input=getchar();
	if(continue_input=='Y'||continue_input=='y')
	{
		search_by_name();
	}
	else
	{
		search_record();
	}
}
//按工号查询工资排名
/*字符数组menu_calculate中储存的是工资排名子菜单中要显示的字符*/
char menu_calculate[]=
"|\n"
"| 1 按所在部门的工资排序\n"   "\n"
"| 2 按入职年份的工资排序\n"   "\n"
"| 3 返回上级菜单\n"          
"|\n";
/*函数指针数组menu_calculate[]储存的是工资排名子菜单项所对应的
 *3个功能函数的地址，分别对应1-3菜单项*/
void (* menu_calculate_func[])()=
{	
	calc_department,
	calc_year,
	calc_exit,
};
/*按工号查询工资排名的函数*/
void calculate()
{
	int selected=0;
	system("cls");
	printf("\n(ｏ^ω^)╭ >-->*按工号查询工资排名*<--＜ ╮(＾ω＾ｏ)\n");
	printf(menu_calculate);
	printf("===================================================\n");
	while(!(selected>=1&&selected<=MENU_CALC_COUNT))
	{
		printf("> 请选择:");
		scanf("%d",&selected);
		getchar();         //接收最后从键盘录入的回车符
		if(selected>=1&&selected<=MENU_CALC_COUNT)
		{
			break;
		}
		printf("\n> 输入错误!(请选择1-%d)\n",MENU_CALC_COUNT);
	}
	menu_calculate_func[selected-1]();                    //调用选择的子菜单所对应的函数
}
/*按所在部门排序函数*/
void calc_department()
{
	int i=0;
	stu *p_1,*p_2,*temp_p,temp;
	printf("\n按所在部门排序\n");
	for(p_1=p_2=head;p_1!=NULL || p_2!=NULL;p_1=p_1->next)
	{
		for(p_2=p_1->next;p_2!=NULL;p_2=p_2->next)	
			if(p_1->department<p_2->department)
			{
				temp=*p_1;*p_1=*p_2;*p_2=temp;	
				temp_p=p_1->next; p_1->next= p_2->next; p_2->next=temp_p;
			}	
		p_1->department=++i;
	}
	printf("\n按回车键返回上一菜单\n");
	getchar();
	calculate(); 
}
/*按入职年份排序函数*/
void calc_year()
{
	int i=0;
	stu *p_1,*p_2,*temp_p,temp;
	printf("\n按入职年份排序\n");
	for(p_1=p_2=head;p_1!=NULL || p_2!=NULL;p_1=p_1->next)
	{
		for(p_2=p_1->next;p_2!=NULL;p_2=p_2->next)
			if(p_1->year<p_2->year)
			{
				temp=*p_1;*p_1=*p_2;*p_2=temp;
				temp_p=p_1->next; p_1->next= p_2->next; p_2->next=temp_p;
			}	
		p_1->year=++i;	
	}
	printf("\n按回车键返回上一菜单\n");
	getchar();
	calculate();
}
void calc_exit()
{
	user_record();
}
/*保存到文件函数*/
void save_to_file()
{
	FILE *fp;
	char file[100];
	stu*p=head;
	printf("\n请输入文件名:\n");
	scanf("%s",file);
	fp=fopen(file,"w");
	while(p!=NULL)
	{
		fprintf(fp,"%s %s %s %d %d %d\n",p->num,p->name,p->sex,p->year,p->department,p->money);
		p=p->next;
	}
	fclose(fp);
	printf("\n保存成功（￣︶￣）↗\n按回车键返回菜单\n");
	getchar();     //接收最后从键盘录入的回车符
	getchar();
	print_menu_main();
}


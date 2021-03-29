//查询员工工资 
/*字符数组menu_search中储存的是查询子菜单中要显示的字符*/
char menu_search[]=
"|\n"
"|> 1 按照学号查询\n"  "\n"
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
	printf("\n继续查找？（Y/y 继续，N/n 返回\n）");
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

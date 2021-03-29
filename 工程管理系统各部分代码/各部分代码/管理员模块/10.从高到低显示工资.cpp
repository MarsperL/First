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

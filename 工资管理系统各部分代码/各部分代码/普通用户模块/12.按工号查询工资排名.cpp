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

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

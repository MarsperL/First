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

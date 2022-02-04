/*录入员工信息函数*/
void input_record()
{
	char continue_input='N';
	stu* pLastStu=NULL;
	stu* pNewStu=(stu*)malloc(sizeof(stu));/*创建一个stu*/
	pNewStu->next=NULL;
	create_stu_by_input(pNewStu);/*让用户为创建的stu赋值*/
	if(head==NULL)/*一个都没有*/
	{
		head=pNewStu;
	}
	else
	{
		pLastStu=get_last_staff(head);/*找到最后一个*/
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

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
	print_menu_main();
}

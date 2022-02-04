//主界面 
/*字符数组menu_main中储存的是主菜单要显示的字符*/
char menu_main[]=
"|\n"               
"|》 1 管理员\n"     "\n"
"|》 2 普通用户\n"   "\n"
"|》 3 保存文件\n"   "\n"
"|》 4 退出系统\n"   "\n";   
//退出系统部分代码插在此处！！！ 
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
	int selected=0;/*用户选择的菜单项*/
	system("cls");/*清屏*/
	printf(TITLE);/*显示标题*/
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

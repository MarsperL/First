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
	search_record,       //查询员工工资
	calculate,		     //工资排名
	save_to_file,          //保存到文件
	back_record,           //返回主界面菜单
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

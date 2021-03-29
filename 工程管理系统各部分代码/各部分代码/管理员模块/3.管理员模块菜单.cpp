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

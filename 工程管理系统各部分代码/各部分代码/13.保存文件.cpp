/*保存文件函数*/
void save_to_file()
{
	FILE *fp;
	char file[100];
	stu*p=head;
	printf("\n请输入文件名:\n");
	scanf("%s",file);
	fp=fopen(file,"w");
	while(p!=NULL)
	{
		fprintf(fp,"%s,%s,%s,%d,%d,%d,%d\n",p->num,p->name,p->sex,p->year,p->department);
		p=p->next;
	}
	fclose(fp);
	printf("\n保存成功（￣︶￣）↗\n按回车键返回菜单\n");
	getchar();     //接收最后从键盘录入的回车符
	getchar();
	print_menu_main();
}


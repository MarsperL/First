//������ 
/*�ַ�����menu_main�д���������˵�Ҫ��ʾ���ַ�*/
char menu_main[]=
"|\n"               
"|�� 1 ����Ա\n"     "\n"
"|�� 2 ��ͨ�û�\n"   "\n"
"|�� 3 �����ļ�\n"   "\n"
"|�� 4 �˳�ϵͳ\n"   "\n";   
//�˳�ϵͳ���ִ�����ڴ˴������� 
/*����ָ������menu_main_func����������˵���4�����ܺ�����
 *��ַ�ֱ��Ӧ1-4���˵���*/
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
	return 0;        //��ʾ���˵��ȴ��û���
}
/*��ʾ���˵�����*/
void print_menu_main()
{
	int selected=0;/*�û�ѡ��Ĳ˵���*/
	system("cls");/*����*/
	printf(TITLE);/*��ʾ����*/
	printf(menu_main);      /*��ʾ�˵��ַ�*/
	printf("��������������������������������������������������������\n");
	/*����û�û��ѡ�����ѡ�����ѭ���ȴ�*/
	while(!(selected>=1&&selected<=MENU_MAIN_COUNT))
	{
		printf("��������ѡ��");
		scanf("%d",&selected);
		getchar();
		if(selected>=1&&selected<=MENU_MAIN_COUNT)
			break;
		printf("\n> ������󣡣�ע����ѡ��1-%d��\n",MENU_MAIN_COUNT);
	}
	menu_main_func[selected-1]();/*�����û�ѡ��˵����Ӧ�ĺ���ָ�������еĺ���*/
} 
/*ȡ���������һ��ֵ����*/
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

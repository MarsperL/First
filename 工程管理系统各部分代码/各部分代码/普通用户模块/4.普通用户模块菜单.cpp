//��ͨ�û�ģ��˵� 
/*�ַ�����menu_user�д��������ͨ�û�ģ��Ҫ��ʾ���ַ�*/
char  menu_user[]=
"|\n"
"|> 1 ��ѯԱ������\n"           "\n"
"|> 2 �����Ų�ѯ��������\n"     "\n"
"|> 3 ���浽�ļ�\n"             "\n"
"|> 4 ����������˵�\n"  
"|\n";
/*����ָ������menu_user[]���������ͨ�û�ģ�鹦�ܺ�������Ӧ��
 4�����ܺ����ĵ�ַ���ֱ��Ӧ1-4�˵���*/
void (*menu_user_func[])()=  //��ͨ�û�ģ�鹦�ܺ����ڲ���� 
{
	search_record,       //��ѯԱ������
	calculate,		     //��������
	save_to_file,          //���浽�ļ�
	back_record,           //����������˵�
};
void user_record()
{
	int selected=0;
	system("cls");
	printf("\n(��^��^)�q >-->*��ͨ�û�ģ��˵�*<--�� �r(�ަأޣ�)\n");
	printf(menu_user);
	printf("===================================================\n");
	while(!(selected>=1&& selected<=MENU_USER_COUNT))
	{
		printf("> ��ѡ��");
		scanf("%d",&selected);
		getchar();      //�������Ӽ���¼��Ļس���
		if(selected>=1&& selected<=MENU_USER_COUNT)
		{
			break;
		}
		printf("\n> ������󣡣���ѡ��1-%d)\n",MENU_USER_COUNT);

	}
	menu_user_func[selected-1]();
}

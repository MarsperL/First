//����Աģ��˵� 
/*�ַ�����menu_manager�д�����ǹ���Աģ��Ҫ��ʾ���ַ�*/
char menu_manager[]=
"|\n"
"|> 1 ¼��Ա����Ϣ\n"       "\n" 
"|> 2 ��ʾ����Ա������\n"   "\n"
"|> 3 �޸�Ա����Ϣ\n"       "\n"
"|> 4 ɾ��Ա����Ϣ\n"       "\n"
"|> 5 ͳ�Ƹ���ְ��ݹ���\n" "\n"
"|> 6 �Ӹߵ�����ʾ����\n"   "\n"
"|> 7 ���浽�ļ�\n"         "\n"
"|> 8 ����������˵�\n"     
"|\n";
/*����ָ������menu_manager_func������ǹ���Աģ������Ӧ��
 *8�����ܺ����ĵ�ַ���ֱ��Ӧ1-8�˵���*/
void (*menu_manager_func[])()=
{  
	input_record,          //¼��Ա����Ϣ
	show_record,		   //��ʾ����Ա������
	update_record,         //�޸�Ա����Ϣ
	delete_record,         //ɾ��Ա����Ϣ
	count_record,          //ͳ�Ƹ���ְ��ݹ���
	sort,                  //�Ӹߵ�����ʾ����
	save_to_file,          //���浽�ļ�
	back_record,           //����������˵�
};
void manager_record()
{
	int selected=0;
	system("cls"); 
	printf("\n(��^��^)�q >-->*����Աģ��˵�*<--�� �r(�ަأޣ�)\n");
	printf(menu_manager);
	printf("===================================================\n");
	while(!(selected>=1&& selected<=MENU_MANAGER_COUNT))
	{
		printf("> ��ѡ��");
		scanf("%d",&selected);
		getchar();      //�������Ӽ���¼��Ļس���
		if(selected>=1&& selected<=MENU_MANAGER_COUNT)
		{
			break;
		}
		printf("\n> ������󣡣���ѡ��1-%d)\n",MENU_MANAGER_COUNT);
 
	}
	menu_manager_func[selected-1]();
} 
//�˳������Ӳ˵����������ص����˵�����
void sort_exit()
{
	manager_record();
} 
//�����ϼ��˵� 
void back_record()
{
	print_menu_main();
}

//��ѯԱ������ 
/*�ַ�����menu_search�д�����ǲ�ѯ�Ӳ˵���Ҫ��ʾ���ַ�*/
char menu_search[]=
"|\n"
"|> 1 ����ѧ�Ų�ѯ\n"  "\n"
"|> 2 ����������ѯ\n"  "\n"
"|> 3 �����ϼ��˵�\n"  
"|\n";
/*����ָ������menu_search_func������ǲ�ѯ�Ӳ˵�������Ӧ��
 *3�����ܺ����ĵ�ַ���ֱ��Ӧ1-3�˵���*/
void (*menu_search_func[])()=
{  
	search_by_id,
	search_by_name,
	search_exit,
};
/*��ѯԱ�����ʺ���*/
void search_record()
{
	int selected=0;
	system("cls");
	printf("\n(��^��^)�q >-->*��ѯԱ������*<--�� �r(�ަأޣ�)\n");
	printf(menu_search);
	printf("===================================================\n");
	while(!(selected>=1&& selected<=MENU_SEARCH_COUNT))
	{
		printf("> ��ѡ��");
		scanf("%d",&selected);
		getchar();      //�������Ӽ���¼��Ļس���
		if(selected>=1&& selected<=MENU_SEARCH_COUNT)
		{
			break;
		}
		printf("\n> ������󣡣���ѡ��1-%d)\n",MENU_SEARCH_COUNT);
	}
	menu_search_func[selected-1]();
}
/*�����Ų�ѯԱ�����ʺ���*/
void search_by_id()
{
	char id[MAX];
	char continue_input='N';
	stu* p=head;
	int isfound=0;
	printf("> ������Ա�����ţ�");
	scanf("%s",id);
	printf("\n> ����[%s]\n",id);
	while (p!=NULL)
	{
		if(strcmp(p->num,id)==0)
		{
			isfound=1;
			break;
		}
		p=p->next;
	}
	if(!isfound)
		printf("\nû���ҵ������\n");
	printf("�������ң���Y/y ������N/n ���أ�");
	getchar();
	continue_input=getchar();
	if(continue_input=='Y'||continue_input=='y')
	{
		search_by_id();
	}
	else
	{
		search_record();/*������ʾ��ѯ�Ӳ˵��������ز˵�*/
	}
}
/*�����ֲ�ѯԱ�����ʺ���*/
void search_by_name()
{
	char name[MAX];
	char continue_input='N';
	stu* p=head;
	int isfound=0;
	printf("> ������Ա��������");
scanf("%s",name);
	printf("\n> ����[%s]\n",name);
	while (p!=NULL)
	{
		if(strcmp(p->name,name)==0)
		{
			isfound=1;
		}
		p=p->next;
	}
	if(!isfound)
		printf("\nû���ҵ������\n");
	printf("\n�������ң���Y/y ������N/n ����\n��");
	getchar();
	continue_input=getchar();
	if(continue_input=='Y'||continue_input=='y')
	{
		search_by_name();
	}
	else
	{
		search_record();
	}
}

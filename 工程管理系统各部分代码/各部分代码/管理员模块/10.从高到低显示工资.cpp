//�Ӹߵ�����ʾ���� 
/*�ַ�����menu_sort�д�����ǴӸߵ�����ʾ���������Ӳ˵���Ҫ��ʾ���ַ�*/
char menu_sort[]=
"|\n"
"|> 1 ����ְ�����ʾ����\n"    "\n"
"|> 2 �����ڲ�����ʾ����\n"    "\n"
"|> 3 �����ϼ��˵�\n"          
"|\n";
/*����ָ������menu_sort_func������ǴӸߵ�����ʾ���������Ӳ˵�������Ӧ��
 *3�����ܺ����ĵ�ַ���ֱ��Ӧ1-3�˵���*/
void (* menu_sort_func[])()=
{	
	sort_year,
	sort_department,
	sort_exit,
};
/*�Ӹߵ�����ʾ���ʵĺ���*/
void sort()
{
	int selected=0;
	system("cls");//���� 
	printf("\n(��^��^)�q >-->*�Ӹߵ�����ʾ����*<--�� �r(�ަأޣ�)\n");
	printf(menu_sort);
	printf("===================================================\n");
	while(!(selected>=1&&selected<=MENU_SORT_COUNT))
	{
		printf("> ��ѡ��:");
		scanf("%d",&selected);
		getchar();         //�������Ӽ���¼��Ļس���
		if(selected>=1&&selected<=MENU_SORT_COUNT)
		{
			break;
		}
		printf("\n> �������!(��ѡ��1-%d)\n",MENU_SORT_COUNT);
	}
	menu_sort_func[selected-1]();    //����ѡ����Ӳ˵�����Ӧ�ĺ���
}
/*����ְ���������*/
void sort_year()
{
	int i=0;
	stu *p_1,*p_2,*temp_p,temp;
	printf("\n����ְ�������\n");
	for(p_1=p_2=head;p_1!=NULL || p_2!=NULL;p_1=p_1->next)
	{
		for(p_2=p_1->next;p_2!=NULL;p_2=p_2->next)	
			if(p_1->year<p_2->year)
			{
				temp=*p_1;*p_1=*p_2;*p_2=temp;	
				temp_p=p_1->next; p_1->next= p_2->next; p_2->next=temp_p;
			}	
		p_1->year=++i;
	}
	printf("\n���س���������һ�˵�\n");
	getchar();
	sort();
}
/*������������*/
void sort_department()
{
	int i=0;
	stu *p_1,*p_2,*temp_p,temp;
	printf("\n����������\n");
	for(p_1=p_2=head;p_1!=NULL || p_2!=NULL;p_1=p_1->next)
	{
		for(p_2=p_1->next;p_2!=NULL;p_2=p_2->next)
			if(p_1->department<p_2->department)
			{
				temp=*p_1;*p_1=*p_2;*p_2=temp;
				temp_p=p_1->next; p_1->next= p_2->next; p_2->next=temp_p;
			}	
		p_1->department=++i;	
	}
	printf("\n���س���������һ�˵�\n");
	getchar();
	sort();
}

//�����Ų�ѯ��������
/*�ַ�����menu_calculate�д�����ǹ��������Ӳ˵���Ҫ��ʾ���ַ�*/
char menu_calculate[]=
"|\n"
"| 1 �����ڲ��ŵĹ�������\n"   "\n"
"| 2 ����ְ��ݵĹ�������\n"   "\n"
"| 3 �����ϼ��˵�\n"          
"|\n";
/*����ָ������menu_calculate[]������ǹ��������Ӳ˵�������Ӧ��
 *3�����ܺ����ĵ�ַ���ֱ��Ӧ1-3�˵���*/
void (* menu_calculate_func[])()=
{	
	calc_department,
	calc_year,
	calc_exit,
};
/*�����Ų�ѯ���������ĺ���*/
void calculate()
{
	int selected=0;
	system("cls");
	printf("\n(��^��^)�q >-->*�����Ų�ѯ��������*<--�� �r(�ަأޣ�)\n");
	printf(menu_calculate);
	printf("===================================================\n");
	while(!(selected>=1&&selected<=MENU_CALC_COUNT))
	{
		printf("> ��ѡ��:");
		scanf("%d",&selected);
		getchar();         //�������Ӽ���¼��Ļس���
		if(selected>=1&&selected<=MENU_CALC_COUNT)
		{
			break;
		}
		printf("\n> �������!(��ѡ��1-%d)\n",MENU_CALC_COUNT);
	}
	menu_calculate_func[selected-1]();                    //����ѡ����Ӳ˵�����Ӧ�ĺ���
}
/*�����ڲ���������*/
void calc_department()
{
	int i=0;
	stu *p_1,*p_2,*temp_p,temp;
	printf("\n�����ڲ�������\n");
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
	calculate(); 
}
/*����ְ���������*/
void calc_year()
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
	calculate();
}
void calc_exit()
{
	user_record();
}

#include<stdio.h>                 
#include<stdlib.h>               
#include<string.h>                
#define TITLE "\n(��^��^)�q >-->*<<<���ʹ���ϵͳ>>>*<--�� �r(�ަأޣ�)    ������� 19031110114\n"       /*��������*/ 
#define MAX 10
#define MENU_MAIN_COUNT 4          /*���˵���ѡ�����*/  
#define MENU_MANAGER_COUNT 8       /*����Աģ��˵��Ӻ�������*/ 
#define MENU_USER_COUNT 4          /*��ͨ�û�ģ��˵��Ӻ�������*/ 
#define MENU_SEARCH_COUNT 3        /*��ѯԱ�������Ӳ˵���ѡ�����*/
#define MENU_CALC_COUNT 3          /*�����Ų�ѯ���������Ӳ˵���ѡ�����*/
#define MENU_SORT_COUNT 3          /*����Ա���ʸߵ������Ӳ˵���ѡ�����*/
typedef struct staff
{
char name[MAX];            /*����*/
char num[MAX];             /*����*/    
char sex[MAX];             /*�Ա�*/
char department;           /*����*/
int money;                 /*����*/ 
int year;                  /*��ְ���*/
struct staff *next;        /*ָ����һ��Ա����ָ��*/
}stu;
/*����һ��ͷ�ڵ�*/
stu* head;                 /*staff�ṹ�������ͷ�ڵ�*/
/*��Ҫ����������*/
//����Ա�˵�ģ�飺 
void input_record();       /*¼��Ա����Ϣ����*/
void show_record();        /*��ʾ����Ա�����ʴ���*/ 
void update_record();      /*�޸�Ա����Ϣ*/
void delete_record();      /*ɾ��Ա����Ϣ*/
void count_record();       /*ͳ�Ƹ���ְ��ݹ���*/
void sort();               /*Ա����������*/
void save_to_file();       /*���浽�ļ��Ĵ���*/
void back_record();        /*�����ϼ��˵�*/
//��ͨ�û��˵�ģ�飺
void search_record();      /*��ѯԱ�����ʵĴ���*/ 
void calculate();          /*��������*/ 
void save_to_file();       /*���浽�ļ��Ĵ���*/
void back_record();        /*�˳�ϵͳ*/
/*��ѯԱ�������Ӻ�������*/
//��ͨ�û�ģ�飺 
void search_by_id();       /*ͨ�����ż���Ա���Ĵ���*/
void search_by_name();     /*ͨ����������Ա���Ĵ���*/
void search_exit();        /*�˳��Ӳ˵��������ϼ��˵�*/
/*���������Ӻ�������*/
void calc_department();    /*�����ڲ�������Ĵ���*/
void calc_year();          /*����ְ�������Ĵ���*/
void calc_exit();          /*�˳��Ӳ˵��������ϼ��˵�*/
/*���ʸߵ������Ӻ�������*/
//����Աģ�飺 
void sort_year();          /*����ְ�������Ĵ���*/
void sort_department();    /*����������Ĵ���*/
void sort_exit();          /*�˳��Ӳ˵��������ϼ��˵�*/
/*������������*/
void create_stu_by_input(stu* pNewStu);      /*ͨ������ΪSTAFF��ֵ*/
stu* get_last_STAFF(stu* p);                 /*�ҵ����һ��Ա���ļ�¼*/
void clear_record(stu* p);                   /*������м�¼*/
/*��ʾ���ƺ�������*/
void print_menu_main();                      //��ʾ���˵�
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
	search_record,           //��ѯԱ������
	calculate,		         //��������
	save_to_file,            //���浽�ļ�
	back_record,             //����������˵�
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
//������ 
/*�ַ�����menu_main�д���������˵�Ҫ��ʾ���ַ�*/
char menu_main[]=
"|\n"               
"|�� 1 ����Ա\n"     "\n"
"|�� 2 ��ͨ�û�\n"   "\n"
"|�� 3 �����ļ�\n"   "\n"
"|�� 4 �˳�ϵͳ\n"   "\n";
//�˳�ϵͳ����
void exit_system()
{
	clear_record(head);    //�ͷ���������
	exit(0);
}
/*������м�¼����*/
void clear_record(stu* p)
{
	if(p==NULL)
	{
		return;
	}
   /*���staff�ṹ���nextָ���ǿ�*
	*���ʾû����һ�����ݣ�ɾ���ýڵ�*/
	if(p->next==NULL)
	{
		free(p);
	}
    /*���staff�ṹ���nextָ�벻Ϊ�գ�*/
	else
	{
		clear_record(p->next);/*�ٴε��ñ�������staff�ṹ��nextָ��Ľڵ���Ϊ����*/
		free(p);/*ɾ����ǰ�ڵ�*/
		p=NULL;/*��ָ���ÿ�*/
	}
}
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
	int selected=0;         /*�û�ѡ��Ĳ˵���*/
	system("cls");          /*����*/
	printf(TITLE);          /*��ʾ����*/
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
/*¼��Ա����Ϣ����*/
void input_record()
{
	char continue_input='N';
	stu* pLastStu=NULL;
	stu* pNewStu=(stu*)malloc(sizeof(stu)); /*����һ��stu*/
	pNewStu->next=NULL;
	create_stu_by_input(pNewStu);           /*���û�Ϊ������stu��ֵ*/
	if(head==NULL)/*һ����û��*/
	{
		head=pNewStu;
	}
	else
	{
		pLastStu=get_last_staff(head);      /*�ҵ����һ��*/
		pLastStu->next=pNewStu;
	}
	printf("\n����¼��Ա����Ϣ����Y/y ������N/n ���ز˵���\n");
	getchar();
	continue_input=getchar();
	if(continue_input=='n'||continue_input=='N')
	{
		print_menu_main();/*���������룬����ʾ���˵�*/
	}
	else
	{
		input_record();/*�ٴε����������¼���µ�Ա����Ϣ*/
	}
}
/*��ʾ¼��Ա����Ϣ����*/
void create_stu_by_input(stu* pNewStu)
{
	printf("> ������Ա����Ϣ��ע����󳤶���10���ַ���\n");
	printf("���ţ�");scanf("%s",pNewStu->num);
	printf("������");scanf("%s",pNewStu->name);
	printf("�Ա�");scanf("%s",pNewStu->sex);
	printf("���ʣ�");scanf("%d",&(pNewStu->money));
	printf("��ְ��ݣ�");scanf("%d",&(pNewStu->year));
	printf("���ţ�");scanf("%s",&(pNewStu->department));
}
void display()
{
    FILE *fp;
    char buff[999999];
    printf("> �������ļ�����");
    scanf("%s",buff);
    fp=fopen(buff,"rb");    //���ļ�
    char ch;
    if(fp==NULL)   
	{
           printf("cann't open file");
           exit(0);
    }
    while((ch=fgetc(fp))!=EOF)    //�����ļ�������ѭ��
    {
    	 putchar(ch);          
	}
    fclose(fp);            //�ر��ļ�ָ��   
    getchar();
}
/*��ʾԱ����Ϣ����*/
void show_record()
{
	stu* p=head;
    display();
	while(p!=NULL)
	{
		p=p->next;
	}
	printf("���س������ز˵�\n");
	getchar();
      manager_record();
}
/*�޸�Ա����Ϣ����*/
void update_record()
{
	stu*p=head;
	char id[MAX];
	char continue_input='N';
	printf("\n������Ҫ�޸�Ա����Ϣ�Ĺ���:\n");
	scanf("%s",id);
	while(p!=NULL)
	{
		if(strcmp(p->num,id)==0)
		{
			break;
		}
		p=p->next;
	}
	if(p==NULL)
	{
		printf("û�й�����[%s]��Ա��.\n",id);
	}
	else
	{
		create_stu_by_input(p);
	}
	printf("\n����������?(Y/y������N/n���ز˵�)\n");
	getchar();     //�������Ӽ���¼��Ļس���
	continue_input=getchar();
	if(continue_input=='n'||continue_input=='N')
	{
		print_menu_main();
	}
	else
	{
		update_record();
	}
}
/*ɾ��Ա����Ϣ����*/
void delete_record()
{
	stu *p=head;
	stu *pPre=NULL;
	char id[MAX];
	char continue_input='N';
	printf("\n������Ҫɾ����Ա������:\n");
	scanf("%s",id);
	while(p!=NULL)
	{
		if(strcmp(p->num,id)==0)
		{
			break;
		}
		p=p->next;
	}
	if(p==NULL)
	{
       printf("û�й�����[%s]��Ա��.\n",id);
	}
	else
	{
		printf("\nȷ��Ҫɾ������Ϊ[%s]����Ϊ[%s]��Ա����(Y/yȷ��,N/nȡ��)\n",p->num,p->name);
		getchar();
		continue_input=getchar();
		if(continue_input=='y'||continue_input=='Y')
		{
			pPre=head;
			if(pPre==p)
			{
				head=p->next;
                free(p);
			}
			else
			{
				while(pPre!=NULL)
				{
					if(pPre->next==p)
					{
						pPre->next=p->next;
						free(p);
						break;
					}
				pPre=pPre->next;
				}
			}
			printf("ɾ���ɹ�!\n");
		}
	}
	printf("\n����ɾ����?(Y/y����,N/n���ز˵�)\n");
	getchar();        //�������Ӽ���¼��Ļس���
	continue_input=getchar();
	if(continue_input=='n'||continue_input=='N')
	{
		print_menu_main();
	}
	else
	{
		delete_record();
	}
}
//ͳ�Ƹ���ְ��ݹ���
void count_record()
{
	int i=0;
	stu *p_1,*p_2,*temp_p,temp;
	printf("\n*ͳ�Ƹ���ְ��ݹ���*\n");
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
	print_menu_main();
}
void search_exit()//��ѯԱ�������Ӳ˵�������ͨ�û�ģ��˵� 
{
	user_record();//�û�ģ��˵� 
}
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
//��ѯԱ������ 
/*�ַ�����menu_search�д�����ǲ�ѯ�Ӳ˵���Ҫ��ʾ���ַ�*/
char menu_search[]=
"|\n"
"|> 1 ���չ��Ų�ѯ\n"  "\n"
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
	printf("\n�������ң���Y/y ������N/n ���أ�\n");
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
/*���浽�ļ�����*/
void save_to_file()
{
	FILE *fp;
	char file[100];
	stu*p=head;
	printf("\n�������ļ���:\n");
	scanf("%s",file);
	fp=fopen(file,"w");
	while(p!=NULL)
	{
		fprintf(fp,"%s %s %s %d %d %d\n",p->num,p->name,p->sex,p->year,p->department,p->money);
		p=p->next;
	}
	fclose(fp);
	printf("\n����ɹ�����������J\n���س������ز˵�\n");
	getchar();     //�������Ӽ���¼��Ļس���
	getchar();
	print_menu_main();
}


#include<stdio.h>                 
#include<stdlib.h>               
#include<string.h>                
#define TITLE "\n(��^��^)�q->*<<<���ݷֲ�>>>*<-�r(�ަأޣ�)    MarsperL \n"       /*��������*/ 
#define MAX 10
#define MENU_MAIN_COUNT 2          /*���˵���ѡ�����*/  
#define MENU_MANAGER_COUNT 2      /*ִ�зֲ�����ģ���Ӻ�������*/ 
typedef struct staff
{
struct staff *next;        
}stu;
/*����һ��ͷ�ڵ�*/
stu* head;                 /*staff�ṹ�������ͷ�ڵ�*/
/*��Ҫ����������*/
void rev();
void manager_record();
void print_menu_main();
void exit_system();
void back_record();        /*�����ϼ��˵�*/
//������ 
/*�ַ�����menu_main�д���������˵�Ҫ��ʾ���ַ�*/
char menu_main[]=
"\n"               
"|�� 1 ִ�зֲ�����\n"     "\n"
"|�� 2 �˳�\n"   "\n";    
/*����ָ������menu_main_func����������˵���4�����ܺ�����
 *��ַ�ֱ��Ӧ1-2���˵���*/
void (*menu_main_func[])()=
{
	manager_record, 
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
	printf("(��������)��(��������)��(��������)��(��������)��(��������)��\n");
	/*����û�û��ѡ�����ѡ�����ѭ���ȴ�*/
	while(!(selected>=1&&selected<=MENU_MAIN_COUNT))
	{
		printf("> ��ѡ��");
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
//ִ�зֲ�����ģ��
/*�ַ�����menu_manager�д������ִ�зֲ�����ģ��Ҫ��ʾ���ַ�*/
char menu_manager[]=
"\n"
"|> 1 ִ�з��ݷֲ�����\n"
"\n"
"|> 2 ����������˵�\n"     
"\n";
void (*menu_manager_func[])()=
{  
	rev,         
	back_record, //����������˵�
};
void manager_record()//ִ�з��ݷֲ�����ģ�� 
{
	int selected=0;
	system("cls"); 
	printf("\n(��^��^)�q >-->*ִ�зֲ�����ģ��*<--�� �r(�ަأޣ�)  MarsperL\n");
	printf(menu_manager);
	printf("(��������)��(��������)��(��������)��(��������)��\n");
	while(!(selected>=1&& selected<=MENU_MANAGER_COUNT))
	{
		printf("> ��ѡ��");
		scanf("%d",&selected);
		getchar();      //�������Ӽ���¼��Ļس���
		if(selected>=1&& selected<=MENU_MANAGER_COUNT)
			break;
		printf("\n> ������󣡣���ѡ��1-%d)\n",MENU_MANAGER_COUNT);
 
	}
	menu_manager_func[selected-1]();
} 
//�˳��Ӳ˵����������ص����˵�����
void sort_exit()
{
	manager_record();
} 
//�����ϼ��˵� 
void back_record()
{
	print_menu_main();
}
//�˳�ϵͳ����
void exit_system()
{
	exit(0);
}
//���ݷֲ���Ҫ���� 
typedef struct Node * Heap; /*�ѽṹ*/
struct Node
{
	int * Data;
	int Size;
};
typedef Heap MinHeap;/*��С��*/
Heap CreateHeap(int n)//��С�ѵĴ���
{
	MinHeap H=(MinHeap)malloc(sizeof(struct Node));
	H->Data=(int *)malloc(2*(n+1)*sizeof(int));
	H->Size=0;//��ʼ�� 
	H->Data[0]=0;/*��С�ѵ��ڱ�*/
	return H;
}
void Insert(Heap H,int m)//������
{
	int i;
	i=++H->Size;
	for(; H->Data[i/2]>m; i/=2)
		H->Data[i]=H->Data[i/2];
	H->Data[i]=m;
}
int Del(Heap H)//�ؽ�С����
{
	int parent,child;
	int min,x;
	min=H->Data[1];
	x=H->Data[H->Size--];//�����һ��Ԫ������Ѿ�����ĶѶ�Ԫ��
	for(parent=1; parent*2<=H->Size ; parent=child) //�ؽ�С�ĺ�������ɸѡ
	{
   	child=parent*2;
	if((child!=H->Size)&&(H->Data[child]>H->Data[child+1])) child++;
	if(H->Data[child]>=x) break;
	else H->Data[parent]=H->Data[child];
   }
H->Data[parent]=x;
return min;
}
void rev()
{
	char continue_input='N';
	int n,m,i,sum=0,a,b;
	printf("������ʵ�����ݣ�\n"); 
	scanf("%d",&n);
	Heap H=CreateHeap(n);
	for(i=1; i<=n; i++)
	{
		scanf("%d",&m);
		Insert(H,m);/*������Ԫ�����(H)*/
	}
	while(H->Size!=1)
	{
		a=Del(H);//ȥ����Сֵ���ؽ���
		b=Del(H);//ȥ����Сֵ���ؽ���
		b=a+b;
		sum+=b;//�����ۼ����
		Insert(H,b);
	}
	printf("%d",sum);
	printf("\n����ִ�з��ݷֲ����񣿣�Y/y ������N/n ���ز˵���\n");
	getchar();
	continue_input=getchar();
	if(continue_input=='n'||continue_input=='N')
	{
		print_menu_main();/*���������룬����ʾ���˵�*/
	}
	else if(continue_input=='y'||continue_input=='Y') 
	{
		rev();/*�ٴε����������ִ�з��ݷֲ�����*/
	} 
	else
	{
		printf("\n> ���������ѡ��Y/y(����)��N/n(���ز˵�) \n");
		getchar();
		continue_input=getchar();
		if(continue_input=='n'||continue_input=='N')
			print_menu_main();/*���������룬����ʾ���˵�*/
		else if(continue_input=='y'||continue_input=='Y') 
			rev();/*�ٴε����������ִ�з��ݷֲ�����*/
	}
}


#include<stdio.h>                 
#include<stdlib.h>               
#include<string.h>                
#define TITLE "\n(��^��^)�q >-->*<<<���ʹ���ϵͳ>>>*<--�� �r(�ަأޣ�)    �������\n"       /*��������*/ 
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

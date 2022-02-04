#include<stdio.h>                 
#include<stdlib.h>               
#include<string.h>                
#define TITLE "\n(ｏ^ω^)╭ >-->*<<<工资管理系统>>>*<--＜ ╮(＾ω＾ｏ)    云沐灵风\n"       /*标题文字*/ 
#define MAX 10
#define MENU_MAIN_COUNT 4          /*主菜单的选项个数*/  
#define MENU_MANAGER_COUNT 8       /*管理员模块菜单子函数个数*/ 
#define MENU_USER_COUNT 4          /*普通用户模块菜单子函数个数*/ 
#define MENU_SEARCH_COUNT 3        /*查询员工工资子菜单的选项个数*/
#define MENU_CALC_COUNT 3          /*按工号查询工资排名子菜单的选项个数*/
#define MENU_SORT_COUNT 3          /*管理员工资高低排序子菜单的选项个数*/
typedef struct staff
{
char name[MAX];            /*姓名*/
char num[MAX];             /*工号*/    
char sex[MAX];             /*性别*/
char department;           /*部门*/
int money;                 /*工资*/ 
int year;                  /*入职年份*/
struct staff *next;        /*指向下一个员工的指针*/
}stu;
/*定义一个头节点*/
stu* head;                 /*staff结构体链表的头节点*/
/*主要处理函数声明*/
//管理员菜单模块： 
void input_record();       /*录入员工信息处理*/
void show_record();        /*显示所有员工工资处理*/ 
void update_record();      /*修改员工信息*/
void delete_record();      /*删除员工信息*/
void count_record();       /*统计各入职年份工资*/
void sort();               /*员工工资排序*/
void save_to_file();       /*保存到文件的处理*/
void back_record();        /*返回上级菜单*/
//普通用户菜单模块：
void search_record();      /*查询员工工资的处理*/ 
void calculate();          /*工资排名*/ 
void save_to_file();       /*保存到文件的处理*/
void back_record();        /*退出系统*/
/*查询员工工资子函数声明*/
//普通用户模块： 
void search_by_id();       /*通过工号检索员工的处理*/
void search_by_name();     /*通过姓名检索员工的处理*/
void search_exit();        /*退出子菜单，返回上级菜单*/
/*工资排名子函数声明*/
void calc_department();    /*按所在部门排序的处理*/
void calc_year();          /*按入职年份排序的处理*/
void calc_exit();          /*退出子菜单，返回上级菜单*/
/*工资高低排序子函数声明*/
//管理员模块： 
void sort_year();          /*按入职年份排序的处理*/
void sort_department();    /*按部门排序的处理*/
void sort_exit();          /*退出子菜单，返回上级菜单*/
/*辅助函数声明*/
void create_stu_by_input(stu* pNewStu);      /*通过输入为STAFF赋值*/
stu* get_last_STAFF(stu* p);                 /*找到最后一个员工的记录*/
void clear_record(stu* p);                   /*清空所有记录*/
/*显示控制函数声明*/
void print_menu_main();                      //显示主菜单

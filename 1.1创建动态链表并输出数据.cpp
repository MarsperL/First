  /*编写函数，实现动态的创建一个链表，然后输出链表中所有结点的数据。
编程提示：函数create功能是创建一个结点，
并把该结点添加到链表中。新建结点需要动态分配内存空间，
让指针变量p指向新建结点。函数返回链表的头指针。
输入：10001 91   输出：10001 91.0 
10002 92               10002 92.0
10003 85 			   10003 85.0
10004 90.5			   10004 90.5
10005 90			   10005 90.0
0 0
*/ 
#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct Link)
struct Link
{
    int num;
    float score;
    struct Link *next;
} ;
int n; 
int main()
{
    struct Link *head;     
    struct Link *creat( );         /* creat函数为建立链表函数 */
    void output(struct Link *head); /* output函数为输出链表函数 */
    head=creat();
    output(head);     
    return 0;
}
struct Link *creat()
{
    struct Link *p1,*p2,*head;
    n=0;
    p1=p2=(struct Link *) malloc(LEN);   
	/* 开辟一个新的空间   新建结点需要动态分配内存空间 */
scanf("%d%f",&p1->num,&p1->score);
    head=NULL;
    while(p1->num!=0)      /* 输入num为0时 即信息输完后，循环结束 */
     {
        n=n+1;
        if(n==1)//链表为空表：新建的结点为头结点
            head=p1;//将头指针指向头节点  
        else//链表不是空表：新建的结点添加到表尾 
            p2->next=p1;//组织不了语言 >_< （看第8章资料上的图） 
        p2=p1;
        p1=(struct Link *)malloc(LEN);//新建结点需要动态分配内存空间 
        scanf("%d%f",&p1->num,&p1->score);
    }
    p2->next=NULL;//最后一个结点的指针域为空指针 
    return(head);
}
void output(struct Link *head)
{
    struct Link *p;
    p=head;
if(head!=NULL)///链表不为空表 
        do
        {
            printf("%d %6.1f\n",p->num,p->score);
            p=p->next;
        }while(p!=NULL);//最后一个结点的指针域为空指针，此时循环结束  
}
//加入部分测试2.1233443 

  /*��д������ʵ�ֶ�̬�Ĵ���һ������Ȼ��������������н������ݡ�
�����ʾ������create�����Ǵ���һ����㣬
���Ѹý����ӵ������С��½������Ҫ��̬�����ڴ�ռ䣬
��ָ�����pָ���½���㡣�������������ͷָ�롣
���룺10001 91   �����10001 91.0 
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
    struct Link *creat( );         /* creat����Ϊ���������� */
    void output(struct Link *head); /* output����Ϊ��������� */
    head=creat();
    output(head);     
    return 0;
}
struct Link *creat()
{
    struct Link *p1,*p2,*head;
    n=0;
    p1=p2=(struct Link *) malloc(LEN);   
	/* ����һ���µĿռ�   �½������Ҫ��̬�����ڴ�ռ� */
scanf("%d%f",&p1->num,&p1->score);
    head=NULL;
    while(p1->num!=0)      /* ����numΪ0ʱ ����Ϣ�����ѭ������ */
     {
        n=n+1;
        if(n==1)//����Ϊ�ձ��½��Ľ��Ϊͷ���
            head=p1;//��ͷָ��ָ��ͷ�ڵ�  
        else//�����ǿձ��½��Ľ����ӵ���β 
            p2->next=p1;//��֯�������� >_< ������8�������ϵ�ͼ�� 
        p2=p1;
        p1=(struct Link *)malloc(LEN);//�½������Ҫ��̬�����ڴ�ռ� 
        scanf("%d%f",&p1->num,&p1->score);
    }
    p2->next=NULL;//���һ������ָ����Ϊ��ָ�� 
    return(head);
}
void output(struct Link *head)
{
    struct Link *p;
    p=head;
if(head!=NULL)///����Ϊ�ձ� 
        do
        {
            printf("%d %6.1f\n",p->num,p->score);
            p=p->next;
        }while(p!=NULL);//���һ������ָ����Ϊ��ָ�룬��ʱѭ������  
}
//���벿�ֲ���2.1233443 

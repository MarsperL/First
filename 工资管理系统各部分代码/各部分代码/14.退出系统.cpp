//退出系统函数
void exit_system()
{
	clear_record(head);    //释放整个链表
	exit(0);
}
/*清空所有记录函数*/
void clear_record(stu* p)
{
	if(p==NULL)
	{
		return;
	}
   /*如果staff结构体的next指针是空*
	*则表示没有下一条数据，删除该节点*/
	if(p->next==NULL)
	{
		free(p);
	}
    /*如果staff结构体的next指针不为空，*/
	else
	{
		clear_record(p->next);/*再次调用本函数，staff结构体next指向的节点作为参数*/
		free(p);/*删除当前节点*/
		p=NULL;/*将指针置空*/
	}
}

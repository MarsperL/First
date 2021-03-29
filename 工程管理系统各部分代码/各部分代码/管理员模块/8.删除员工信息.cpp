/*删除员工信息函数*/
void delete_record()
{
	stu *p=head;
	stu *pPre=NULL;
	char id[MAX];
	char continue_input='N';
	printf("\n请输入要删除的员工工号:\n");
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
       printf("没有工号是[%s]的员工.\n",id);
	}
	else
	{
		printf("\n确定要删除工号为[%s]姓名为[%s]的员工吗？(Y/y确定,N/n取消)\n",p->num,p->name);
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
			printf("删除成功!\n");
		}
	}
	printf("\n继续删除吗?(Y/y继续,N/n返回菜单\n)");
	getchar();        //接收最后从键盘录入的回车符
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

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

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
	printf("\n����ɾ����?(Y/y����,N/n���ز˵�\n)");
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

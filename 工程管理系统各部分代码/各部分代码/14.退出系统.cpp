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

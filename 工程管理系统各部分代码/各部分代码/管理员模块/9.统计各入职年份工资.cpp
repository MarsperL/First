//ͳ�Ƹ���ְ��ݹ���
void count_record()
{
	int i=0;
	stu *p_1,*p_2,*temp_p,temp;
	printf("\n*ͳ�Ƹ���ְ��ݹ���*\n");
	for(p_1=p_2=head;p_1!=NULL || p_2!=NULL;p_1=p_1->next)
	{
		for(p_2=p_1->next;p_2!=NULL;p_2=p_2->next)
			if(p_1->year<p_2->year)
			{
				temp=*p_1;*p_1=*p_2;*p_2=temp;
				temp_p=p_1->next; p_1->next= p_2->next; p_2->next=temp_p;
			}	
		p_1->year=++i;	
	}
	printf("\n���س���������һ�˵�\n");
	getchar();
	print_menu_main();
}
void search_exit()//��ѯԱ�������Ӳ˵�������ͨ�û�ģ��˵� 
{
	user_record();//�û�ģ��˵� 
}

/*¼��Ա����Ϣ����*/
void input_record()
{
	char continue_input='N';
	stu* pLastStu=NULL;
	stu* pNewStu=(stu*)malloc(sizeof(stu));/*����һ��stu*/
	pNewStu->next=NULL;
	create_stu_by_input(pNewStu);/*���û�Ϊ������stu��ֵ*/
	if(head==NULL)/*һ����û��*/
	{
		head=pNewStu;
	}
	else
	{
		pLastStu=get_last_staff(head);/*�ҵ����һ��*/
		pLastStu->next=pNewStu;
	}
	printf("\n����¼��Ա����Ϣ����Y/y ������N/n ���ز˵���\n");
	getchar();
	continue_input=getchar();
	if(continue_input=='n'||continue_input=='N')
	{
		print_menu_main();/*���������룬����ʾ���˵�*/
	}
	else
	{
		input_record();/*�ٴε����������¼���µ�Ա����Ϣ*/
	}
}
/*��ʾ¼��Ա����Ϣ����*/
void create_stu_by_input(stu* pNewStu)
{
	printf("> ������Ա����Ϣ��ע����󳤶���10���ַ���\n");
	printf("���ţ�");scanf("%s",pNewStu->num);
	printf("������");scanf("%s",pNewStu->name);
	printf("�Ա�");scanf("%s",pNewStu->sex);
	printf("���ʣ�");scanf("%d",&(pNewStu->money));
	printf("��ְ��ݣ�");scanf("%d",&(pNewStu->year));
	printf("���ţ�");scanf("%s",&(pNewStu->department));
}

/*��ʾԱ����Ϣ����*/
void show_record()
{
	stu* p=head;
    display();
	while(p!=NULL)
	{
		p=p->next;
	}
	printf("���س������ز˵�\n");
	getchar();
	print_menu_main();
}

/*�����ļ�����*/
void save_to_file()
{
	FILE *fp;
	char file[100];
	stu*p=head;
	printf("\n�������ļ���:\n");
	scanf("%s",file);
	fp=fopen(file,"w");
	while(p!=NULL)
	{
		fprintf(fp,"%s,%s,%s,%d,%d,%d,%d\n",p->num,p->name,p->sex,p->year,p->department);
		p=p->next;
	}
	fclose(fp);
	printf("\n����ɹ�����������J\n���س������ز˵�\n");
	getchar();     //�������Ӽ���¼��Ļس���
	getchar();
	print_menu_main();
}


/*void display()
{
    FILE *fp;
    char buff[999999];
    printf("�������ļ���");
    scanf("%s",buff);
    fp=fopen(buff,"rb");    //���ļ�
    char ch;
    while((ch=fgetc(fp))!=EOF)    //�����ļ�������ѭ��
    {
    	 putchar(ch);          //���һ���ַ�
	}
    fclose(fp);            //�ر��ļ�ָ��   
    getchar();
}*/
void display()
{
    FILE *fp;
    char buff[999999];
    printf("�������ļ���");
    scanf("%s",buff);
    fp=fopen(buff,"rb");    //���ļ�
    char ch;
    if(fp==NULL)   
	{
           printf("cann't open file");
           exit(0);
    }
    while((ch=fgetc(fp))!=EOF)    //�����ļ�������ѭ��
    {
    	 putchar(ch);          //���һ���ַ�
	}
    fclose(fp);            //�ر��ļ�ָ��   
    getchar();
}

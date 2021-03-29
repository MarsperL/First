/*void display()
{
    FILE *fp;
    char buff[999999];
    printf("请输入文件名");
    scanf("%s",buff);
    fp=fopen(buff,"rb");    //打开文件
    char ch;
    while((ch=fgetc(fp))!=EOF)    //不到文件结束就循环
    {
    	 putchar(ch);          //输出一个字符
	}
    fclose(fp);            //关闭文件指针   
    getchar();
}*/
void display()
{
    FILE *fp;
    char buff[999999];
    printf("请输入文件名");
    scanf("%s",buff);
    fp=fopen(buff,"rb");    //打开文件
    char ch;
    if(fp==NULL)   
	{
           printf("cann't open file");
           exit(0);
    }
    while((ch=fgetc(fp))!=EOF)    //不到文件结束就循环
    {
    	 putchar(ch);          //输出一个字符
	}
    fclose(fp);            //关闭文件指针   
    getchar();
}

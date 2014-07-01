#include <stdio.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h> 
#define NULL 0
#define LEN sizeof(struct worker)


struct worker{
	char number[20];
	char name[20];
	int late;
	int earlyleave;
	int notwork;
	struct worker *next;
};

typedef struct now{
	int year;
	int month;
	int day;
	int weekday;
	int hour;
	int minute;

}NOW;
NOW nowtime;

 struct worker *head=NULL,*p1,*p2,*p3;/*定义结构体指针head 为头指针p1 为输入数据缓存空间指针p2 为尾指针*/
 int writenflag=0;


void welcome();					/*欢迎函数*/

void menuprint();				/*主菜单打印*/
void loadinf();					/*从磁盘导入职工信息到内存*/

void monuprecord();				/*上午上班时间录入*/
void mondownrecord();			/*上午下班时间录入*/

void afteruprecord();			/*下午上班时间录入*/
void afterdownrecord();			/*下午下班时间录入*/

void evenuprecord();			/*晚上上班时间录入*/
void evendownrecord();			/*晚上下班时间录入*/

void allprint();				/*显示所有职工信息*/
void seek();					/*查找*/
void change();					/*修改*/
void cutoff();					/*删除*/
void inforsave();				/*保存考勤信息*/
void quit();					/*退出*/

int input();					/*输入选择*/
void getjudge(char wh[]);		/*输入判断*/
void putsecret();				/*密码*/




int main()
{
	welcome();											/*欢迎函数*/
	menuprint();
	loadinf();

	system("cls");

	for(;;)
	{	
		switch(input())										/*显示主菜单*/
		{				
			case 1:monuprecord();break;						/*上午上班时间录入*/
			case 2:mondownrecord();break;					/*上午下班时间录入*/
			case 3:afteruprecord();break;					/*下午上班时间录入*/
			case 4:afterdownrecord();break;					/*下午下班时间录入*/
			case 5:evenuprecord();break;					/*晚上上班时间录入*/
			case 6:evendownrecord();break;					/*晚上下班时间录入*/
			case 7:allprint();break;						/*显示所有职工信息*/
			case 8:seek();break;							/*查找*/
			case 9:change();break;							/*修改*/
			case 10:cutoff();break;							/*删除*/
			case 11:inforsave();	system("cls");break;	/*保存考勤信息*/
			case 12:system("cls");quit();return 0;			/*退出*/
			default:{

				rewind(stdin);
				printf("\n\n输入错误，按任意键返回.....\n");			
				getch();
				
				system("cls");		/*清屏*/
					}
		}
	}
	return 0;
}

void welcome()
{

	printf("\n\n\n\n\t\t***************************************************\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* *  \t\t\t\t\t\t* *\n");
	printf("\t\t* *  \t\t\t\t\t\t* *\n");
	printf("\t\t* *  \t    欢 迎 使 用 考 勤 系 统 ！    \t* *\n");
	printf("\t\t* *  \t\t\t\t\t\t* *\n");
	printf("\t\t* *  \t\t\t\t\t\t* *\n");
	printf("\t\t* *  \t\t\t\t\t\t* *\n");
	printf("\t\t* *  \t\t\t\t\t\t* *\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* * * * * * 请 按 任 意  键 进 入 系 统 * * * * * *\n");
	printf("\t\t***************************************************\n");
	getch();
	system("cls");
	rewind(stdin);

}





int input()
{
	int c;

	printf("***********************************主菜单**************************************\n");
	printf("*\t\t\t\t\t\t\t\t\t      *\n");
	printf("*\t\t\t\t1.上午上班时间录入。                          *\n");
	printf("*\t\t\t\t2.上午下班时间录入。                          *\n");
	printf("*\t\t\t\t3.下午上班时间录入。                          *\n");
	printf("*\t\t\t\t4.下午下班时间录入。                          *\n");
	printf("*\t\t\t\t5.晚上上班时间录入。                          *\n");
	printf("*\t\t\t\t6.晚上下班时间录入。                          *\n");
	printf("*\t\t\t\t7.职工整体出勤情况浏览。                      *\n");
	printf("*\t\t\t\t8.查询考勤记录。                              *\n");
	printf("*\t\t\t\t9.修改考勤记录。                              *\n");
	printf("*\t\t\t\t10.删除考勤记录。                             *\n");
	printf("*\t\t\t\t11.保存考勤记录。                             *\n");
	printf("*\t\t\t\t12.退出。（任何情况下按ctrl+c退出）           *\n");
	printf("*\t\t\t\t\t\t\t\t\t      *\n");
	printf("*******************************************************************************\n");
	printf("请输入你的选择（0~12）：");
	scanf("%d",&c);
	rewind(stdin);
	return c;
}


/*主菜单*/
void menuprint()
{

	printf("***********************************主菜单**************************************\n");
	printf("*\t\t\t\t\t\t\t\t\t      *\n");
	printf("*\t\t\t\t1.上午上班时间录入。                          *\n");
	printf("*\t\t\t\t2.上午下班时间录入。                          *\n");
	printf("*\t\t\t\t3.下午上班时间录入。                          *\n");
	printf("*\t\t\t\t4.下午下班时间录入。                          *\n");
	printf("*\t\t\t\t5.晚上上班时间录入。                          *\n");
	printf("*\t\t\t\t6.晚上下班时间录入。                          *\n");
	printf("*\t\t\t\t7.职工整体出勤情况浏览。                      *\n");
	printf("*\t\t\t\t8.查询考勤记录。                              *\n");
	printf("*\t\t\t\t9.修改考勤记录。                              *\n");
	printf("*\t\t\t\t10.删除考勤记录。                             *\n");
	printf("*\t\t\t\t11.保存考勤记录。                             *\n");
	printf("*\t\t\t\t12.退出。（任何情况下按ctrl+c退出）           *\n");
	printf("*\t\t\t\t\t\t\t\t\t      *\n");
	printf("*******************************************************************************\n");
}

/*输入判断*/
void getjudge(char wh[])
{
	char *p;
	p=wh;
	rewind(stdin);
	printf("\n请输入职工号(1001~1010)：");
	while(1){
	rewind(stdin);
	gets(wh);
	rewind(stdin);
	if((*p=='1'&&*(p+1)=='0'&&*(p+2)=='0'&&*(p+3)>='0'&&*(p+3)<='9')||(*p=='1'&&*(p+1)=='0'&&*(p+2)=='1'&&*(p+3)>='0'))
	{
		printf("\n合法输入。\n");
		break;}
	else printf("\n\n不合法输入，请重新输入职工号：");
	}
	return;
}

/*密码*/
void putsecret()
{
	int y;
	char str1[8]="abc123",str2[8]="0";

	rewind(stdin);
	printf("\n请输入密码：");
		while(1){
				gets(str2);
				y=strcmp(str1,str2);
				
				if(y!=0)
					printf("\n密码输入错误，请重新输入：");
			else
					break;
				}
		return ;
}




/*从磁盘导入职工信息到内存*/	
void loadinf()	
{
	FILE *fp;
	int n=0;
	if((fp=fopen("c:\\123.txt","r"))==NULL)
	{
		printf("文件不存在或文件无法打开！\n");
	getch();
	system("cls");
		return ;
	}
	printf("\n\t\t\t\t读入考勤信息如下\n");
	printf("\n职工号\t\t姓  名\t\t迟到次数\t早退次数\t旷工次数\n");
	head=p1=(struct worker*)malloc(LEN);
	p1->next=NULL;
	while(!feof(fp))
	{
		n++;
		fscanf(fp,"%s%s%d%d%d",p1->number,p1->name,&p1->late,&p1->earlyleave,&p1->notwork);

		if(p1->number[0]<'0'||p1->number[0]>'9')
		{
			n--;
			break;
		}

		printf("%s\t\t%s\t\t%5d\t\t%5d\t\t%5d\n",p1->number,p1->name,p1->late,p1->earlyleave,p1->notwork);
		p2=(struct worker *)malloc(LEN);
		p1->next=p2;
		p3=p1;
		p1=p2;
		p1->next=NULL;
		
	}
	free(p2);
	p3->next=NULL;
	fclose(fp);	
	
	printf("\n已读取%d项职工信息信息，按任意键返回????",n);
	getch();
	system("cls");
	writenflag=0;

	if(!fclose(fp))
	{
		printf("Can not close the file!\n\n");
		exit(0);
	}
}


/*上午上班时间录入*/
void monuprecord()
{

	char num[20];

	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	asctime (timeinfo);

	if(timeinfo->tm_wday==6||timeinfo->tm_wday==0)
	{
	printf("\n现在是周末，不是上班时间。\n");
	printf("\n按任意键返回...");
	getch();
	system("cls");
	return;
	}

	if(timeinfo->tm_hour>=12)
	{
	printf("\n现在不是上午，不能进行此操作。按任意键返回...");
	getch();
	system("cls");
	return;
	}

	printf ( "\n现在时间为：%4d-%02d-%02d	%02d:%02d:%02d\t星期：%d\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);

	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;

	p1=head;
	rewind(stdin);
	getjudge(num);
	
	if((nowtime.hour==8&&nowtime.minute==0)||nowtime.hour<8)
	printf("\n正常上班。\n");

	/*迟到判断*/
	if((nowtime.hour==8&&nowtime.minute>=0&&nowtime.minute<=5))
	{
		printf("\n上班迟到\n。");
	
	while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
	if(strcmp(num,p1->number)==0){
		(p1->late)++;
		}
	}

	/*旷工判断*/
	if((nowtime.hour==8&&nowtime.minute>5)||nowtime.hour>8)
	{

		printf("\n旷工一次。\n");
	while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
	if(strcmp(num,p1->number)==0)
	{
		(p1->notwork)++;
		}

	}
	writenflag=1;

	printf("\n考勤信息已录入，按任意键返回...");
	getch();
	system("cls");

}


/*上午下班时间录入*/
void mondownrecord()
{

	char num[20];

	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	asctime (timeinfo);

	if(timeinfo->tm_wday==6||timeinfo->tm_wday==0)
	{
	printf("\n现在是周末，不允许进行此操作。\n");
	printf("\n按任意键返回...");
	getch();
	system("cls");
	return;
	}

	printf ( "\n现在时间为：%4d-%02d-%02d	%02d:%02d:%02d\t星期：%d\n\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);

	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;

	p1=head;

	rewind(stdin);
	getjudge(num);

	if(nowtime.hour>11||(nowtime.hour==11&&nowtime.minute>=30))
	printf("\n正常下班。\n");

	/*早退判断*/
	if(nowtime.hour<11||(nowtime.hour==11&&nowtime.minute<=30))
	{
	printf("\n早退。\n");
	while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
	if(strcmp(num,p1->number)==0)
	{
		(p1->earlyleave)++;
		}
	
	}	
	writenflag=1;
	printf("\n考勤信息已录入，按任意键返回...");
	getch();
	system("cls");

}


/*下午上班时间录入*/
void afteruprecord()
{

	char num[20];

	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	asctime (timeinfo);

	if(timeinfo->tm_wday==6||timeinfo->tm_wday==0)
	{
	printf("\n现在是周末，不是上班时间。\n");
	printf("\n按任意键返回...");
	getch();
	system("cls");
	return;
	}

	if(timeinfo->tm_hour<=12)
	{
	printf("\n现在不是下午，不能进行此操作。按任意键返回...");
	getch();
	system("cls");
	return;
	}

	printf ( "\n现在时间为：%4d-%02d-%02d	%02d:%02d:%02d\t星期：%d\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);

	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;

	p1=head;
	rewind(stdin);
	getjudge(num);
	
	if(nowtime.hour<=14)
	printf("\n正常上班。\n");

	/*迟到判断*/
	if(nowtime.hour==14&&nowtime.minute>=0&&nowtime.minute<=5)
	{
		printf("\n上班迟到\n。");
	
	while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
	if(strcmp(num,p1->number)==0){
		(p1->late)++;
		}
	}

	/*旷工判断*/
	if((nowtime.hour==14&&nowtime.minute>5)||nowtime.hour>14)
	{

		printf("\n旷工一次。\n");
	while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
	if(strcmp(num,p1->number)==0)
	{
		(p1->notwork)++;
		}

	}
	writenflag=1;

	printf("\n考勤信息已录入，按任意键返回...");
	getch();
	system("cls");

}


/*下午下班时间录入*/
void afterdownrecord()
{

	char num[20];

	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	asctime (timeinfo);

	if(timeinfo->tm_wday==6||timeinfo->tm_wday==0)
	{
	printf("\n现在是周末，不允许进行此操作。\n");
	printf("\n按任意键返回...");
	getch();
	system("cls");
	return;
	}
	printf ( "\n现在时间为：%4d-%02d-%02d	%02d:%02d:%02d\t星期：%d\n\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);

	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;

	p1=head;
	//getchar();
	rewind(stdin);
	getjudge(num);

	if(nowtime.hour>=17)
	printf("\n正常下班。\n");

	/*早退判断*/
	if(nowtime.hour<17||(nowtime.hour=17&&nowtime.minute<30))
	{
	printf("\n早退。\n");
	while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
	if(strcmp(num,p1->number)==0)
	{
		(p1->earlyleave)++;
		}
	
	}	
	writenflag=1;
	printf("\n考勤信息已录入，按任意键返回...");
	getch();
	system("cls");
}


/*晚上上班时间录入*/
void evenuprecord()
{

	char num[20];

	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	asctime (timeinfo);

	if(timeinfo->tm_wday==6||timeinfo->tm_wday==0)
	{
	printf("\n现在是周末，不是上班时间。\n");
	printf("\n按任意键返回...");
	getch();
	system("cls");
	return;
	}
	if(timeinfo->tm_hour<=17)
	{
	printf("\n现在不是晚上，不能进行此操作。按任意键返回...");
	getch();
	system("cls");
	return;
	}
	printf ( "\n现在时间为：%4d-%02d-%02d	%02d:%02d:%02d\t星期：%d\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);

	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;

	p1=head;
	rewind(stdin);
	getjudge(num);
	
	if((nowtime.hour==18&&nowtime.minute==0)||nowtime.hour<18)
	printf("\n正常上班。\n");

	/*迟到判断*/
	if((nowtime.hour==18&&nowtime.minute>=0&&nowtime.minute<=5))
	{
		printf("\n上班迟到\n。");
	
	while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
	if(strcmp(num,p1->number)==0){
		(p1->late)++;
		}
	}

	/*旷工判断*/
	if((nowtime.hour==18&&nowtime.minute>5)||nowtime.hour>18)
	{

		printf("\n旷工一次。\n");
	while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
	if(strcmp(num,p1->number)==0)
	{
		(p1->notwork)++;
		}

	}
	writenflag=1;

	printf("\n考勤信息已录入，按任意键返回...");
	getch();
	system("cls");

}


/*晚上下班时间录入*/
void evendownrecord()
{

	char num[20];

	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	asctime (timeinfo);

	if(timeinfo->tm_wday==6||timeinfo->tm_wday==0)
	{
	printf("\n现在是周末，不允许进行此操作。\n");
	printf("\n按任意键返回...");
	getch();
	system("cls");
	return;
	}
	printf ( "\n现在时间为：%4d-%02d-%02d	%02d:%02d:%02d\t星期：%d\n\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);

	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;

	p1=head;
	//getchar();
	rewind(stdin);
	getjudge(num);

	if(nowtime.hour>=21)
	printf("\n正常下班。\n");

	/*早退判断*/
	if(nowtime.hour<=21)
	{
	printf("\n早退。\n");
	while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
	if(strcmp(num,p1->number)==0)
	{
		(p1->earlyleave)++;
		}
	
	}	
	writenflag=1;
	printf("\n考勤信息已录入，按任意键返回...");
	getch();
	system("cls");

}

/*查找*/
void seek()
{	char num[20];

	rewind(stdin);
	putsecret();
	rewind(stdin);
	getjudge(num);
	p1=head;
	if(p1==NULL)
	{	printf("\n职工信息数据库为空，按任意键返回...\n");
		getch();
		system("cls");
		return ;	
	}
	printf("\n\t\t\t\t职工考勤信息如下：\n");
	printf("\n职工号\t\t姓  名\t\t迟到次数\t早退次数\t矿工次数\n");
	while(p1!=NULL)
	{
		if(strcmp(p1->number,num )==0)
		{	printf("%s\t\t%s\t\t%5d\t\t%5d\t\t%5d\n",p1->number,p1->name,p1->late,p1->earlyleave,p1->notwork);
		break;
		}
		else p1=p1->next;
	}
	
	if(p1==NULL)
	{	printf("\n职工信息数据库为空，按任意键返回...\n");
	printf("\n\t\t\t\t职工考勤信息如下：\n");
		getch();
		system("cls");
		return ;	
	}
	printf("\n按任意键返回....");
	getch();
	system("cls");
}


/*显示所有信息*/
void  allprint()
{
	rewind(stdin);

	if(head==NULL){ 
		printf("\n数据库中没有考勤信息，按Enter键返回。\n");
		getchar();
		system("cls");
	}
	printf("\n\t\t\t\t全部考勤信息如下\n");
	printf("\n职工号\t\t姓  名\t\t迟到次数\t早退次数\t矿工次数\n");
	p1=head;
	while(p1!=NULL){
		printf("%s\t\t%s\t\t%5d\t\t%5d\t\t%5d\n",p1->number,p1->name,p1->late,p1->earlyleave,p1->notwork);
		p1=p1->next;
	
	}

	printf("\n按任意键返回....");
	getch();
	system("cls");
}

/*修改*/
void change()
{
	char num[20];
	rewind(stdin);
	putsecret();
	rewind(stdin);
	getjudge(num);

	if(head==NULL)
	{
		getchar();
		printf("\n考勤信息数据库为空，不能修改，按任意键返回...");
		getch();
		system("cls");
		return;
	}
	p1=head;
	
	while(strcmp(num,p1->number)!=NULL&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==NULL)
		{
			strcpy(p1->number,num);
			printf("\n请输入该职工的名字：");
			scanf("%s",p1->name);
			printf("\n请输入该职工的迟到的次数：");
			scanf("%d",&p1->late);
	
			printf("\n请输入该职工的早退的次数：");
			scanf("%d",&p1->earlyleave);


			printf("\n请输入该职工的旷工的天数：");
			scanf("%d",&p1->notwork);
			printf("\n一项信息修改完毕。\n");
		}
		else
			printf("\n找不到该职工的考勤信息！\n");
			getchar();
			printf("\n按任意键返回.....\n");
			getch();
			system("cls");
			writenflag=1;
			return ;
}


/*删除*/
void cutoff()
{
	char num[20];
	putsecret();
	if(head==NULL)
	{
		getchar();
		printf("\n考勤信息为空，不能删除，按任意键返回....");
		getch();
		system("cls");
		return;	
		getchar();
	}

	p1=head;	
	rewind(stdin);
	getjudge(num);

	while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(strcmp(num,p1->number)==0)
	{
		if(head->next==NULL)
		{
			free(head);
			head=NULL;
		}
		else if(head==p1)
		{
				head=p1->next;
				free(p1);
		}
		else { p2->next=p1->next;
				free(p1);
		}
		printf("\n删除完毕。\n");
	}
	else 
		printf("\n找不到该职工的考勤信息！\n");

	printf("\n按任意键返回...");
	getch();
	system("cls");
	writenflag=1;
	return ;
}

/*保存考勤信息*/
void inforsave()
{
	FILE *fp;
	if(head==NULL)
	{
		printf("\n数据库中没有考勤信息，按任意键返回...");
		getch();
		system("cls");
		return;
	}
	if(writenflag==0)
	{
		printf("\n数据库中考勤信息已保存过，按任意键返回....");
		getch();
		return;
	}
	if((fp=fopen("c:\\123.txt","w"))==NULL)
	{
		printf("\n数据库中考勤信息无法保存，按任意键返回....");
		getch();
		system("cls");
		return;
	}
	p1=head;
	while(p1!=NULL)
	{
		fprintf(fp,"%s %s %d %d %d\n",p1->number,p1->name,p1->late,p1->earlyleave,p1->notwork);
		p1=p1->next;
		
	}
	fclose(fp);
	printf("\n\n数据库中考勤信息已保存完毕，按任意键返回....\n");
	getch();
	system("cls");

	writenflag=0;
	return;
}

/*退出*/
void quit()
{
	rewind(stdin);
	printf("\n\n\n\n\t\t\t*************************\n");
	printf("\t\t\t*\t谢谢使用！\t*\n");
	printf("\t\t\t*************************\n\n\n\n\n");
	if(	writenflag==1)
		inforsave();
	p1=head;
	while(p1!=NULL)
	{
		p2=p1->next;
		free(p1);
		p1=p2;
	}
	
	return ;	
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct DAY
{
	char*dayName;
	int date;
	char*activity;
}Day;

Day createDay()
{
	Day newDay;
	newDay.dayName=(char*)malloc(10*sizeof(char));
	newDay.activity=(char*)malloc(100*sizeof(char));
	fflush(stdin);
	printf("Enter day name:");
	scanf("%s",newDay.dayName);
	fflush(stdin);
	printf("Enter date:");
	scanf("%d",&newDay.date);
	fflush(stdin);
	printf("Enter activity:");
	scanf("%[^\n]s*",newDay.activity);
	
	return newDay;
}

void read(Day calendar[])
{
	for(int i=0; i<7; i++)
	{
		printf("\nEnter details for day %d:\n",i+1);
		calendar[i]=createDay();
	}
}

void display(Day calendar[])
{
	printf("\nWeeks Activity Details:\n");
	for(int i=0; i<7; i++)
	{
		printf("\nDay %d\n",i+1);
		printf("Day Name:%s\n",calendar[i].dayName);
		printf("Date:%d\n",calendar[i].date);
		printf("Activity:%s\n",calendar[i].activity);
	}
}

int main()
{
	Day week[7];
	printf("Creating the calendar...\n");
	read(week);
	
	printf("\nDisplay the calendar....\n");
	display(week);
	
	for(int i=0; i<7; i++)
	{
		free(week[i].dayName);
		free(week[i].activity);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
// Structure to represent a day
typedef struct DAY {
 char *dayName;
 int date;
 char *activity;
}Day;
// Function to create a day
Day createDay() {
 Day newDay;
 newDay.dayName = (char *)malloc(10* sizeof(char));
 newDay.activity = (char *)malloc(100 * sizeof(char));
 printf("Enter day name: ");
 scanf("%s", newDay.dayName);
 printf("Enter date: ");
 scanf("%d", &newDay.date);
 printf("Enter activity: ");
 scanf("%[^\n]s", newDay.activity);
 return newDay;
}
// Function to read data for all days of the week
void read(Day calendar[]) {
 for (int i = 0; i < 7; ++i) {
 printf("\nEnter details for day %d:\n", i + 1);
 calendar[i] = createDay();
 }
}
// Function to display the calendar
void display(Day calendar[]) {
 printf("\nWeek's Activity Details:\n");
 for (int i = 0; i < 7; ++i) {
 printf("\nDay %d\n", i + 1);
 printf("Day Name: %s\n", calendar[i].dayName);
 printf("Date: %d\n", calendar[i].date);
 printf("Activity: %s\n", calendar[i].activity);
 }
}
int main() {
 Day week[7];
 clrscr();
 printf("Creating the calendar...\n");
 read(week);
 printf("\nDisplaying the calendar...\n");
 display(week);
 // Free dynamically allocated memory
 for (int i = 0; i < 7;++i) {
 free(week[i].dayName);
 free(week[i].activity);
 }
 return 0;
}
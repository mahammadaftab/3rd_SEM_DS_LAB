#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "conio.h"
#define COMPARE(x, y) ( (x == y) ? 0 : (x > y) ? 1 : -1)
struct node
{
int coef;
int xexp, yexp, zexp;
struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x = (NODE) malloc(sizeof(struct node));
if(x == NULL)
{
printf("Running out of memory \n");
return NULL;
}
return x;
}
NODE attach(int coef, int xexp, int yexp, int zexp, NODE head)
{
NODE temp, cur;
temp = getnode();
temp->coef = coef;
temp->xexp = xexp;
temp->yexp = yexp;
temp->zexp = zexp;
cur = head->link;
while(cur->link != head)
{
cur = cur->link;
}
cur->link = temp;
temp->link = head;
return head;
}
NODE read_poly(NODE head)
{
int i, j, coef, xexp, yexp, zexp, n;
printf("\nEnter the no of terms in the polynomial: ");
scanf("%d", &n);
for(i=1; i<=n; i++)
{
printf("\n\tEnter the %d term: ",i);
printf("\n\t\tCoef =");
scanf("%d", &coef);
printf("\n\t\tEnter Pow(x) Pow(y) and Pow(z): ");
scanf("%d", &xexp);
scanf("%d", &yexp);
scanf("%d", &zexp);
head = attach(coef, xexp, yexp, zexp, head);
}
return head;
}
void display(NODE head)
{
NODE temp;
if(head->link == head)
{
printf("\nPolynomial does not exist.");
return;
}
temp = head->link;
while(temp != head)
{
printf("%dx^%dy^%dz^%d", temp->coef, temp->xexp, temp->yexp, temp->zexp);
temp = temp->link;
if(temp != head)
printf(" + ");
}
}
int poly_evaluate(NODE head)
{
int x, y, z, sum = 0;
NODE poly;
printf("\nEnter the value of x,y and z: ");
scanf("%d %d %d", &x, &y, &z);
poly = head->link;
while(poly != head)
{
sum += poly->coef * pow(x,poly->xexp)* pow(y,poly->yexp) * pow(z,poly->zexp);
poly = poly->link;
}
return sum;
}
void main()
{
NODE head, head1, head2, head3;

int res, ch;

head = getnode(); /* For polynomial evalaution */
head1 = getnode(); /* To hold POLY1 */
head3 = getnode(); /* To hold POLYSUM */
head->link=head;
head1->link=head1;
head3->link= head3;
printf("\n1.Represent and Evaluate a Polynomial P(x,y,z)");
printf("\n~~~~Polynomial evaluation P(x,y,z)~~~\n");
head = read_poly(head);
printf("\nRepresentation of Polynomial for evaluation: \n");display(head);
res = poly_evaluate(head);
printf("\nResult of polynomial evaluation is : %d \n",res);
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#define COMPARE(x,y)((x==y)?0:(x>y)?1:-1)
struct node
{
int coef;
int xexp,yexp,zexp;
struct node*link;
};
typedef struct node*NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
{
printf("Runningoutofmemory\n");
return NULL;
}
return x;
}
NODE attach(int coef,int xexp,int yexp,int zexp,NODE head)
{
NODE temp,cur;
temp=getnode();
temp->coef=coef;
temp->xexp=xexp;
temp->yexp=yexp;
temp->zexp=zexp;
cur=head->link;
while(cur->link!=head)
{
cur=cur->link;
}
cur->link=temp;
temp->link=head;
return head;
}
NODE read_poly(NODE head)
{
int i,j,coef,xexp,yexp,zexp,n;
printf("\nEnterthenooftermsinthepolynomial:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("\n\tEnterthe%dterm:",i);
printf("\n\t\tCoef=");
scanf("%d",&coef);
printf("\n\t\tEnterPow(x)Pow(y)andPow(z):");
scanf("%d",&xexp);
scanf("%d",&yexp);
scanf("%d",&zexp);
head=attach(coef,xexp,yexp,zexp,head);
}
return head;
}
void display(NODE head)
{
NODE temp;
if(head->link==head)
{
printf("\nPolynomialdoesnotexist.");
return;
}
temp=head->link;
while(temp!=head)
{
printf("%dx^%dy^%dz^%d",temp->coef,temp->xexp,temp->yexp,temp->zexp);
temp=temp->link;
if(temp!=head)
printf("+");
}
}
NODE poly_sum(NODE head1,NODE head2,NODE head3)
{
NODE a,b;
int coef;
a=head1->link;
b=head2->link;
while(a!=head1&&b!=head2)
{
while(1)
{
if(a->xexp==b->xexp&&a->yexp==b->yexp&&a->zexp==b->zexp)
{
coef=a->coef+b->coef;
head3=attach(coef,a->xexp,a->yexp,a->zexp,head3);
a=a->link;
b=b->link;
break;
}//ifendshere
if(a->xexp!=0||b->xexp!=0)
{
switch(COMPARE(a->xexp,b->xexp))
{
case -1:head3=attach(b->coef,b->xexp,b->yexp,b->zexp,head3);
b=b->link;
break;
case 0:if(a->yexp>b->yexp)
{
head3=attach(a->coef,a->xexp,a->yexp,a->zexp,head3);
a=a->link;
break;
}
else if(a->yexp<b->yexp)
{
head3=attach(b->coef,b->xexp,b->yexp,b->zexp,head3);
b=b->link;
break;
}
else if(a->zexp>b->zexp)
{
head3=attach(a->coef,a->xexp,a->yexp,a->zexp,head3);
a=a->link;
break;
}
else if(a->zexp<b->zexp)
{
head3=attach(b->coef,b->xexp,b->yexp,b->zexp,head3);
b=b->link;
break;
}
case 1:head3=attach(a->coef,a->xexp,a->yexp,a->zexp,head3);
a=a->link;
break;
}//switchendshere
break;
}//ifendshere
if(a->yexp!=0||b->yexp!=0)
{
switch(COMPARE(a->yexp,b->yexp))
{
case -1:head3=attach(b->coef,b->xexp,b->yexp,b->zexp,head3);
b=b->link;
break;
case 0:if(a->zexp>b->zexp)
{
    head3=attach(a->coef,a->xexp,a->yexp,a->zexp,head3);
a=a->link;
break;
}
else if(a->zexp<b->zexp)
{
head3=attach(b->coef,b->xexp,b->yexp,b->zexp,head3);
b=b->link;
break;
}
case 1:head3=attach(a->coef,a->xexp,a->yexp,a->zexp,head3);
a=a->link;
break;
}
break;
}
if(a->zexp!=0||b->zexp!=0)
{
switch(COMPARE(a->zexp,b->zexp))
{
case -1:head3=attach(b->coef,b->xexp,b->yexp,b->zexp,head3);
b=b->link;
break;
case 1:head3=attach(a->coef,a->xexp,a->yexp,a->zexp,head3);
a=a->link;
break;
}
break;
}
}
}
while(a!=head1)
{
head3=attach(a->coef,a->xexp,a->yexp,a->zexp,head3);
a=a->link;
}
while(b!=head2)
{
head3=attach(b->coef,b->xexp,b->yexp,b->zexp,head3);
b=b->link;
}
return head3;
}
void main()
{
NODE head,head1,head2,head3;
int res,ch;
clrscr();
head=getnode();/*Forpolynomialevalaution*/
head1=getnode();/*ToholdPOLY1*/
head2=getnode();/*ToholdPOLY2*/
head3=getnode();/*ToholdPOLYSUM*/
head->link=head;
head1->link=head1;
head2->link=head2;
head3->link=head3;
printf("\nFindthesumoftwopolynomialsPOLY1(x,y,z)");
printf("\nEnterthePOLY1(x,y,z):\n");
head1=read_poly(head1);
printf("\nPolynomial1is:\n");
display(head1);
printf("\nEnterthePOLY2(x,y,z):\n");
head2=read_poly(head2);
printf("\nPolynomial2is:\n");
display(head2);
printf("\nPolynomialadditionresult:\n");
head3=poly_sum(head1,head2,head3);
display(head3);
}
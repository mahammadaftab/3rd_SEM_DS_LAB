#include<stdio.h>
#include<math.h>
#include<conio.h>
void tower(int n, char from_peg, char aux_peg, char to_peg);
void main()
{
 int n;
 clrscr();
 printf("\nEnter the number of disks: ");
 scanf("%d", &n);
 tower(n, 'A', 'B', 'C'); // A-> from_peg B->aux_peg C->to_peg
 printf("\nTotal number of moves = %0.0f", pow(2,n)-1 );
}
void tower(int n, char from_peg, char aux_peg, char to_peg) // A-> from_peg B->aux_peg C->to_peg
{
 if(n == 1)
 {
 printf("\nMove disk %d from %c peg to %c peg", n, from_peg, to_peg);
 return;
 }
 // move n-1 disks from A(from_peg) to B(to_peg) using C(aux_peg) as auxiliary
 tower(n-1, from_peg, to_peg, aux_peg);
 printf("\nMove disk %d from peg %c to %c peg", n, from_peg, to_peg);
 // move n-1 disks from B(aux_peg) to C(to_peg) using A(from_peg) as auxiliary
 tower(n-1, aux_peg, from_peg, to_peg);
}
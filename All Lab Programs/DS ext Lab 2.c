#include<stdio.h>
#include<stdlib.h>
insertion_sort()
{
	int i,j,a[10],n,temp;
	printf("Enter the value of n:");
	scanf("%d",&n);
	
	printf("enter n element:");
	for(i=0; i<n;  i++)
		scanf("%d",&a[i]);
		for(i=0; i<n;  i++)
		{
			j=i;
			while(j>-1)
			{
				if(a[j]<a[j-1])
				{
					temp=a[j];
					a[j]=a[j-1];
					a[j-1]=temp;
				}
				j=j-1;
			}
		}
		printf("Sorted array elements:\n");
		for(i=0; i<n;  i++)
			printf("%d\n",a[i]);
}

Merging()
{
	int i,j,a[10],b[10],m,n,temp,c[20],k=0;
	printf("Enter the value of n:");
	scanf("%d",&n);
	
	printf("enter n element in sorted order:");
	for(i=0; i<n;  i++)
		scanf("%d",&a[i]);
	printf("Enter the value of m:");
	scanf("%d",&m);
	printf("enter m element in sorted order:");
	for(j=0; j<m;  j++)
		scanf("%d",&b[j]);
		i=0;
		j=0;
	while(i<n && j<m)
	{
		if(a[i]<b[j])
			c[k++]=a[i++];
		else
			c[k++]=b[j++];
	}
	while(i<n)
		c[k++]=a[i++];
	while(j<m)
		c[k++]=b[j++];
	printf("Sorted array elements:\n");
	for(i=0; i<n+m; i++)
		printf("%d\n",c[i]);
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n-----MENU-----\n");
		printf("1. Insertion sort\n");
		printf("2. Merging two Sorted array\n");
		printf("3. Exit\n");
		
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertion_sort();
				break;
			
			case 2:
				Merging();
				break;
			
			case 3:
				exit(1);
				break;
			
			default:
				printf("Invalid choice");
		}
		
	}
}

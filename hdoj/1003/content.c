#include<stdio.h>

typedef struct context{
	int sum,begin,end;
}

typedef struct block{
	block *next;
	int begin,end;
	int sum;
} 


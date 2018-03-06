#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Block{
	struct Block *next,*pre;
	int Begin,End,sum;
};


struct Context{
	int sum,Begin,End;
	int Length,line[100000];
	struct Block *head;
};

struct Block* creat_Block(struct Context *context,struct Block *this){
	struct Block *next;
	next=(struct Block*)calloc(1,sizeof(struct Block));
	next->Begin=this->End+1;
	next->End  =next->Begin;
	this->next=next;
	next->pre =this;
	next->next=NULL;
	next->sum =context->line[next->Begin-1];
	return next;
}

void init_con(struct Context *con){
	scanf("%d",&(con->Length));
	int digit=0;
	for(digit=0;digit<con->Length;digit++){
		scanf("%d",&(con->line[digit]));
	}
	con->Begin=1;
	con->End=1;
	con->sum=con->line[0];
	con->head=NULL;
}

void link_Block(struct Context *con){
	struct Block *temp;
	temp=(struct Block*)calloc(1,sizeof(struct Block));
	con->head=temp;
	temp->Begin=1;
	temp->End  =1;
	temp->sum  =con->line[0];
	temp->pre  =NULL;
	while(temp->End<con->Length){
		temp=creat_Block(con,temp);
	}
}

void display_link(struct Context *context){
	struct Block *block;
	int count=0;
	block=context->head;
	while(1){
		printf("%d:\tThis block begin at %d , end at %d,sum is %d \t\t\n",++count,block->Begin,block->End,block->sum);
		if(block->next==NULL){break;}
		else{block=block->next;}
	}
}
		
void display_con(struct Context *context){
	printf("-------------------------------------------------------------------------\nThe line is :\n");
	int digit=0;
	for(digit=0;digit<context->Length;digit++){
		printf("%d ",context->line[digit]);
	}
	printf("\n-----------------------------------------------------------------------\n");
	display_link(context);
}

void merge_block(struct Context *context,struct Block* block){
	struct Block *next=block->next;
	block->next=next->next;
	block->End=next->End;
	block->sum+=next->sum;
}

struct Block* merge(){;}

void test();
int main(){
	test();
	return 0;
}

void test(){
	struct Context context;
	init_con(&context);	
	link_Block(&context);
	display_con(&context);
	merge_block(&context,context.head);
	merge_block(&context,context.head);
	merge_block(&context,context.head);
	merge_block(&context,context.head);
	display_con(&context);

}





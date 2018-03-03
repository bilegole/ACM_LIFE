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
	next->sum =context->line[next->Begin];
	return next;
}

void init_con(struct Context *con){
	con->sum=78;
	con->Begin=0;
	con->End=0;
	con->Length=0;
	int digit=0;
	for(digit=0;digit<100000;digit++){
		con->line[digit]=111;
	}
	con->head=NULL;
}

void link_Block(struct Context *con){
	struct Block *head;
	head=(struct Block*)calloc(1,sizeof(struct Block));
	con->head=head;
	head->Begin=1;
	head->End  =1;
	head->sum  =con->line[0];
	head->pre  =NULL;
	while(
	creat_Block(con,head);
}

void display_link(struct Context *context){
	struct Block *block;
	int count=0;
	block=context->head;
	while(1){
		printf("%d:\tThis block begin at %d , end at %d\n",++count,block->Begin,block->End);
		if(block->next==NULL){break;}
		else{block=block->next;}
	}
}
		

void test();
int main(){
	test();
	return 0;
}

void test(){
	struct Context context;
	init_con(&context);	
	link_Block(&context);
	display_link(&context);
	

}





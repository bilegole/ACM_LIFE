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

void compare_biggest(struct Context *con,struct Block *block){
	if(block->sum > con->sum){
		con->Begin=block->Begin;
		con->End=block->End;
		con->sum=block->sum;
	}
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

void link_free(struct Block *block){
	while(block->next!=NULL){
		block=block->next;
		free(block->pre);
	}
	free(block);
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
	block->next->pre=block;
}

int block_detect(struct Block* block){
	if(block->next==NULL){return -1;}
	else if(block->sum*block->next->sum>=0){return 1;}
	else if(block->pre==NULL){return 3;}
	else if(((block->next->sum+block->sum)*block->sum<=0) &&
			((block->pre ->sum+block->sum)*block->sum<=0))
			{return 2;}
	return 0;
}

void merge(struct Context *context){
	struct Block *cursor=context->head;
	int loop=1;
	while (loop){
		compare_biggest(context,cursor);
		switch (block_detect(cursor)){
			case -1:
				loop=0;
				break;
			case 1:
				merge_block(context,cursor);
				if(cursor->pre!=NULL){cursor=cursor->pre;}
				break;
			case 2:
				merge_block(context,cursor);
				cursor=cursor->pre;
				merge_block(context,cursor);
				if(cursor->pre!=NULL){cursor=cursor->pre;}
				break;
			default:
				cursor=cursor->next;
		}
	}
}

void display_result(struct Context* context){
	printf("%d %d %d\n",context->sum,context->Begin,context->End);
}
	

void test();
int main(){
	int cu_turn1,Ra_turn1;
	scanf("%d",&Ra_turn1);
	for(cu_turn1=0;cu_turn1<Ra_turn1;cu_turn1++){
		struct Context context;
		init_con(&context);
		link_Block(&context);
		merge(&context);
		display_result(&context);
		link_free(context.head);
	}
	return 0;
}






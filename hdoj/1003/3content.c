#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Block{
	struct Block *next,*pre;
	int Begin,End,sum;
};
struct Context{
	int sum,Begin,End;
	int Length,line[1000];
	struct Block *root;
};

//____________________________________________________________________
//Block
void 			block_merge	(struct Block *this); 
//____________________________________________________________________
//Context
void 			con_init	(struct Context *context);

void 			con_display	(struct Context *context);

void			con_big		(struct Context *context,struct Block block);
//____________________________________________________________________
//link
void			link_merge	(struct Context *context);

void			link_display(struct Context *context);

void			link_free	(struct Context *context);
//____________________________________________________________________

//struct Block* block_addone(struct Context* context,struct Block* block){
//	block->next=(struct Block*)calloc(1,sizeof(struct Block);
//	block->next->pre  = block;
//	block->next->next = NULL;
//	block->next->Begin= block->next->End = block->End+1;
//	scanf("%d",&block->next->sum);
//	return block->next;
//}

//~~~~~~~~~~~~~~~~~~~~~~  Block Part  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void block_merge(struct Block* block){
	block->next->next->pre=block;
	block->next = block->next->next;
	block->sum += block->next->sum ;
	block->End  = block->next->End ;
}

//void block_detect(struct Block *block){
//	if(block->sum*block->next->sum>0){

//~~~~~~~~~~~~~~~~~~~~~~~  Context Part  ~~~~~~~~~~~~~~~~~~~~~~~~~~~
void con_init(struct Context *con){
	//init the root block
	con->root=(struct Block*)calloc(1,sizeof(struct Block*));
	scanf("%d",&con->Length);
	con->root->pre = con->root->next = NULL;
	con->root->Begin = con->root->End = 1;
	scanf("%d",&con->root->sum);
	con->line[0]=root->sum;
	//init the follow block
	struct Block *temp = con->root;
	while(temp->Begin<con->Length){
		temp->next=(struct Block*)calloc(1,sizeof(struct Block));
		temp->next->pre = block;
		temp->next->next= NULL;
		temp->next->Begin = temp->next->End = temp->End+1 ;
		scanf("%d",&temp->next->sum);
		con->line[temp->Begin-1]=temp->sum;
		temp = temp->next;
	}
	//init the biggest situation
	con->Begin=1;
	con->End  =1;
	con->sum  = con->root->sum;
}
void con_display(struct Context *context){
	printf("\n--------------------the line in the context----------------------\n");
	int digit=0;
	for(digit=0;digit<context->Length;digit++){
		printf("%d\t",context->line[digit]);
	}
	printf("\n-----------------------------------------------------------------\n");
	link_display(context->root);
}
void con_big(struct Context *con,struct Block *block){
	if(block->sum>=con->sum){
		con->Begin=block->Begin;
		con->End  =block->End;
		con->sum  =block->sum;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   Link Part ~~~~~~~~~~~~~~~~~~~~~~~
void link_merge(struct Context *context){
	struct Block *cursor=context->root;
	while(cursor->next!=NULL){
		if(cursor->next->sum*cursor->sum>=0){
			block_merge(	
































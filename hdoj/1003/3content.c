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
void			link_init	(struct Context *context);

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

void block_merge(struct Block* block){
	block->next->next->pre=block;
	block->next = block->next->next;
	block->sum += block->next->sum ;
	block->End  = block->next->End ;
}

//void block_detect(struct Block *block){
//	if(block->sum*block->next->sum>0){

//~~~~~~~~~~~~~~
void con_init(struct Context *con){
	//init the root block
	con->root=(struct Block*)calloc(1,sizeof(struct Block*));
	scanf("%d",&con->Length);
	con->root->pre = con->root->next = NULL;
	con->root->Begin = con->root->End = 1;
	scanf("%d",&con->root->sum);
	//init the follow block
	struct Block *temp = con->root;
	while(temp->Begin<con->Length){
		temp->next=(struct Block*)calloc(1,sizeof(struct Block));
		temp->next->pre = block;
		temp->next->next= NULL;
		temp->next->Begin = temp->next->End = temp->End+1 ;
		scanf("%d",&temp->next->sum);
		temp = temp->next;
	}
	//init the biggest situation
	con->Begin=1;
	con->End  =1;
	con->sum  = con->root->sum;
}



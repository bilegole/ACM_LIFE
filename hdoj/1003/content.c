#include<stdio.h>

struct Block{
	struct	Block *next,*pre;
	int begin,end;
	int sum;
}

struct Context{
	int sum,begin,end;
	int Length;
	int *line[100000];
	struct Block *begin;
}

struct Block creat_block(struct Context *context,struct Block this){
	struct Block next;
	next.begin=this.end+1;
	next.end=next.begin;
	this.next=*next;
	next.next=NULL;
	next.pre=*this;
	next.in=con.line[next.begin];
	next.sum=con.line[next.begin];
	return next;
}

void creat_link(struct Context context){
	context.begin.begin=0;
	context.begin.end=context.begin.begin;
	context.begin.sum=context.line[0];
	Block temp=context.begin;
	while(temp.begin<context.Length){
		temp=creat_block(context,temp);
	}
}

void cross_block(struct Block *this){
	printf("This block bagin at line[%d],\n\t\tEnd at line[%d],\n,sum up to %d\n\n",this->begin,this->end,this->sum);
	if((*(this.next)).next!=NULL){
		cross_block(*(this.next));
	}
void display_link(struct Context *context){
	cross_block(context->begin);
}

int main(){
	int co_turn1,Ra_turn1;
	int co_turn2,Ra_turn2;
	scanf("%d",&Ra_turn1);
	for(co_turn1=0;co_turn1<Ra_turn1;co_turn1++){
		context con={0};
		for(co_turn2=0;co_turn2<Ra_turn2;co_turn2++){
			scanf("%d",con.line[co_turn1]);
		}
		creat_link(con);
		display_link(context);
	}
	return 0;
}
























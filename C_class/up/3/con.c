#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct context{
	int stat;		//1:句前空格
					//2:句中
					//3:句中空格1
					//4:句中空格2（多余）
	char *sentence;
	int len;
};

struct cen{
	char *sen;
	char *word;
	int cen;
};

struct context *init(char *insen){
	struct context *con=(struct context*)calloc(1,sizeof(struct context));
	con->sentence=insen;
	con->stat=1;
	return con;
}

void process(struct context *con){
	int dig=0;
	con->len=strlen(con->sentence);
	printf("len: %d\n",con->len);
	int tig,digit;
	for(digit=0,tig=0;digit<con->len+1&&tig==0;){
		printf("%d  %d	'%c'\n",con->stat,digit,con->sentence[digit]);
		switch (con->stat){
			case 1://初始状态
				if(con->sentence[digit]==32){
					printf("1~1\n");
					for(dig=digit;dig<con->len-1;dig++){
						con->sentence[dig]=con->sentence[dig+1];
						printf("$$$%d-%d:'%c'\n",dig,con->len,con->sentence[dig]);
					}	con->sentence[dig]='\0';
					printf("$$$\n");
					con->len=strlen(con->sentence);
					printf("$$$\n");
				}else{
					printf("1~2\n");
					con->stat=2;
					digit++;
				}
				break;
			case 2://句中
				if(con->sentence[digit]==32){
					printf("2~1\n");
					con->stat=3;
					digit++;
				}else if(con->sentence[digit]=='\0'){
					printf("2~2\n");
					tig=1;
				}else{
					printf("2~3\n");
					digit++;
				}
				break;
			case 3://句中空格
				if(con->sentence[digit]==32){
					printf("3~1\n");
					for(dig=digit;dig<con->len-1;dig++){
						con->sentence[dig]=con->sentence[dig+1];
						printf("$$$%d-%d:'%c'\n",dig,con->len,con->sentence[dig]);
					}	con->sentence[dig]='\0';
					con->len=strlen(con->sentence);
				}else if(con->sentence[digit]=='\0'){
					printf("3~2\n");
					con->sentence[digit-1]='\0';
					tig=1;
				}else {
					printf("3~3\n");
					con->stat=2;
					digit++;
				}
		}
	}
}

struct cen *ce(char *sen,char *word){
	struct cen *ce=(struct cen*)calloc(1,sizeof(struct cen));
	ce->sen=sen;
	ce->word=word;
	ce->cen=0;
	return ce;
}

struct cen *sen_cen(struct cen *ce){
	int len=strlen(ce->sen);
	int len2=strlen(ce->word);
	for(int digit=0;digit<len;digit++){
		printf("sss  %d \n",digit);
		if(digit==0||(digit>0&&ce->sen[digit-1]==32)){
		for(int dig=0;dig<len2;dig++){
			printf("ooo  %d -- %d--%d\n",digit,dig,len2);
			if(ce->sen[digit+dig]!=ce->word[dig]){
				printf("different\n");
				break;
			}
			if(dig==len2-1&&ce->sen[digit+dig+1]==32){
				ce->cen++;
			}
		}}
	}
	return ce;
}

void display1(){
	char sen[100]="         hello     !    @    ";
	process(init(sen));
	printf("%s\n",sen);
	for(int i=0;i<strlen(sen);i++){
		printf("-%d",sen[i]);
	}	printf("\n");
}	

void display2(){
	char sen[100]="hello11 hello iihello hello world!";
	struct cen *ce1=sen_cen(ce(sen,"hello"));
	printf("%s in %s :%d\n",ce1->word,ce1->sen,ce1->cen);
}

int main(){
	display2();
	return 0;
}

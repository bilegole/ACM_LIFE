#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Len 1000

typedef struct  {
	int *con,len,sig;	//sig=1 -> 正数		sig=0 -> 负数
}Num;

typedef struct  {
	Num *nums;
	int *sig;			//[0]代表运算种类，[1]代表较大数位置
	Num *res;
}Pro;

int bigger(Num *num1,Num *num2){
	if(num1->sig>0&&num2->sig<0){return 1;}
	else if(num1->sig<0&&num2->sig>0){return 2;}
	else{
		int tig=num1->sig;
		for(int digit=Len-1;digit>=0;digit--){
			if(num1->con[digit]>num2->con[digit]){
				return tig?1:2;
			}else if(num1->con[digit]<num2->con[digit]){
				return tig?2:1;
			}else if(digit==0){ return 0; }
		}
	}
}

Num *str_to_Num(char *str){
	int digit=0;
	Num *num=(Num*)calloc(1,sizeof(Num));
	num->con=(int*)calloc(Len,sizeof(int));
	for(digit=0;digit<Len;digit++){
		num->con[digit]=0;
	}	
	num->len=strlen(str);
	if(str[0]=='-'){
		num->sig=0;
		num->len-=1;
	}else{
		num->sig=1;
	}
	for(digit=0;digit<num->len;digit++){
		num->con[digit]=str[num->len-num->sig-digit];
	}
	return num;
}

char *Num_to_str(Num *tar){
	char *res=(char*)calloc(Len,sizeof(char));
	int digit=0;
	if(tar->sig==0){
		res[digit++]='-';
	}
	int dig1=0;
	for(dig1=tar->len-1;dig1>=0;dig1--){
		res[digit++]=tar->con[dig1];
	}
	return res;
}

Pro *pro_creat(int sig){
	Pro *pro=(Pro*)calloc(1,sizeof(Pro));
	pro->sig=(int*)calloc(2,sizeof(int));
	pro->sig[0]=sig;
	pro->nums=(Num*)calloc(2,sizeof(Num));
	pro->nums=(Num*)calloc(sig!=3?1:2,sizeof(Num));
	return pro;
}

void num_to_pro(Pro *pro,Num *num,int dig){
	pro->nums[dig]=*num;
}

void pro_start(Pro *pro){
	if(pro->sig[0]<2){
		if(pro->sig[0]!=(pro->nums[0].sig*pro->nums[1].sig)){
			//ba_add(pro->nums[0],pro->nums[1]);
			printf("开始加法。");
		}else{
			//ba_dec(pro->nums[0],pro->nums[1]);
			printf("开始减法。");
		}
	}else if (pro->sig[0]==2){
		printf("开始乘法");
	}else if (pro->sig[0]==3){
		printf("开始除法");
	}
}



void test(){
	char one[Len]="-100";
	char two[Len]="298";
	Pro *pro=pro_creat(1);
	num_to_pro(pro,str_to_Num(one),0);
	num_to_pro(pro,str_to_Num(two),1);
	pro_start(pro);
	printf("%s\n",Num_to_str(pro->res));
}

int main(){
	test();
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define Len 1000
#define isTest 1


typedef struct  {
	int *con,len,sig;	//sig=1 -> 正数		sig=0 -> 负数
}Num;

typedef struct  {
	Num *nums;
	int *sig;			//[0]代表运算种类，[1]代表较大数位置
	Num *res;
}Pro;

int power(int a,int x){
	int res=1;
	for(int i=0;i<x;i++){
		res*=a;
	}
	return res;
}

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


//比较两个num绝对值的大小。
int num_abs_compare(Num *num1,Num *num2){
	for(int digit=Len-1;digit>=0;digit--){
		if(num1->con[digit]>num2->con[digit]){
			return 1;
		}else if(num2->con[digit]<num2->con[digit]){
			return 2;
		}else if(digit==0){
			return 0;
		}
	}
}

//比较两个num真实值的大小。
int num_compare(Num *num1,Num *num2){
	if(num1->sig>0&&num2->sig<0){	
		return 1;
	}else if(num1->sig<0&&num2->sig>0){
		return 2;
	}else if(num1->sig>0&&num2->sig>0){
		return num_abs_compare(num1,num2);
	}else if(num1->sig<0&&num2->sig<0){
		return num_abs_compare(num2,num1);
	}
}

//比较num和0的大小。
int num_comto_zero(Num *num){
	for(int digit=0;digit<Len;digit++){
		if(num->con[digit]==0){
			break;
		}else if(digit==Len-1){
			return 0;
		}
	}
	if(num->sig){
		return 1;
	}else{
		return -1;
	}
}

//将字符串转为Num对象。
Num *str_to_Num(char *str){
	Num *num=(Num*)calloc(1,sizeof(Num));			//分配num空间，初始化对象
	num->con=(int*)calloc(Len,sizeof(int));			//分配num.con的空间
	num->len=strlen(str);							//获取字符串的长度
	if(str[0]=='-'){								//获取num应有正负值，并对长度做修正。
		num->sig=0;
		num->len-=1;
	}else{
		num->sig=1;
	}
	for(int digit=0;digit<Len;digit++){					//将字符串主体写入num.con中
		if(digit<num->len){
			num->con[digit]=str[num->len-num->sig-digit]-'0';
		}else {
			num->con[digit]=0;
		}
	}
	if(num_comto_zero(num)!=-1){num->sig=1;}
	return num;
}

//将Num对象转为字符串。
char *Num_to_str(Num *tar){
	char *res=(char*)calloc(Len,sizeof(char));		//分配字符串空间，初始化对象
	int digit=0;									//初始化数位
	if(tar->sig==0){								//判断并执行写入符号位
		res[digit++]='-';
	}
	for(int dig1=tar->len-1;dig1>=0;dig1--){		//将num.con写入字符串中
		res[digit++]=tar->con[dig1]+'0';
	}
	return res;
}

//将int对象转化为Num对象。
Num *int_to_Num(int tar){
	int digit=0;
	Num *num=(Num*)calloc(1,sizeof(Num));
	num->con=(int*)calloc(Len,sizeof(Num));
	if(tar<0){num->sig=0;}
	else{num->sig=1;}
	for(digit=0;tar>0;digit++){
		num->con[digit]=tar%10;
		tar/=10;
	}
	num->len=digit;
	return num;
}	

//将Num对象转化为int对象（可能会爆表）。
int Num_to_int(Num *num){
	int tar=0;
	for(int digit=0;digit<Len;digit++){
		tar+=num->con[digit]*power(10,digit);
	}
	tar*=num->sig=1?1:-1;
	return tar;
}

//初始化pro对象
Pro *pro_creat(int sig){							
	Pro *pro=(Pro*)calloc(1,sizeof(Pro));			//分配pro空间
	pro->sig=(int*)calloc(2,sizeof(int));			//分配并写入运算类型
	pro->sig[0]=sig;								
	pro->nums=(Num*)calloc(2,sizeof(Num));			//分配运算对象空间
	pro->nums[0].con=(int*)calloc(Len,sizeof(int));	
	pro->nums[1].con=(int*)calloc(Len,sizeof(int));	
	pro->res=(Num*)calloc(sig!=3?1:2,sizeof(Num));	//分配运算结果的空间
	pro->res[0].con=(int*)calloc(Len,sizeof(int));	
	if(sig==3){pro->res[1].con=(int*)calloc(Len,sizeof(int));}	//如果是除法，给余数分配空间
	return pro;
}

//将num对象写入pro中。
void Num_to_pro(Pro *pro,Num *num,int dig){
	pro->nums[dig]=*num;
}

//pro的正式运算
void pro_start(Pro *pro){
	int bi,sm;
	pro->sig[1]=num_abs_compare(pro->nums,pro->nums+1);
	if(pro->sig[0]<2){
		if(pro->sig[0]!=(pro->nums[0].sig*pro->nums[1].sig)){
			//ba_add(pro->nums[0],pro->nums[1]);
			//printf("开始加法。对象为%s和%s\n",Num_to_str(pro->nums),Num_to_str(pro->nums+1));
//			pro->res=str_to_Num("3999");
			int tig=0;
			for(int digit=0;digit<Len;digit++){
				pro->res->con[digit]=pro->nums[0].con[digit]+pro->nums[1].con[digit]+tig;
				//printf("%d",pro->res->con[digit]);
				if(pro->res->con[digit]>9){
					pro->res->con[digit]-=10;
					tig=1;
				}else{tig=0;}
			}
			if(tig==1){printf("数据过大溢出，请调整Len值后重新编译运行！\n");}
			pro->res->sig=pro->nums->sig;
			pro->res->len=(pro->sig[1]==1)?pro->nums[0].len:pro->nums[1].len;
		}else{
			//ba_dec(pro->nums[0],pro->nums[1]);
			//printf("开始减法。对象为%s和%s\n",Num_to_str(pro->nums),Num_to_str(pro->nums+1));
			if(pro->sig[1]==0){
				pro->res=str_to_Num("0");
			}else{
				if(pro->sig[1]==1){
					bi=0,sm=1;
					pro->res->sig=pro->nums->sig;
				}else if(pro->sig[1]==2){
					bi=1,sm=0;
					pro->res->sig=pro->nums->sig==1?0:1;
				}
				for(int digit=0,tig=0;digit<Len;digit++){
					pro->res->con[digit]=pro->nums[bi].con[digit]-pro->nums[sm].con[digit]-tig;
					if(pro->res->con[digit]<0){
						pro->res->con[digit]+=10;
						tig=1;
					}else{
						tig=0;
					}
				}
				int len=0;
				for(len=Len;pro->res->con[len-1]==0;len--){}
				pro->res->len=len;
					
			}
		}
	}else if (pro->sig[0]==2){
		printf("开始乘法");
		if(pro->nums[0].sig==pro->nums[1].sig){
			pro->res->sig=1;
		}else{pro->res->sig=0;}
		for(int a=0;a<Len;a++){
			pro->res->con[a]=0;
		}
		for(int a=0;a<Len;a++){
			for(int b=0;b<Len;b++){
				int mid=0;int tig=a+b;
				pro->res->con[tig]+=pro->nums[0].con[a]*pro->nums[1].con[b];
				while(pro->res->con[tig]>9){
					mid=pro->res->con[tig]/10;
					pro->res->con[tig]%=10;
					pro->res->con[++tig]+=mid;
				}
			}
		}
	}else if (pro->sig[0]==3){
		printf("开始除法");
	}
}

void test6(){
	
}

void test5(){
	for(int a=0;a<1000;a++){
	for(int b=0;b<1000;b++){
		Pro *pro=pro_creat(0);
		Num_to_pro(pro,int_to_Num(a),0);
		Num_to_pro(pro,int_to_Num(b),1);
		pro_start(pro);
		if(Num_to_int(pro->res)!=a+b){
			printf("好像错了？\n");
		}
	}}
}

void test4(){
	printf("1000 is %s\n",Num_to_str(int_to_Num(1000)));	
	printf("1000 is %d\n",Num_to_int(str_to_Num("1000")));
}

void test3(){
	char *one="1000";
	char *two="1";
 	Pro *pro=pro_creat(1);
	Num_to_pro(pro,str_to_Num(one),0);
	Num_to_pro(pro,str_to_Num(two),1);
	pro_start(pro);
	printf("%s\n",Num_to_str(pro->res));
}

void test2(){
	char *num_char="-1000000000000031415926";
	Num *num=str_to_Num(num_char);
	printf("%s\n",Num_to_str(num));

}



void test1(){
	int length=100;
	Num *num=(Num*)calloc(1,sizeof(Num));
	num->sig=1;
	num->con=(int*)calloc(Len,sizeof(int));
	for(int digit=0;digit<length;digit++){
		num->con[digit]=9;
	}	num->len=length;
	printf("%s\n",Num_to_str(num));
}

int main(){
	test6();
	return 0;
}

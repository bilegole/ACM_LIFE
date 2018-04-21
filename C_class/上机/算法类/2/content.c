#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Len 1000	//定义此运算体系中支持的最大长度 

//此运算体系中用于存储数字的对象。 
struct Num{
	int con[Len];
	int sig;		//代表此数字的正负号。0为负，1为正 
	int len; 
};

//此运算体系中一次外显的运算过程。 
struct Pro{
	struct Num nums[2];
	int sig[2];	//0位代表运算类型，0-加		1-减	2-乘	3-除 
					//1位代表较大的数字的下标
	struct Num result; 
}; 

//此运算体系中输入一个长数 
//输入：以字符串形式存储的一个数字 ，负号加在最前面。 
void NumIn(char *s_num,struct *Num result){
	struct Num *res=(struct Num *)calloc(1,sizeof(struct Num));
	for(int digit=0;digit<Len;digit++){
		res->con[digit]=0;
	}
	res->sig=s_num[0]=='-'?1:0;
	res->len=strlen(s_num)-res->sig;
	for(int digit=0;digit+res->sig<res->len;digit++){
		res->con[digit]=s_num[res->len-digit-1];
	}
	res->sig=!res->sig;
	*result=*res;
}

//内在的两同号数相加运算 
void ba_add(struct Num *num,struct Num *res){
	for(digit=0;digit<Len;digit++){
		res->con[digit]=0;
	}
	int tig=0;		//这个变量用于记录进位与否。 
	int dig=0; 		//这个代表正在运算的位数。 
	for(digit=0;digit<Len;digit++){
		res.con[digit]=num[0].con[digit]+num[1].con[digit]+tig;
		if(res.con[digit]>9){	
			tig=1;
			res.con[digit]-=10;
		}else{
			tig=0;
		}
	} 
	res.sig=num[0].sig;
} 

//内在的两同号数大减小运算 
void ba_dec(struct Num *num,struct Num *res){		//保证【0】一定大于【1】 
	for(digit=0;digit<Len;digit++){
		res->con[digit]=0;
	}
	int tig=0;		//用于记录拆借的数。
	int dig=0;		//同上。
	for(digit=0;digit<Len;digit++){
		res->con[digit]=num[0].con[digit]-num[1].con[digit]-tig;
		if(res->con[digit]<0){
			res->con[digit]+=10;
			tig=1;
		}else{
			tig=0;
		}
	}
	res.sig=num[0].sig;
}

//乘法 
void ba_mul(struct Num *num,struct Num *res){
	for(digit=0;digit<Len;digit++){
		res->con[digit]=0;
	}
	int n=0,n1=0,n2=0;
	for(co1=0;co1<num[0].len;co1++){
		for(co2=0;co2<num[1].len;co2++){
			n=num[0].con[co1]*num[1].con[co2];
			n1=n/10,n2=n%10;	//n1代表高位，n2代表低位
			res.con[co1+co2]+=n2;
			res.con[co1+co2+1]+=n1; 
		}
	}
	res.sig=num[0].sig==num[1].sig; 
}

//除法 
void ba_div(struct Num *num,struct Num *res){
//	for(digit=0;digit<Len;digit++){
//		res->con[digit]=0;
//	}
//	int bnum[Len]=0;
//	for(digit=num[0].len-num[1].len;digit>=0;digit--){
//		for(int dig=digit;digit<num[0].len;digit++){
//			
//		}
//		for(res->con[digit]=0;)
//	}
}

//定义了一次外显的运算，	pro			外显运算的储存位置
//							num1，num2	参与运算的两个数字
//							type		外线运算的种类	0-加	1-减	2-乘	3-除 
void pro_init(struct Pro *pro,struct Num num1,struct Num num2,int type){		 
	pro->nums[0]=num1;
	pro->nums[1]=num2;
	pro->sig[0]=type;
	for(int digit=Len-1;digit>=0;digit--){
		if(pro->nums[0].con[digit]>pro->nums[1].con[digit]){
			pro->sig[1]=0;
			break;
		} else if(pro->nums[0].con[digit]<pro->nums[1].con[digit]){
			pro->sig[1]=1;
			break;
		} else if(digit==0){
			pro->sig[1]=-1;
		}
		
	} 
	switch (type)	//开始运算 
	{
		if(type<2){
			if(type*(pro->nums[0].sig==pro->nums[1].sig)){
				struct Num numin[2]={pro->nums[0],pro->nums[1]};
				ba_add(numin,pro->result);
			}else{

			}
	}
}




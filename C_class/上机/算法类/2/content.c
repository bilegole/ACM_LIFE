#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Len 1000	//�����������ϵ��֧�ֵ���󳤶� 

//��������ϵ�����ڴ洢���ֵĶ��� 
struct Num{
	int con[Len];
	int sig;		//��������ֵ������š�0Ϊ����1Ϊ�� 
	int len; 
};

//��������ϵ��һ�����Ե�������̡� 
struct Pro{
	struct Num nums[2];
	int sig[2];	//0λ�����������ͣ�0-��		1-��	2-��	3-�� 
					//1λ����ϴ�����ֵ��±�
	struct Num result; 
}; 

//��������ϵ������һ������ 
//���룺���ַ�����ʽ�洢��һ������ �����ż�����ǰ�档 
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

//���ڵ���ͬ����������� 
void ba_add(struct Num *num,struct Num *res){
	for(digit=0;digit<Len;digit++){
		res->con[digit]=0;
	}
	int tig=0;		//����������ڼ�¼��λ��� 
	int dig=0; 		//����������������λ���� 
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

//���ڵ���ͬ�������С���� 
void ba_dec(struct Num *num,struct Num *res){		//��֤��0��һ�����ڡ�1�� 
	for(digit=0;digit<Len;digit++){
		res->con[digit]=0;
	}
	int tig=0;		//���ڼ�¼��������
	int dig=0;		//ͬ�ϡ�
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

//�˷� 
void ba_mul(struct Num *num,struct Num *res){
	for(digit=0;digit<Len;digit++){
		res->con[digit]=0;
	}
	int n=0,n1=0,n2=0;
	for(co1=0;co1<num[0].len;co1++){
		for(co2=0;co2<num[1].len;co2++){
			n=num[0].con[co1]*num[1].con[co2];
			n1=n/10,n2=n%10;	//n1�����λ��n2�����λ
			res.con[co1+co2]+=n2;
			res.con[co1+co2+1]+=n1; 
		}
	}
	res.sig=num[0].sig==num[1].sig; 
}

//���� 
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

//������һ�����Ե����㣬	pro			��������Ĵ���λ��
//							num1��num2	�����������������
//							type		�������������	0-��	1-��	2-��	3-�� 
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
	switch (type)	//��ʼ���� 
	{
		if(type<2){
			if(type*(pro->nums[0].sig==pro->nums[1].sig)){
				struct Num numin[2]={pro->nums[0],pro->nums[1]};
				ba_add(numin,pro->result);
			}else{

			}
	}
}




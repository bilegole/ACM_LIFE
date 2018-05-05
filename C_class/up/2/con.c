#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define isTest 1
struct para_cal{
	char *con;
	int cen[128],words[26];
	int len;
};

struct para_cal *init_para(char *parag){
	struct para_cal *para=(struct para_cal*)calloc(1,sizeof(struct para_cal));
	para->len=strlen(parag);
	para->con=(char*)calloc(para->len,sizeof(char));
	for(int i=0;i<para->len;i++){
		para->con[i]=parag[i];
	}
	return para;
}

int char_cen(struct para_cal *para){
	para->len=strlen(para->con);
	for(int i=0;i<128;i++){para->cen[i]=0;}
	for(int digit=0;digit<para->len;digit++){
		if(para->con[digit]>127||para->con[digit]<0){
			printf("please input right words,be sure they are Ascii!\n");
			return 1;
		}
		para->cen[para->con[digit]]++;
	}
	for(int i=0;i<26;i++){
		para->words[i]=para->cen[64+i]+para->cen[97+i];
	}
	return 0;
}

void print_words_cen(struct para_cal *para){
	char *out=(char*)calloc(para->len+1,sizeof(char));
	for(int i=0;i<26;i++){
		printf("%c %d	\n",i+65,para->words[i]);
	}
}

void print_word(char *p,int len){
	char *i=(char*)calloc(len+1,sizeof(char));
	for(int m=0;m<len;m++){
		i[m]=p[m];
	}	i[len]='\0';
	printf("%d\t%s\n",len,i);
}

char *search_replace(char *para,char *sea,char *tar){
	int len1=strlen(para);
	int len2=strlen(sea);
	int len3=strlen(tar);
	printf("%d  %d  %d  \n",len1,len2,len3);
	char *one,*two,*the,*sto,*res;
	sto=(char*)calloc(len1,sizeof(char));
	for(int i=0;i<len1;i++){
		sto[i]=para[i];
	}	if(isTest==1){print_word(sto,len1);}
	for(int digit=0;digit<len1-len2+1;printf("digit:%d\n",++digit)){
		int dig=0;
		for(dig=0;dig<len2;dig++){
			if(sto[digit+dig]!=sea[dig]){break;}
		}	if(dig==len2){	

			one=(char*)calloc(digit,sizeof(char));
			for(dig=0;dig<digit;dig++){
				one[dig]=sto[dig];
			}	if(isTest==1){print_word(one,digit);}

			two=(char*)calloc(len3,sizeof(char));
			for(dig=0;dig<len3;dig++){
				two[dig]=tar[dig];
			}	if(isTest==1){print_word(two,len3);}

			the=(char*)calloc(len1-digit-len2,sizeof(char));
			for(dig=0;dig<len1-digit-len2;dig++){
				the[dig]=sto[digit+len2+dig];
			}	if(isTest==1){print_word(the,len1-digit-len2);}

			res=(char*)calloc(len1+len3-len2+1,sizeof(char));
			for(int i=0;i<len1+len3-len2+1;i++){
				if(i<digit){
					res[i]=sto[i];
				}else if(i<digit+len3){
					res[i]=tar[i-digit];
				}else {
					res[i]=the[i-len3-digit];
				}
			}	res[len1+len3-len2]='\0';
			printf("%s\n",res);
		}
	}
	return res;
}

void file_save(char *artical,char *name){
	FILE *file=fopen(name,"w");
	for(int i=0;artical[i]!='\0';i++){
		fputc(artical[i],file);
	} 	
	fclose(file);
}

void display1(){
	char artical[100]="hello world!";
	struct para_cal *pro=init_para(artical);
	char_cen(pro);
	print_words_cen(pro);
}

void display2(){
	char artical[100]="111111222111";
	char *res=search_replace(artical,"222","333");
	printf("%s\n",res);	
	char name[10]="date.txt";
	file_save(artical,name);
}
int main(){
	display2();
	return 0;
}

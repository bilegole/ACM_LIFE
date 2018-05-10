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
		para->words[i]=para->cen[65+i]+para->cen[97+i];
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
	if(isTest){printf("%d  %d  %d  \n",len1,len2,len3);}
	char *one,*two,*the,*sto,*res;
	sto=(char*)calloc(len1,sizeof(char));
	for(int i=0;i<len1;i++){
		sto[i]=para[i];
	}	if(isTest==1){print_word(sto,len1);}
	for(int digit=0;digit<len1-len2+1;++digit){
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

            int a=digit,b=len3,c=len1-digit-len2;
			sto=(char*)calloc(a+b+c,sizeof(char));
			for(int i=0;i<a+b+c;i++){
				if(i<a){
					sto[i]=one[i];
				}else if(i<a+b){
					sto[i]=two[i-digit];
				}else {
			        sto[i]=the[i-len3-digit];
				}
			}	sto[a+b+c]='\0';
            len1=a+b+c;
			if(1){printf("11%s\n",sto);}
		}
	}
	return sto;
}

void file_save(char *artical,char *name){
	FILE *file=fopen(name,"w");
	for(int i=0;artical[i]!='\0';i++){
		fputc(artical[i],file);
	} 	
	fclose(file);
}

void display1(){
	char artical[100]={0};
    scanf("%s",artical);
	struct para_cal *pro=init_para(artical);
	char_cen(pro);
	printf("word:%s\n",artical);
	print_words_cen(pro);
}

void display2(){
    
	char artical[100]={0};
	char tore[100]={0};
	char bere[100]={0};
    scanf("%s",artical);
    scanf("%s",bere);
    scanf("%s",tore);
	printf("the sentence before:\n\"%s\"\n",artical);
	printf("Want the \"%s\" to be replaced as \"%s\"\n",bere,tore);
	char *res=search_replace(artical,bere,tore);
	printf("%s\n",res);	
	char name[10]="date.txt";
	printf("save file as %s\n",name);
    struct para_cal *pro=init_para(artical);
    char_cen(pro);
    print_words_cen(pro);
	file_save(artical,name);
}
int main(){
//	printf("display1:\n");
//	display1();
	printf("display2:\n");
	display2();
	return 0;
}

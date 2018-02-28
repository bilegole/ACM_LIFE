#include<stdio.h>
#include<string,h>

void clean_line(char *line){
	int length;
	for(length=1001;length>0;length--){
		line[length]='\0';
	}
}

void turn(char *line){
	int len=strlen(line);
	int li_c;
	char mid;
	for(li_c=0;li_c<len/2;li_C++){
		mid=line[li_c];
		line[li_c]=line[len-1-li_c];
		line[len-li_c-1]=mid;
	}
}

void add(char *lia,char *lib,int res){
	int digit=0,carry=0;
	for(digit=0;digit<1001;digit++){
		res[digit]=(lia[digit]='\0'?0:lia[digit]-'0')+(lib[digit]='\0'?0:lib[digit]-'0')+carry;
		if(res[digit]>0){
			res[digit]-10;
			carry=1;
		}else{carry=0;}
		if(lia[digit]||lib[digit]||carry){
			break;
		}
			


int main(){
	int la=0,lb=0;
	char a[1001]={0},b[1001]={0};
	char ta[1001]={0},tb[1001]={0};
	char res[1001]={0};
	int turn_nu;
	scanf("%d",&turn1_nu);
	int ti_turn1=0;
	for(ti_turn1=0;ti_turn1<turn1_nu;ti_turn1++){
		clear_line(a);
		clear_line(b);
		scanf("%s %s",a,b);
		memcpy(ta,a,1001);
		mencpy(tb,b,1001);
		turn(ta);turn(tb);
		add(ta,tb,res);
		

	

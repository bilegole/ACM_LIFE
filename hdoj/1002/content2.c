#include<stdio.h>
#include<string.h>

int charToint(char aim){
	if(aim=='\0'){return 0;}
	else {return (int)(aim-'0');}
}

void clear_line(char *line){
	int length;
	for(length=1001;length>0;length--){
		line[length]='\0';
	}
}

void turn(char *line){
	int Len=strlen(line);
	int digit;
	char mid;
	for(digit=0;digit<Len/2;digit++){
		mid=line[digit];
		line[digit]=line[Len-1-digit];
		line[Len-digit-1]=mid;
	}
}

int add(char *lia,char *lib,int *res){
	int digit=0,carry=0;
	for(digit=0;digit<1001;digit++){
		res[digit]=charToint(lia[digit])+charToint(lib[digit])+carry;
		//printf("%d\t%d\n",res[digit],carry);
		if(res[digit]>9){
			res[digit]-10;
			carry=1;
		}else{carry=0;}

		if( lia[digit]=='\0'
		&&	lib[digit]=='\0'
		&&  carry==0       ){break;}
		
	}
	return digit;

}
	
int main(){
	int la=0,lb=0;
	char a[1001]={0},b[1001]={0};
	char ta[1001]={0},tb[1001]={0};
	int res[1001]={0};
	int lor=0;//length of result[1001];
	int co_turn1=0,Ra_turn1;
	scanf("%d",&Ra_turn1);
	for(co_turn1=0;co_turn1<Ra_turn1;co_turn1++){
		clear_line(a);
		clear_line(b);
		scanf("%s %s",a,b);
		printf("Case %d:\n%s + %s = ",co_turn1+1,a,b);
		memcpy(ta,a,1001);
		memcpy(tb,b,1001);
		turn(ta);turn(tb);
		//printf("\n%s %s\n",ta,tb);
		lor=add(ta,tb,res);
		int Co_Turn2=0;
		for(Co_Turn2=lor;Co_Turn2>0;Co_Turn2--){
			printf("%d",res[Co_Turn2-1]);
		}
		if(co_turn1<Ra_turn1-1){printf("\n\n");}
		else{printf("\n");}
	}
	return 0;
}
			
		

	

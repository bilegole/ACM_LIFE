#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define filename "data.txt"

struct User{
	int id,exist;
	char name[100];
	int sex;
	char phone[12];
	char email[100];
	char address[100];
};

struct List{
	int list[10000];
	int cur;
};

struct Lib{
	struct User users[10000];
	int cursor;
};

struct Lib *init_lib(){
	struct Lib *lib=(struct Lib*)calloc(1,sizeof(struct Lib));
	for(int i=0;i<10000;i++){
		lib->users[i].id=i;
		lib->users[i].exist=0;
	}
	return lib;
}

int init_user(struct Lib *lib){
	for(int i=0;i<10000;i++){
		if(lib->users[i].exist=0){
			lib->cursor=i;
			lib->users[i].id=i;
			lib->users[i].exist=1;
			break;
		}
	}
	return lib->cursor;
}

void print_user(struct Lib *lib){
	struct User user=lib->users[lib->cursor];
	if(user.exist==0){
		printf("User does not exist!\n");
	}else{
		printf("------------------------------------------------\n");
		printf("ID:%d\n\tName:%s\n\tSex:%s\n\tPhone numser:%s\n\te-mail:%s\n\tAddress:%s\n\t",user.id,user.name,user.sex==1?"boy":"girl",user.phone,user.email,user.address);
		printf("------------------------------------------------\n");
	}
}

void print_by_list(struct Lib *lib,struct List *list){
	for(int i=0;i<list->cur;i++){
		lib->cursor=list->list[i];
		print_user(lib);
		printf("\n\n");
	}
}

void print_all(struct Lib *lib){
	for(int i=0;i<10000;i++){
		if(lib->users[i].exist==0){continue;}
		lib->cursor=i;
		print_user(lib);
	}
}

void user_add_name(struct Lib *lib,char *name){
	int len=strlen(name);
	int i=0;
	for(i=0;i<len;i++){
		lib->users[lib->cursor].name[i]=name[i];
	}	lib->users[lib->cursor].name[i]='\0';
}

void user_add_sex(struct Lib *lib,int sex){
	lib->users[lib->cursor].sex=sex;
}

void user_add_phone(struct Lib *lib,char *phone){
	for(int i=0;i<12;i++){
		lib->users[lib->cursor].phone[i]=phone[i];
	}
}

void user_add_email(struct Lib *lib,char *email){
	int len=strlen(email);
	for(int i=0;i<len+1;i++){
		lib->users[lib->cursor].email[i]=email[i];
	}
}

void user_add_address(struct Lib *lib,char *address){
	int len=strlen(address);
	for(int i=0;i<len+1;i++){
		lib->users[lib->cursor].address[i]=address[i];
	}
}

void add_user(struct Lib *lib){
	init_user(lib);
	while(1){
		printf("Please input your name....\n");
		char name[100];
		scanf("%s",name);
		user_add_name(lib,name);
		printf("Are you a boy or a gril?(boy:1,gril:0)\n");
		int sex;
		scanf("%d",&sex);
		user_add_sex(lib,sex);
		printf("What is your phone number?\n");
		char phone[100];
		while(1){
			scanf("%s",phone);
			if(strlen(phone)==11){
				break;
			}else{
				printf("Wrong formate!\ntell me again!\n");
			}
		}
		user_add_phone(lib,phone);
		printf("What is your email?\n");
		char email[100];
		scanf("%s",email);
		user_add_email(lib,email);
		printf("What is your address?\n");
		char address[100];
		scanf("%s",address);
		user_add_address(lib,address);
		printf("So,is your imformation Right?(yes:1,no:0)\n");
		print_user(lib);
		int yon;
		scanf("%d",&yon);
		if(yon==1){break;}
	}
}

struct List *search_name(struct Lib *lib,char *name){
	struct List *list=(struct List*)calloc(1,sizeof(struct List));
	list->cur=0;
	int len=strlen(name);
	for(int i=0;i<10000;i++){
		int tig=1;
		for(int digit=0;digit<len&&tig==1;digit++){
			if(lib->users[i].name[digit]!=name[digit]&&lib->users[i].exist==1){
				tig=0;
			}
		}
		if(tig==1){
			list->list[list->cur]=i;
			list->cur+=1;
		}
	}
	return list;
}

struct List *search_sex(struct Lib *lib,int sex){
	struct List *list=(struct List*)calloc(1,sizeof(struct List));
	list->cur=0;
	for(int i=0;i<10000;i++){
		if(lib->users[i].sex==sex&&lib->users[i].exist==1){
			list->list[list->cur]=i;
			list->cur+=1;
		}
	}
	return list;
}

struct List *search_phone(struct Lib *lib,char *phone){
	struct List *list=(struct List*)calloc(1,sizeof(struct List));
	list->cur=0;
	for(int i=0;i<10000;i++){
		int tig=1;
		for(int digit=0;digit<11&&tig==1;digit++){
			if(lib->users[i].phone[digit]!=phone[digit]&&lib->users[i].exist==1){
				tig=0;
			}
		}
		if(tig==1){
			list->list[list->cur]=i;
			list->cur+=1;
		}
	}
	return list;
}

struct List *search_email(struct Lib *lib,char *email){
	struct List *list=(struct List*)calloc(1,sizeof(struct List));
	list->cur=0;
	int len=strlen(email);
	for(int i=0;i<10000;i++){
		int tig=1;
		for(int digit=0;digit<len&&tig==1;digit++){
			if(lib->users[i].email[digit]!=email[digit]&&lib->users[i].exist==1){
				tig=0;
			}
		}
		if(tig==1){
			list->list[list->cur]=i;
			list->cur+=1;
		}
	}
	return list;
}

struct List *search_address(struct Lib *lib,char *address){
	struct List *list=(struct List*)calloc(1,sizeof(struct List));
	list->cur=0;
	int len=strlen(address);
	for(int i=0;i<10000;i++){
		int tig=1;
		for(int digit=0;digit<len&&tig==1;digit++){
			if(lib->users[i].address[digit]!=address[digit]&&lib->users[i].exist==1){
				tig=0;
			}
		}
		if(tig==1){
			list->list[list->cur]=i;
			list->cur+=1;
		}
	}
	return list;
}

void delete_user(struct Lib *lib){
	lib->users[lib->cursor].exist=0;
}

void delete_by_list(struct Lib *lib,struct List *list){
	for(int i=0;i<list->cur;i++){
		lib->cursor=list->list[i];
		delete_user(lib);
	}
}

void lib_load(struct Lib *lib){
	FILE *file;
	char line[200];
	while(1){
		if((file=fopen(filename,"r"))==NULL){
			printf("Wrong File Name!\n");
		}else{
			while(fscanf(file,"%s",line)!=EOF){
				if(line[0]=='0'){
					int id=(line[1]-48)*1000+(line[2]-48)*100+(line[3]-48)*10+(line[4]-48);
					lib->cursor=id;
					int sex=line[5]-'0';
					char phone[12]={0};
					for(int i=0;i<11;i++){
						phone[i]=line[6+i];
					}
					user_add_phone(lib,phone);
				}else if(line[0]=='1'){
					char name[100]={0};
					for(int i=0;line[i]!='\0';i++){
						name[i]=line[i+1];
					}
					user_add_name(lib,name);
				}else if(line[0]=='2'){
					char email[100]={0};
					for(int i=0;line[i]!='\0';i++){
						email[i]=line[i+1];
					}
					user_add_email(lib,email);
				}else if(line[0]=='3'){
					char address[100]={0};
					for(int i=0;line[i]!='\0';i++){
						address[i]=line[i+1];
					}
					user_add_email(lib,address);
				}	
			}
			break;
		}
	}
}

void lib_save(struct Lib *lib){
	FILE *file;
	while(1){
		if((file=fopen(filename,"w"))!=NULL){break;}
		else{printf("Fail to open.\n");}
	}
	for(int i=0;i<10000;i++){
		if(lib->users[i].exist==1){
			fputc('0',file);
			fputc('0'+(i%10000)/1000,file);
			fputc('0'+(i%1000)/100,file);
			fputc('0'+(i%100)/10,file);
			fputc('0'+i%10,file);
			for(int dig=0;dig<11;dig++){
				fputc(lib->users[i].phone[dig],file);
			}	fputc(0,file);fputc(10,file);
			fputc(49,file);
			for(int dig=0;dig<strlen(lib->users[i].name)+1;dig++){
				fputc(lib->users[i].name[dig],file);
			}	fputc(10,file);
			for(int dig=0;dig<strlen(lib->users[i].email)+1;dig++){
				fputc(lib->users[i].email[dig],file);
			}	fputc(10,file);
			for(int dig=0;dig<strlen(lib->users[i].address)+1;dig++){
				fputc(lib->users[i].address[dig],file);
			}	fputc(10,file);
			fputc(35,file);fputc(10,file);
		}
	}
}

void display1(){
	char cmd[200];
	int d;
	struct Lib *lib=init_lib();
	while(1){
		printf("Please input your command:\n");
		scanf("%s",cmd);
		if(cmd[0]=='1'){//输出所有内容
			print_all(lib);
		}else if(cmd[0]=='2'){
			printf("help!help!help!\n");
		}else if(cmd[0]=='3'){
			lib_save(lib);
		}else if(cmd[0]=='4'){
			lib_load(lib);
		}else if(cmd[0]=='.'){
			if(cmd[1]='c'){
				char name[100];
				printf("name!\n");
				scanf("%s",name);
				user_add_name(lib,name);
			}else if(cmd[1]=='s'){
				lib_save(lib);
			}else if(cmd[1]=='d'){
				printf("tell me which you want to delete?\n");
				scanf("%d",&d);
				lib->users[d];
			}else if(cmd[1]=='r'){
				lib_load(lib);
			}else if(cmd[1]=='p'){
				print_all(lib);
			}else if(cmd[1]=='q'){
				if(cmd[2]=='1'){
				}else if(cmd[2]=='2'){
				}else if(cmd[2]=='3'){
				}
			}
		}
	}
}


int main(){
	display1();
	return 0;
}


















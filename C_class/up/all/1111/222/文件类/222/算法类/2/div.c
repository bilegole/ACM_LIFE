#include<stdio.h>

void ba_div(struct Num *nums,struct Num *res){
	int nu1[Len],nu2[Len];
	for(int digit=nums[0].len-nums[1].len;digit>=0;digit--){
		for(int dig1=digit;dig1<nums[0].len;digit++){
			nu1[dig1-digit]=nums[0].con[dig1];
			nums[0].con[dig1]=0;
		}
		res[0].con[digit]=0;
		while(1){
			
		}

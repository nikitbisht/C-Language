/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/
#include<stdio.h>
int main(){
  int n,i,j,target,sum,flag=0;
  printf("enter the sizeof array:- ");
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
  	scanf("%d",&a[i]);
  }
  printf("Enter the target:- ");
  scanf("%d",&target);
  for(i=0;i<n;i++){
    int item1=a[i];
    for(j=0;j<n;j++){
        int item2=a[j];
        sum=item1+item2;
         if(target==sum){
    		printf("[%d,%d]",i,j);
			return 0;
  		}
	}
  }
  if(flag==0){
  	printf("Target not found");
  }
  return 0;
}

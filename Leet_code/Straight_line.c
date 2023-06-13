/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
Check if these points make a straight line in the XY plane.

Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
*/
#include<stdio.h>
int main(){
	int x1,x2,x3,y1,y2,y3;
	printf("Enter the cordinate of 1 point:- ");
	scanf("%d %d",&x1,&y1);
	printf("Enter the cordinate of 2 point:- ");
	scanf("%d %d",&x2,&y2);
	printf("Enter the cordinate of 3 point:- ");
	scanf("%d %d",&x3,&y3);
	//you can add more point and their cordinate accroding to your need
	int m=(y2-y1)/(x2-x1);
	int n=(y3-y2)/(x3-x2);
	//like if add one move point then
	//int o=(y4-y3)/(x4-x3);
	if(n==m)		//then this condition is if(n==m==o)
		printf("True");
	else
		printf("false");
	return 0;
}

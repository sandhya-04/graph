#include<bits/stdc++.h>
using namespace std;
int R,C;
void printmat(char mat[][50])
{
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		cout<<mat[i][j]<<" ";
	cout<<endl;	
	}
	
}
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

void floodfill(char mat[][50],int i,int j,char ch,char ch2)
{
	if(i<0 || j<0 || i>=R || j>=C)  //base case
	{
		return ;
	}
	if(mat[i][j]!=ch)
	return;
	
	mat[i][j]=ch2;
	
	for(int k=0;k<4;k++)
	{
		floodfill(mat,i+dx[k],j+dy[k],ch,ch2);
	}
}
int main()
{
	cin>>R>>C;
	char mat[15][50];
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		cin>>mat[i][j];
	}
	floodfill(mat,0,0,'.','r');
	
	printmat(mat);
}

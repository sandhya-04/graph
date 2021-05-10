#include<bits/stdc++.h>
using namespace std;
struct ludo{
    int num;
    int dice;
};

int game(int n,int board[])
{
    queue<ludo>q;
    
    ludo l={0,0};
    q.push(l);
    
    bool *vis=new bool[n];
    
    for(int i=0;i<n;i++)
    vis[i]=false;
    
    vis[0]=false;
    ludo s;
    while(!q.empty())
    {
        s=q.front();
        int v=s.num;
        q.pop();
        
        if(v==n-1)
        break;
        for(int j=v+1;j<=v+6;j++)
        {
            if(!vis[j])
            {
                ludo k;
                k.dice=s.dice+1;
                vis[j]=true;
                
                if(board[j]!=-1)
                k.num=board[j];
                
                else
                k.num=j;
                
                q.push(k);                
            }
        }
        
    }
    return s.dice;
}
int main()
{
    int n;
    cin>>n;
    int moves[n];
    for(int i=0;i<n;i++)
    moves[i]=-1;
    
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
  
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
		cout<<game(n,moves)<<endl;
}

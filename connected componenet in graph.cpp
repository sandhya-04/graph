#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
    map<int,list<T> >l;
  public:
  void addedge(int x,int y){
      l[x].push_back(y);
      l[y].push_back(x);
  }
  void dfs_helper(T src,map<int,bool> &vis)
  {
      cout<< src <<" ";
      vis[src]=true;
      
      for(auto p:l[src]){
          if(!vis[p])
          {
              vis[p]=true;
              dfs_helper(p,vis);
          }
      }
  }
  void dfs(){
      map<int,bool>vis;
      for(auto s:l)
      {
          T nbr=s.first;
          vis[nbr]=false;
      }
      int count=0;
      for(auto p:l){
          T node=p.first;
          if(!vis[node]){
              cout<<"connected componenet"<<count<<"---->";
              dfs_helper(node,vis);
              count++;
             cout<<endl;
          }
      }
  }
  
};
int main()
{
    graph<int>g;
    g.addedge(2,1);
	g.addedge(2,3);
	g.addedge(3,2);
	g.addedge(3,0);
	g.addedge(1,2);
	g.addedge(1,0);
	g.addedge(0,1);
	g.addedge(3,4);
	g.addedge(4,3);
	g.addedge(4,5);
	g.addedge(5,4);
	g.dfs();
}

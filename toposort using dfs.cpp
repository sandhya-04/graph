#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
	map<int,list<T> >l;
	public:
		void eddedge(int x,int y){
			l[x].push_back(y); //directed graph
		}
		
		void dfs_helper(map<T,bool>&vis,T src,stack<T> s)
		{
			vis[src]=true;
			
			for(auto p:l[src]){
				if(!vis[p])
				{
					dfs_helper(vis,p,s);
				}
			}
			s.push(src);
		}
		
		void dfs_topo(){
			map<T,bool>vis;
			stack<T>s;
			for(auto d:l)
			{
				T node=d.first;
				vis[node]=false;
			}
			for(auto d:l){
				T nbr=d.first;
				if(!vis[nbr])
				{
					dfs_helper(vis,nbr,s);
				}
			}
			
			while(!s.empty())
			{
				T r=s.top();
				cout<<r<<" ";
				s.pop();
			}
		}
};
int main()
{
	graph<int>g;
	g.eddedge(5,2);
	g.eddedge(5,0);
	g.eddedge(4,0);
	g.eddedge(4,1);
	g.eddedge(2,3);
	g.eddedge(3,1);
	
	g.dfs_topo();
}

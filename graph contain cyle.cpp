#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
	map<int,list<T> >l;
	public:
		void addedge(int x,int y)
		{
			l[x].push_back(y);
			l[y].push_back(x); //bi-directional
		}
		bool iscycle(map<int,bool> &vis,T src,int parent)
		{
			vis[src]=true;
			
			for(auto node:l[src]){
				if(!vis[node])
				{
					bool p=iscycle(vis,node,src);
					if(p)
					return true;
				}
				else if(node!=parent)
				{
					return true;
				}
			}
			return false;
		}
		
		bool contain_cycle(T src){
			 map<int,bool>vis;
			for(auto node:l)
      {
          T nbr=node.first;
          vis[nbr]=false;
      }
      return iscycle(vis,src,-1);
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
	
	if(g.contain_cycle(0))
	cout<<"yes,graph contains cycle"<<endl;
	else
	cout<<"graph does'nt contain sycle"<<endl;
	
	graph<int>g2;
    g2.addedge(0, 1);
    g2.addedge(1, 2);
    
    if(g2.contain_cycle(0))
	cout<<"yes,graph contains cycle"<<endl;
	else
	cout<<"graph does'nt contain sycle"<<endl;
    
}

#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
	map<int,list<T> >l;
	public:
		void addedge(int x,int y){
			l[x].addedge(y);  // directed graph
			
		}
		
		bool cycle_helper(map<T,bool>&vis,bool stack[],T src){
			
			vis[src]=true;
			stack[src]=true;
			
			for(auto p:l[src]){
				if(stack[p]==true)
				{
					return true;
				}
				if(!vis[p]){
					bool cycle=cycle_helper(vis,stack,p);
					
					if(cycle==true)
					return true;
				}
			}
			
			stack[src]=false;
			return false;
		}
		bool directed_cycle(){
			map<T,bool>vis;
			bool stack[100];
			T src;
			return cycle_helper(vis,stack,src);
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
	 if(g.iscycle())
	 cout<<"Yes"<<endl;
	 else
	 cout<<"NO"<<endl;
}

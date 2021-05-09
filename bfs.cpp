#include<bits/stdc++.h>
using namespace std;
template<typename T>
map<T,list<T> >l;
class graph{
	public:
		void addedge(int x,int y)
		{
			l[x].push_back(y);  // bidirectional
			l[y].push_back(x);
		}
		
		void bfs(T src){
			queue<T>q;
			map<T,int>vis;
			
			q.push(src);
			vis[src]=true;
			
			while(!q.empty())
			{
				T temp=q.front();
				q.pop();
				cout<<temp<<" ";
				
				for(int nbr: l[temp)
				{
					if(!vis[nbr])
					{
						q.push(nbr);
						vis[nbr]=true;
					}
				}
			}
		}
		
};
int main()
{
	graph<int> g;
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(0,2);
	g.addedge(2,3);
	g.addedge(3,1);
}

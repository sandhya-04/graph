#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
	map<T,list<T> >l;
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
			vis[src] = true;
			
			while(!q.empty())
			{
				T temp=q.front();
				q.pop();
				cout<< temp <<" ";
				
				for(int nbr : l[temp])
				{
					if(!vis[nbr])
					{
						q.push(nbr);
						vis[nbr] = true;
					}
				}
			}
		}
		
};
int main()
{
	graph<int> g;
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
	g.bfs(0);
}

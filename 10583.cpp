#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define pb push_back
#define mp make_pair
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
int parent[50050];
int rank[50050];
int find(int);
void unite(int, int);

int main()
{
	int n,m,x,y,i,ans,cn = 0;
	while(scanf("%d %d",&n,&m) && n && m)
	{
	    cn++;
	    for(i=1;i<=n;i++)
	    {
	        parent[i] = i;
	        rank[i] = 0;
	    }
	    for(i=0;i<m;i++)
	    {
	        scanf("%d %d",&x,&y);
	        unite(x,y);
	    }

	    /*for(i=1;i<=n;i++)
	    cout<<parent[i]<<" ";
	    cout<<endl;*/

	    set<int> religions;
	    for(i=1;i<=n;i++)
	    {
	        parent[i] = find(i);
	        religions.insert(parent[i]);
	    }
	    ans = (int)religions.size();
	    printf("Case %d: %d\n",cn,ans);
	}
	return 0;
}

int find(int x)
{
    if(parent[x]==x)
    return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);

    if(xroot==yroot)
    return;

    if(rank[xroot] < rank[yroot])
    {
        parent[xroot] = yroot;
    }
    else if(rank[yroot] < rank[xroot])
    {
        parent[yroot] = xroot;
    }
    else
    {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

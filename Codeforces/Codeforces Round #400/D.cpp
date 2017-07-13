#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
//#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

#define ll long long
#define SZ(x) ((int)(x).size()) 
#define ALL(v) (v).begin(), (v).end()
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define reveach(i, v) for (__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++ i) 
#define REP(i,a,n) for ( int i=a; i<int(n); i++ )
#define FOR(i,a,n) for ( int i=n-1; i>= int(a);i-- )
#define lson rt<<1, L, m
#define rson rt<<1|1, m, R
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fi first
#define se second
#define CLR(a, b) memset(a, b, sizeof(a))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define lowbit(x) (x) & (-(x))
const int N = 1e6 + 100;

vector<int>G[N];  
int dfn[N],low[N];  
int sta[N],top;  
int indx;  
int tmp[N];  
inline void addEdge(int u,int c1,int v,int c2)  
{  
    u=2*(u-1)+c1,v=2*(v-1)+c2;  
	G[u].push_back(v);
	G[v].push_back(u);
}  
  
void tarjan(int u)  
{  
    dfn[u]=low[u]=++indx;  
    tmp[u]=1;  
    sta[++top]=u;  
    int sz=G[u].size();  
    for(int i=0;i<sz;i++)  
    {  
        int v=G[u][i];  
        if(tmp[v]==0) tarjan(v);  
        if(tmp[v]==1) low[u]=min(low[u],low[v]);  
    }  
    if(dfn[u]==low[u])  
    {  
        do  
        {  
            int v=sta[top];  
          	low[v] = low[u];
		  	tmp[v]=2;  
        }while(sta[top--]!=u);  
    }  
}  

int a[N];
int toL[N][2];
int main()  
{  
	int n, m; 
    while(~scanf("%d%d",&n,&m))  
    { 
	   	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for(int id = 1; id <= m; id ++) {
			int c, t;
			scanf("%d", &c);
			while(c --) {
				scanf("%d", &t);
                if(toL[t][0] == 0) toL[t][0] = id;
                else toL[t][1] = id;
			}	
		}	
		for(int i = 1; i <= n; i ++) {
			if(a[i]) {
				addEdge(toL[i][0], 1, toL[i][1], 1);
				addEdge(toL[i][0], 0, toL[i][1], 0);
			} else {
				addEdge(toL[i][0], 1, toL[i][1], 0);
				addEdge(toL[i][0], 0, toL[i][1], 1);
			}
		}
		for(int i=0;i < 2 * m; i++) if(!tmp[i]) tarjan(i);  
		bool ans = 1; 
        for(int i=0;i< 2 * m;i++) if(low[i]==low[i^1]) ans=0;  
        if(ans) puts("YES");
		else puts("NO");
  
    }  
    return 0;  
}  

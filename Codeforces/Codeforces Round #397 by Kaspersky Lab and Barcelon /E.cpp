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
const int N = 2e5 + 7;

int n;
vector<int> G[N];
int fa[N];
int sz[N];
int dis[N];
int mxd, rt;

void dfs(int u, int f, int d){
    for(auto v : G[u]){
        if(v == f) continue;
        fa[v] = u;
        dfs(v, u, d + 1);
    }
    if(d >= mxd){
        mxd = d;
        rt = u;
    }
}
int res;
bool dfs1(int u, int f){
    int a = 0, b = 0;
    for(auto v : G[u]){
        if(v == f) continue;
        fa[v] = u;
        if(!dfs1(v, u)) return false;
        if(u == rt){
            if(a && b && sz[v] != a && sz[v] != b) return false;
            else if(a && sz[v] != a) b = sz[v];
            else a = sz[v];
        }
        if(u != rt && sz[u] && sz[v] != sz[u]){
            return false;
        }
        sz[u] = sz[v];
    }
    sz[u] ++;
    if(u == rt){
        res = a + b;
    }
    return true;
}
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    
    scanf("%d", &n);
    REP(i, 1, n){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    rt = 1;
    dfs(1, 0, 0);
    dfs(rt, 0, 0);
    /*
    if(mxd % 2 == 1){
        puts("-1");
        return 0;
    }
    */
    //cout << mxd << endl;
    //cout << rt << endl;
    {
        REP(i, 0, mxd / 2){
            rt = fa[rt];
            //printf("u = %d, fa[u] = %d\n", rt, fa[rt]);
        }
    }
    //cout << rt << endl;
    if(dfs1(rt, 0)){
        while(res % 2 == 0) res /= 2;
        printf("%d\n", res);
    }
    else puts("-1");
    return 0;
}

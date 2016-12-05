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
int col[N];
vector<int> G[N];
vector<int> E[N];
int up[N];
int p[N];
int res = N;
const bool cmp(const pii &a, const pii &b){
    return a.fi > b.fi;
}
int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]);
}
void dfs(int u, int f){
    for(auto v : G[u]){
        if(v == f) continue;
        int uu = find(u);
        //int vv = find(v);
        if(col[u] == col[v]){
            p[v] = uu;
        }
        else{
            E[uu].pb(v);
        }
        dfs(v, u);
    }
}
void dfs2(int u, int f){
    up[u] = 1;
    for(auto v : E[u]){
        if(v == f) continue;
        dfs2(v, u);
        Max(up[u], up[v] + 1);
    }
    //printf("u = %d, up[u] = %d\n", u, up[u]);
}
void dfs3(int u, int f, int down){
    //printf("u = %d, down = %d\n", u, down);
    vector<pii> t;
    for(auto v : E[u]){
        if(v == f) continue;
        t.pb(mp(up[v], v));
    }
    t.pb(mp(down, u));
    sort(t.begin(), t.end(), cmp);
    Min(res, t[0].fi);
    for(auto v : E[u]){
        if(v == f) continue;
        //if(u == 1 && v == 9) cout << t[0].se << endl;
        if(t[0].se == v) dfs3(v, u, t[1].fi + 1);
        else dfs3(v, u, t[0].fi + 1);
    }
}
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d", &n);
    REP(i, 1, n + 1) scanf("%d", &col[i]);
    REP(i, 1, n){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    REP(i, 1, n + 1) p[i] = i;
    dfs(1, 0);
    dfs2(find(1), 0);
    dfs3(find(1), 0, 0);
    
    printf("%d\n", res);
    return 0;
}

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
int n, m;
int w[N], c[N];
struct Edge{
    int u, v, w, c, id, nxt;
    Edge(){}
    Edge(int v, int w, int id, int nxt): v(v), w(w), id(id), nxt(nxt){}
    bool operator < (const Edge &t) const{
        return w < t.w;
    }
}e[N], es[N << 1];
int p[N];
int vis[N];
int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]);
}
int cnt, head[N];
void addEdge(int u, int v, int w, int id){
    es[cnt] = Edge(v, w, id, head[u]);
    head[u] = cnt ++;
    es[cnt] = Edge(u, w, id, head[v]);
    head[v] = cnt ++;
}
int dep[N];
int dp[N][22];
pii pd[N][22];
void dfs(int u, int f, int d){
    dep[u] = d;
    dp[u][0] = f;
    REP(i, 1, 22){
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
        pd[u][i] = max(pd[u][i - 1], pd[dp[u][i - 1]][i - 1]);
    }
    for(int i = head[u]; ~i; i = es[i].nxt){
        int v = es[i].v, w = es[i].w;
        if(v == f) continue;
        pd[v][0] = mp(w, es[i].id);
        dfs(v, u, d + 1);
    }
}
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &m);
    REP(i, 0, m) scanf("%d", &w[i]);
    REP(i, 0, m) scanf("%d", &c[i]);
    REP(i, 0, m){
        scanf("%d%d", &e[i].u, &e[i].v);
        e[i].w = w[i];
        e[i].c = c[i];
        e[i].id = i;
    }
    sort(e, e + m);
    REP(i, 1, n + 1) p[i] = i;
    ll sum = 0;
    CLR(head, -1);
    REP(i, 0, m){
        int u = find(e[i].u);
        int v = find(e[i].v);
        if(u == v) continue;
        vis[i] = 1;
        sum += e[i].w;
        p[u] = v;
        addEdge(e[i].u, e[i].v, e[i].w, i);
    }
    dfs(1, 0, 0);
    ll res = sum;
    int S;
    scanf("%d", &S);
    pii ans[2];
    REP(i, 0, m){
        if(vis[i]){
            if(sum - S / e[i].c <= res){
                ans[0].fi = i;
                ans[1] = mp(e[i].id, e[i].w - S / e[i].c);
                res = sum - S / e[i].c;
            }
        }
        else{
            int u = e[i].u, v = e[i].v;
            if(dep[u] < dep[v]) swap(u, v);
            pii q = mp(0, 0);
            REP(i, 0, 22){
                if((dep[u] - dep[v]) & (1 << i)){
                    Max(q, pd[u][i]);
                    u = dp[u][i];
                }
            }
            FOR(i, 0, 22){
                if(dp[u][i] != dp[v][i]){
                    Max(q, pd[u][i]);
                    Max(q, pd[v][i]);
                    u = dp[u][i];
                    v = dp[v][i];
                }
            }
            if(u != v){
                Max(q, pd[u][0]);
                Max(q, pd[v][0]);
            }
            if(sum + e[i].w - S / e[i].c - q.fi < res){
                res = sum + e[i].w - S / e[i].c - q.fi;
                ans[0].fi = q.se;
                ans[1] = mp(e[i].id, e[i].w - S / e[i].c);
            }
        }
    }
    printf("%lld\n", res);
    REP(i, 0, m) if(vis[i] && ans[0].fi != i) printf("%d %d\n", e[i].id + 1, e[i].w);
    printf("%d %d\n", ans[1].fi + 1, ans[1].se);
    return 0;
}

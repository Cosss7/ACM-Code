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
int vis[N];
struct Edge{
    int u, v, w, c, id, nxt;
    Edge(){}
    Edge(int v, int w, int nxt): v(v), w(w), nxt(nxt){}
    bool operator < (const Edge &t) const{
        return w < t.w;
    }
}e[N];
int p[N];
int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]);
}
struct SegmentTree{
    pii mx[N << 2];
    void pushUp(int rt){
        int lch = rt << 1, rch = lch | 1;
        mx[rt] = max(mx[lch], mx[rch]);
    }
    void update(int rt, int L, int R, int pos, int val, int val2){
        if(L + 1 == R){
            mx[rt] = mp(val, val2);
            return ;
        }
        int m = (L + R) >> 1;
        if(pos < m) update(lson, pos, val, val2);
        else update(rson, pos, val, val2);
        pushUp(rt);
    }
    pii query(int rt, int L, int R, int l, int r){
        if(l <= L && r >= R) return mx[rt];
        pii res = mp(-1, -1);
        int m = (L + R) >> 1;
        if(l < m) Max(res, query(lson, l, r));
        if(r > m) Max(res, query(rson, l, r));
        return res;
    }
}segt;
struct Tree{
    Edge e[N << 1];
    int cnt, head[N];
    int fa[N], dep[N], top[N], idx[N], idy[N], son[N], siz[N], totw;
    void init(){
        cnt = 0;
        CLR(head, -1);
    }
    void addEdge(int u, int v, int w, int id){
        e[cnt] = Edge(v, w, head[u]);
        e[cnt].id = id;
        head[u] = cnt ++;
        e[cnt] = Edge(u, w, head[v]);
        e[cnt].id = id;
        head[v] = cnt ++;
    }
    void dfs1(int u, int f, int d){
        dep[u] = d;
        fa[u] = f;
        siz[u] = 1;
        for(int i = head[u]; ~i; i = e[i].nxt){
            int v = e[i].v;
            if(v == f) continue;
            dfs1(v, u, d + 1);
            siz[u] += siz[v];
            if(siz[v] > siz[son[u]]) son[u] = v;
        }
    }
    void dfs2(int u, int f, int tp){
        idx[u] = totw ++;
        top[u] = tp;
        if(son[u]) dfs2(son[u], u, tp);
        for(int i = head[u]; ~i; i = e[i].nxt){
            int v = e[i].v;
            if(v != f && v != son[u]) dfs2(v, u, v);
        }
    }
    void dfs3(int u, int f){
        for(int i = head[u]; ~i; i = e[i].nxt){
            int v = e[i].v, w = e[i].w;
            if(v == f) continue;
            idy[idx[v]] = e[i].id;
            segt.update(1, 1, totw, idx[v], w, e[i].id);
            dfs3(v, u);
        }
    }
    void build(){
        dfs1(1, 0, 0);
        dfs2(1, 0, 1);
        dfs3(1, 0);
    }
    pii query(int u, int v){
        int f1 = top[u], f2 = top[v];
        pii res = mp(-1, -1);
        while(f1 != f2){
            if(dep[f1] < dep[f2]){
                swap(u, v);
                swap(f1, f2);
            }
            Max(res, segt.query(1, 1, totw, idx[f1], idx[u] + 1));
            u = fa[f1];
            f1 = top[u];
        }
        if(u == v) return res;
        if(dep[u] > dep[v]) swap(u, v);
        Max(res, segt.query(1, 1, totw, idx[son[u]], idx[v] + 1));
        return res;
    }
}tree;
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
        e[i].id = i;
        e[i].w = w[i];
        e[i].c = c[i];
    }
    sort(e, e + m);
    REP(i, 1, n + 1) p[i] = i;
    ll sum = 0;
    tree.init();
    REP(i, 0, m){
        int u = find(e[i].u);
        int v = find(e[i].v);
        if(u == v) continue;
        vis[i] = 1;
        sum += e[i].w;
        p[u] = v;
        tree.addEdge(e[i].u, e[i].v, e[i].w, i);
    }
    tree.build();
    ll res = sum;
    pii ans[2];
    int S;
    scanf("%d", &S);
    REP(i, 0, m){
        if(vis[i]){
            if(sum - S / e[i].c <= res){
                ans[0].fi = i;
                ans[1] = mp(e[i].id, e[i].w - S / e[i].c);
                res = sum - S / e[i].c;
            }
        }
        else{
            int t = e[i].w - S / e[i].c;
            pii q = tree.query(e[i].u, e[i].v);
            if(sum - q.fi + t < res){
                ans[0].fi = q.se;
                ans[1] = mp(e[i].id, t);
                res = sum - q.fi + t;
            }
        }
    }
    printf("%lld\n", res);
    REP(i, 0, m) if(vis[i] && ans[0].fi != i)
        printf("%d %d\n", e[i].id + 1, e[i].w);
    printf("%d %d\n", ans[1].fi + 1, ans[1].se);
    return 0;
}

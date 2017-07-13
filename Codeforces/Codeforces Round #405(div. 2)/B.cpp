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
const int N = 150000 + 7;

int n, m;
map<int, set<int> > id;
vector<int> G[N];
int vis[N];
int de[N];

int d, e;
void dfs(int u){
    vis[u] = 1;
    d ++;
    e += de[u];
    for(auto v : G[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}
bool solve(){
    REP(i, 0, n){
        if(vis[i]) continue;
        if(!vis[i]){
            d = e = 0;
            dfs(i);
        }
        e /= 2;
        if(e != 1ll * d * (d - 1) / 2) return false;
    }
    return true;
}
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &m);
    REP(i, 0, m){
        int u, v;
        scanf("%d%d", &u, &v);
        u --, v --;
        G[u].pb(v);
        G[v].pb(u);
        id[u].insert(v);
        id[v].insert(u);
        de[u] ++, de[v] ++;
    }
    if(solve()) puts("YES");
    else puts("NO");
    return 0;
}

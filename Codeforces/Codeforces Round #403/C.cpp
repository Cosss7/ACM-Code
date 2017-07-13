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
int ind[N];
int dp[N];
int res;
void dfs(int u, int f, int x){
    int i = 0;
    for(auto v : G[u]){
        if(v == f) continue;
        i ++;
        while(i == x || i == dp[u]){
            i ++;
        }
        dp[v] = i;
        //printf("v = %d, i = %d\n", v, i);
        dfs(v, u, dp[u]);
    }
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
        ind[u] ++;
        ind[v] ++;
    }
    int cur = 0;
    int rt = 0;
    REP(i, 1, n + 1){
        if(ind[i] > cur){
            cur = ind[i];
            rt = i;
        }
    }
    dp[rt] = 1;
    res = ind[rt] + 1;
    dfs(rt, 0, 0);
    printf("%d\n", res);
    REP(i, 1, n + 1) printf("%d ", dp[i]);
    puts("");
    return 0;
}

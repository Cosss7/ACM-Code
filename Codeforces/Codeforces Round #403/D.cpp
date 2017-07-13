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

const int N = 2000 + 7;
int n;

vector<int> e[N];
int low[N], dfn[N], idx, belong[N], scc;
stack<int> stk;
bool instack[N];
inline void addedge(int u, int v) { e[u].push_back(v); }
void Tarjan(int u) {
    int v; low[u] = dfn[u] = ++idx; stk.push(u); instack[u] = true;
    for (int i = 0; i < (int)e[u].size(); i++) {
        int v = e[u][i];
        if (!dfn[v]) { Tarjan(v); low[u] = min(low[u], low[v]); }
        else if (instack[v] && low[u] > dfn[v]) { low[u] = dfn[v]; }
    }
    if (low[u] == dfn[u]) {
        scc++;
        do {
            v = stk.top(); stk.pop();
            instack[v] = false; belong[v] = scc;
        } while (v != u);
    }
}
void SCC(int n) {
    memset(dfn, 0, sizeof(dfn)); memset(instack, 0, sizeof(instack)); idx = scc = 0;
    while (!stk.empty()) { stk.pop(); }
    for (int i = 0; i < n; i++) { if (!dfn[i]) { Tarjan(i); } }
}
bool solvable(int n) {
    SCC(n << 1);
    for (int i = 0; i < n << 1; i += 2) {
        if (belong[i] == belong[i ^ 1]) { return false; }
    }
    return true;
}
vector<int> dag[N]; //缩点后的逆向DAG图
char color[N]; //染色, 为'R'是选择的
int cf[N], in[N];
void solve(int n) {
    for (int i = 1; i <= scc; i++) { dag[i].clear(); }
    memset(in, 0, sizeof(in)); memset(color, 0, sizeof(color));
    for (int u = 0; u < n << 1; u++) {
        for (int i = 0; i < (int)e[u].size(); i++) {
            int v = e[u][i];
            if (belong[u] != belong[v]) { dag[belong[v]].push_back(belong[u]); in[belong[u]]++; }
        }
    }
    for (int i = 0; i < n << 1; i += 2) {
        cf[belong[i]] = belong[i ^ 1]; cf[belong[i ^ 1]] = belong[i];
    }
    queue<int> que;
    for (int i = 1; i <= scc; i++) { if (in[i] == 0) { que.push(i); } }
    while (!que.empty()) {
        int u = que.front(); que.pop();
        if (color[u] == 0) { color[u] = 'R'; color[cf[u]] = 'B'; }
        for (int i = 0; i < (int)dag[u].size(); i++) {
            if (--in[dag[u][i]] == 0) { que.push(dag[u][i]); }
        }
    }
}
char s[N][N], t[N][N];
int main(){
#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif
    //freopen("out.txt","w",stdout);
    scanf("%d", &n);
    REP(i, 0, n){
        scanf("%s%s", s[i], t[i]);
    }
    REP(i, 0, n){
        REP(j, i + 1, n){
            if(s[i][0] == s[j][0] && s[i][1] == s[j][1] && s[i][2] == s[j][2]){
                addedge(i << 1, i << 1 | 1);
                //addedge(i << 1 | 1, i << 1);
                addedge(j << 1, j << 1 | 1);
                //addedge(j << 1 | 1, j << 1);
            }
            if(s[i][0] == s[j][0] && s[i][1] == s[j][1] && s[i][2] == t[j][0]){
                addedge(i << 1, j << 1);
                addedge(j << 1 | 1, i << 1 | 1);
            }
            if(s[i][0] == s[j][0] && s[i][1] == s[j][1] && t[i][0] == s[j][2]){
                addedge(i << 1 | 1, j << 1 | 1);
                addedge(j << 1, i << 1);
            }
            if(s[i][0] == s[j][0] && s[i][1] == s[j][1] && t[i][0] == t[j][0]){
                addedge(i << 1 | 1, j << 1);
                addedge(j << 1 | 1, i << 1);
            }
        }
    }
    if(solvable(n)){
        puts("YES");
        solve(n);
        REP(i, 0, n){
            if(color[belong[i << 1]] == 'R'){
                putchar(s[i][0]);
                putchar(s[i][1]);
                putchar(s[i][2]);
            }
            else{
                putchar(s[i][0]);
                putchar(s[i][1]);
                putchar(t[i][0]);
            }
            puts("");
        }
    }
    else{
        puts("NO");
    }
    return 0;
}

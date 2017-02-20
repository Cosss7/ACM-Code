#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 7;

int n;
int c[N];
int dp[N];
vector<int> G[N];
int ok, res;

void dfs(int u, int f){
    dp[u] = 0;
    for(auto v : G[u]){
        if(v == f) continue;
        dfs(v, u);
        if(c[u] != c[v] || dp[v] != 0) dp[u] ++;
    }
    //printf("u = %d, dp[u] = %d\n", u + 1, dp[u]);
}
void dfs1(int u, int f){
    int flag = 1;
    for(auto v : G[u]){
        //if(v == f) continue;
        if(dp[v] != 0) flag = 0;
        //if(u == 3) printf("v = %d, dp[v] = %d\n", v + 1, dp[v]);
    }
    if(flag) ok = 1, res = u + 1;
    if(ok) return ;
    for(auto v : G[u]){
        if(v == f) continue;
        if(c[u] != c[v] || dp[v] != 0){
            dp[u] --;
        }
        if(c[u] != c[v] || dp[u] != 0){
            dp[v] ++;
        }
        dfs1(v, u);
        if(c[u] != c[v] || dp[u] != 0){
            dp[v] --;
        }
        if(c[u] != c[v] || dp[v] != 0){
            dp[u] ++;
        }
    }
}
int main(){
#ifdef LOCAL_TEST
    freopen("in.txt", "r", stdin);
#endif


    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i ++) G[i].clear();
        ok = 0;
        for(int i = 1; i < n; i ++){
            int u, v;
            scanf("%d%d", &u, &v);
            u --, v --;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 0; i < n; i ++) scanf("%d", &c[i]);
        dfs(0, -1);
        dfs1(0, -1);
        if(ok){
            puts("YES");
            printf("%d\n", res);
        }
        else puts("NO");
    }

    return 0;
}
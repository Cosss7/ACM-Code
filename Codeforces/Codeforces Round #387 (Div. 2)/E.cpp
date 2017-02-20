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
const int N = 1e6 + 7;
map<int, string> id;
string tmp;
char str[N];
int cnt;
vector<int> G[N];
int getChar(){
    //while(getchar() == '\n') getchar();
    //if(getchar() == EOF) return 0;
    char ch = getchar();
    if(ch == EOF) return 0;
    int p = 0;
    str[p ++] = ch;
    while(1){
        ch = getchar();
        if(ch == ',') break;
        str[p ++] = ch;
    }
    str[p] = '\0';
    return 1;
}
void dfs(int u, int num){
    if(u == 0){
        while(getChar() != 0){
            int t;
            scanf("%d", &t);
            getchar();
            //printf("%s, %d\n", str, t);
            cnt ++;
            tmp = str;
            id[cnt] = tmp;
            G[u].pb(cnt);
            //cout << tmp << endl;
            dfs(cnt, t);
        }
    }
    else{
        while(num --){
            getChar();
            int t;
            scanf("%d", &t);
            getchar();
            cnt ++;
            tmp = str;
            id[cnt] = tmp;
            G[u].pb(cnt);
            dfs(cnt, t);
        }
    }
}
void BFS(){
    queue<pii> que;
    que.push(mp(0, 0));
    int res = 0;
    while(!que.empty()){
        pii t = que.front(); que.pop();
        int u = t.fi;
        Max(res, t.se);
        for(auto v : G[u]){
            que.push(mp(v, t.se + 1));
        }
    }
    que.push(mp(0, 0));
    printf("%d\n", res);
    int pre = 1;
    while(!que.empty()){
        pii t = que.front(); que.pop();
        int u = t.fi;
        if(u){
            if(t.se > pre) puts("");
            pre = t.se;
            printf("%s ", id[u].c_str());
        }
        for(auto v : G[u]){
            que.push(mp(v, t.se + 1));
        }
    }
    puts("");
}
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    //cin.sync_with_stdio(false);
    dfs(0, N);
    BFS();
    return 0;
}

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
const int N = 5e5 + 7;
int n, x, y;
pii p[N];
char ch[N][11];
map<int, set<int> > sum, dif;
map<int, set<int> > hor, ver;
bool solve(){
    REP(i, 0, n){
        if(ch[i][0] == 'B'){
            if(p[i].fi + p[i].se == x + y){
                int tx = min(p[i].fi, x);
                auto t = sum[x + y].upper_bound(tx);
                if(t == sum[x + y].end() || *t >= max(p[i].fi, x)) return true;
            }
            if(p[i].fi - p[i].se == x - y){
                int tx = min(p[i].fi, x);
                auto t = dif[x - y].upper_bound(tx);
                if(t == dif[x - y].end() || *t >= max(p[i].fi, x)) return true;
            }
        }
        else if(ch[i][0] == 'R'){
            if(p[i].se == y){
                int tx = min(p[i].fi, x);
                auto t = hor[y].upper_bound(tx);
                if(t == hor[y].end() || *t >= max(p[i].fi, x)) return true;
            }
            if(p[i].fi == x){
                int tx = min(p[i].se, y);
                auto t = ver[x].upper_bound(tx);
                if(t == ver[x].end() || *t >= max(p[i].se, y)) return true;
            }
        }
        else{
            if(p[i].fi + p[i].se == x + y){
                int tx = min(p[i].fi, x);
                auto t = sum[x + y].upper_bound(tx);
                if(t == sum[x + y].end() || *t >= max(p[i].fi, x)) return true;
            }
            if(p[i].fi - p[i].se == x - y){
                int tx = min(p[i].fi, x);
                auto t = dif[x - y].upper_bound(tx);
                if(t == dif[x - y].end() || *t >= max(p[i].fi, x)) return true;
            }
            if(p[i].se == y){
                int tx = min(p[i].fi, x);
                auto t = hor[y].upper_bound(tx);
                if(t == hor[y].end() || *t >= max(p[i].fi, x)) return true;
            }
            if(p[i].fi == x){
                int tx = min(p[i].se, y);
                auto t = ver[x].upper_bound(tx);
                if(t == ver[x].end() || *t >= max(p[i].se, y)) return true;
            }
        }
    }
    return false;
}
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d", &n);
    scanf("%d%d", &x, &y);
    REP(i, 0, n){
        scanf("%s%d%d", ch[i], &p[i].fi, &p[i].se);
        sum[p[i].fi + p[i].se].insert(p[i].fi);
        dif[p[i].fi - p[i].se].insert(p[i].fi);
        hor[p[i].se].insert(p[i].fi);
        ver[p[i].fi].insert(p[i].se);
    }
    if(solve()) puts("YES");
    else puts("NO");
    return 0;
}

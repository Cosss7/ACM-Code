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
const int N = 1e5 + 7;

int n;
map<pii, pii> hs;
int main(){
#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif
    //freopen("out.txt","w",stdout);
    scanf("%d", &n);
    int res = 0;
    int k = 0;
    pii ans;
    REP(i, 0, n){
        int a[3];
        REP(j, 0, 3) scanf("%d", &a[j]);
        sort(a, a + 3);
        if(a[0] > res){
            k = 1;
            ans.fi = i;
            res = a[0];
        }
        if(hs.count(mp(a[2], a[1]))){
            if(min(min(hs[mp(a[2], a[1])].fi + a[0], a[1]), a[2]) > res){
                k = 2;
                ans = mp(hs[mp(a[2], a[1])].se, i);
                res = min(min(hs[mp(a[2], a[1])].fi + a[0], a[1]), a[2]);
            }
        }
        Max(hs[mp(a[2], a[1])], mp(a[0], i));
        Max(hs[mp(a[2], a[0])], mp(a[1], i));
        Max(hs[mp(a[1], a[0])], mp(a[2], i));
    }
    printf("%d\n", k);
    if(k == 1) printf("%d\n", ans.fi + 1);
    else printf("%d %d\n", ans.fi + 1, ans.se + 1);
    return 0;
}


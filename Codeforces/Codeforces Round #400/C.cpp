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

int n, k;
int a[N];
set<pll> st;
vector<ll> pw;
pll b[N];
int vis[N];
int main(){
#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif
    //freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &k);
    REP(i, 1, n + 1) scanf("%d", &a[i]);
    ll sum = 0;
    REP(i, 1, n + 1){
        sum += a[i];
        b[i] = pll(sum, i);
        st.insert(pll(sum, i));
    }
    if(k == 1) pw.pb(1);
    else if(k == -1){
        pw.pb(1);
        pw.pb(-1);
    }
    else{
        ll kk = k;
        pw.pb(1);
        while(kk < 1e16){
            pw.pb(kk);
            kk *= k;
        }
    }
    sort(b + 1, b + n + 1);
    sort(ALL(pw));
    unique(ALL(pw));
    sum = 0;
    ll res = 0;
    REP(i, 1, n + 1){
        sum += a[i - 1];
        for(auto x : pw){
            auto p = lower_bound(b + 1, b + n + 1, pll(x + sum, i));
            auto q = upper_bound(b + 1, b + n + 1, pll(x + sum, n + 2));
            res += q - p;
        }
    }
    printf("%lld\n", res);
    return 0;
}

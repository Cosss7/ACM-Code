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
const int BLK = 355;

int n, k;
ll t[N], l[N], r[N];
ll a[N << 1], cl[N << 1], cr[N << 1], res[N];

struct Query{
    int l, r, id;
    bool operator < (const Query &t) const{
        return (l / BLK == t.l / BLK ? r < t.r : l / BLK < t.l / BLK);
    }
}qu[N];

int main(){
#ifdef LOCAL_TEST
	freopen("/Users/cosss/in.txt","r",stdin);
#endif
	//freopen("/Users/cosss/out.txt","w",stdout);

    scanf("%d%d", &n, &k);
    REP(i, 1, n + 1)
        scanf("%lld", &t[i]);

    REP(i, 1, n + 1){
        scanf("%lld", &a[i]);
        if(t[i] == 2) a[i] = -a[i];
        a[i] += a[i - 1];
    }

    REP(i, 0, n + 1)
        l[i] = a[i + n + 1] = a[i] + k, r[i] = a[i];
    sort(a, a + 2 * n + 2);
    REP(i, 0, n + 1){
        l[i] = lower_bound(a, a + n * 2 + 2, l[i]) - a;
        r[i] = lower_bound(a, a + n * 2 + 2, r[i]) - a;
    }

    int q;
    scanf("%d", &q);
    REP(i, 0, q){
        scanf("%d%d", &qu[i].l, &qu[i].r);
        qu[i].id = i;
    }
    sort(qu, qu + q);

    int ql = 1, qr = 0;
    ll tot = 0;
    REP(i, 0, q){
        while(qr < qu[i].r){
            qr ++;
            cl[l[qr - 1]] ++;
            cr[r[qr]] ++;
            tot += cl[r[qr]];
        }
        while(ql > qu[i].l){
            ql --;
            cl[l[ql - 1]] ++;
            cr[r[ql]] ++;
            tot += cr[l[ql - 1]];
        }
        while(qr > qu[i].r){
            tot -= cl[r[qr]];
            cl[l[qr - 1]] --;
            cr[r[qr]] --;
            qr --;
        }
        while(ql < qu[i].l){
            tot -= cr[l[ql - 1]];
            cl[l[ql - 1]] --;
            cr[r[ql]] --;
            ql ++;
        }

        res[qu[i].id] = tot;
    }

    REP(i, 0, q)
        printf("%lld\n", res[i]);

    return 0;
}

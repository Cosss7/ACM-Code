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
int n;
char s[N];
int a[N];
ll suf[N], pre[N], suf2[N], pre2[N];
//ll pre2[N], suf2[N];
map<int, ll> hsp, hss;
int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d%s", &n, s);
    REP(i, 0, n) a[i + 1] = (s[i] == 'U');
    REP(i, 1, n + 1) pre[i] = pre[i - 1] + a[i];
    FOR(i, 1, n + 1) suf2[i] = suf2[i + 1] + a[i];
    FOR(i, 1, n + 1) suf[i] = suf[i + 1] + (!a[i]);
    REP(i, 1, n + 1) pre2[i] = pre2[i - 1] + (!a[i]);
    int num = 0;
    FOR(i, 1, n + 1){
        //suf2[i] = suf2[i + 1];
        if(a[i]){
            num ++;
            hss[num] = hss[num - 1] + (n - i) * 2;
            //suf2[i] += n - i + 1;
        }
    }
    num = 0;
    REP(i, 1, n + 1){
        //pre2[i] = pre2[i - 1];
        if(!a[i]){
            num ++;
            hsp[num] = hsp[num - 1] + (i - 1) * 2;
            //pre2[i] += i;
        }
    }
    REP(i, 1, n + 1){
        ll res = 0;
        if(a[i]){
            if(suf[i + 1] > pre[i - 1]){
                res += hss[suf2[i] + pre[i - 1]] - hss[suf2[i]] - 2 * pre[i - 1] * (n - i);
                res += hsp[pre2[i] + pre[i - 1] + 1] - hsp[pre2[i]] - 2 * (pre[i - 1] + 1) * (i - 1);
                res += i;
            }
            else if(suf[i + 1] == pre[i - 1]){
                res += hss[suf2[i] + pre[i - 1]] - hss[suf2[i]] - 2 * pre[i - 1] * (n - i);
                res += hsp[pre2[i] + pre[i - 1]] - hsp[pre2[i]] - 2 * pre[i - 1] * (i - 1);
                res += n - i + 1;
            }
            else{
                res += hsp[pre2[i] + suf[i + 1]] - hsp[pre2[i]] - 2 * suf[i + 1] * (i - 1);
                res += hss[suf2[i] + suf[i + 1]] - hss[suf2[i]] - 2 * suf[i + 1] * (n - i);
                res += n - i + 1;
            }
        }
        else{
            if(suf[i + 1] < pre[i - 1]){
                res += hsp[pre2[i] + suf[i + 1]] - hsp[pre2[i]] - 2 * suf[i + 1] * (i - 1);
                res += hss[suf2[i] + suf[i + 1] + 1] - hss[suf2[i]] - 2 * (suf[i + 1] + 1) * (n - i);
                res += (n - i + 1);
            }
            else if(suf[i + 1] == pre[i - 1]){
                res += hss[suf2[i] + pre[i - 1]] - hss[suf2[i]] - 2 * pre[i - 1] * (n - i);
                res += hsp[pre2[i] + pre[i - 1]] - hsp[pre2[i]] - 2 * pre[i - 1] * (i - 1);
                res += i;
            }
            else{
                res += hss[suf2[i] + pre[i - 1]] - hss[suf2[i]] - 2 * pre[i - 1] * (n - i);
                res += hsp[pre2[i] + pre[i - 1]] - hsp[pre2[i]] - 2 * pre[i - 1] * (i - 1);
                res += i;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}

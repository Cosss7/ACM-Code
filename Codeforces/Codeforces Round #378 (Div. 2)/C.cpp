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
const int N = 555;
int n, a[N];
int k, b[N];
vector<pair<int, char> > ans;
bool solve(){
    int sum = 0;
    int last = 0;
    for(int i = 0, j = 0; i < n; i ++){
        if(j == k) return false;
        sum += a[i];
        if(sum > b[j]) return false;
        if(sum == b[j]){
            int mx = 0, mxp = -1, mxd = 0;
            if(i - last == 0){
            }
            else{
                for(int k = last; k <= i; k ++){
                    if(k > last && a[k] > mx && a[k] > a[k - 1]){
                        mx = a[k], mxp = k, mxd = 0;
                    }
                    if(k < i && a[k] > mx && a[k] > a[k + 1]){
                        mx = a[k], mxp = k, mxd = 1;
                    }
                }
                if(mxp == -1) return false;
                if(mxd){
                    for(int k = mxp; k < i; k ++)
                        ans.pb(mp(mxp - last + j, 'R'));
                    for(int k = mxp; k > last; k --)
                        ans.pb(mp(k - last + j, 'L'));
                }
                else{
                    for(int k = mxp; k > last; k --)
                        ans.pb(mp(k - last + j, 'L'));
                    for(int k = mxp; k < i; k ++)
                        ans.pb(mp(j, 'R'));
                }
            }
            last = i + 1;
            sum = 0;
            j ++;
        }
        if(i == n - 1 && j != k) return false;
    }
    return true;
}
int main(){
#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif
    //freopen("out.txt","w",stdout);
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", &a[i]);
    scanf("%d", &k);
    REP(i, 0, k) scanf("%d", &b[i]);
    if(solve()){
        puts("YES");
        for(auto it : ans)
            printf("%d %c\n", it.fi + 1, it.se);
    }
    else puts("NO");
    return 0;
}


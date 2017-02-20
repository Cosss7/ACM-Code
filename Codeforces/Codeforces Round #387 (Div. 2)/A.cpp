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

int main(){
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    int N = sqrt(n) + 1;
    int a, b;
    int dif = 11111111;
    REP(i, 1, min(N + 2, n + 1)){
        if(n % i == 0){
            if(abs(i - n / i) < dif){
                dif = abs(i - n / i);
                a = min(i, n / i);
                b = max(i, n / i );
            }
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}

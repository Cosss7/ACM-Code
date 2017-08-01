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
const int N  = 1e6 + 7;

int n;
int a[N];
bool solve(){
    ///*
    REP(i, 0, n - 1){
        if(a[i] > a[i + 1]){
            REP(j, i + 1, n - 1){
                if(a[j] <= a[j + 1]){
                    return false;
                }
            }
            break;
        }
        else if(a[i] == a[i + 1]){
            REP(j, i + 1, n - 1){
                if(a[j] < a[j + 1]){
                    return false;
                }
                else if(a[j] > a[j + 1]){
                    REP(k, j + 1, n - 1){
                        if(a[k] <= a[k + 1]){
                            return false;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    return true;
    //*/
/*
    REP(i, 0, n){
        REP(j, 0, n){
            REP(k, j, j + i - 1){
                if(a[k] != a[k + 1]){
                    break;
                }
            }
        }
    }
    */
}
int main(){
#ifdef LOCAL_TEST
	freopen("/Users/cosss/in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    scanf("%d", &n);
    REP(i, 0, n){
        scanf("%d", &a[i]);
    }
    if(solve()) puts("yes");
    else puts("no");
    return 0;
}

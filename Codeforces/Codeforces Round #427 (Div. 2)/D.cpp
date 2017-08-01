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

#define SZ(x) ((int)(x).size())
#define ALL(v) (v).begin(), (v).end()
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define reveach(i, v) for (__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++ i)
#define REP(i,a,n) for ( int i=a; i<int(n); i++ )
#define FOR(i,a,n) for ( int i=n-1; i>= int(a);i-- )
#define lson rt<<1, L, m
#define rson rt<<1|1, m, R
typedef pair<int, int> pii;
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fi first
#define se second
#define CLR(a, b) memset(a, b, sizeof(a))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define lowbit(x) (x) & (-(x))

const int N = 5e3 + 7;

char s[N];
int n;
int m;
int p[N << 1];
short f[N << 1][N];
short g[N << 1][N];
int res[N];

int main(){
#ifdef LOCAL_TEST
	freopen("/Users/cosss/in.txt","r",stdin);
#endif
	//freopen("/Users/cosss/out.txt","w",stdout);
    scanf("%s", s);
    n = strlen(s);
    string t("#");
    //CLR(f, -1);
    for(int i = 0; i < n; i ++){
        t += s[i];
        t += '#';
    }

    m = t.length();

    for(int i = 0; i < m; i ++){
        int l, r;
        l = r = i;
        while(l >= 0 && r < m && t[l --] == t[r ++]){
            p[i] ++;
        }
    }
    for(int i = 0; i < m; i ++){
        int j;
        if(i & 1) j = 2, f[i][1] = 0;
        else j = 1;
        for(; j < p[i]; j ++){
            f[i][j] = 0;
            int l = i - j, r = i + j;
            if(l + p[l] >= i && r - p[r] <= i){
                //Max(f[i], f[l] + 1);
                int x;
                if(i & 1) x = (l + i) / 2 - l;
                else x = (l + i + 1) / 2 - l;
                f[i][j] = f[l][x] + 1;
                //if(i == 4) printf("p[%d] = %d, p[%d] = %d, f = %d\n", l, p[l], r, p[r], f[i]);
                g[i][f[i][j]] ++;
                g[i][0] --;
            }
        }
        //f[i][p[i]] = f[i][p[i] - 1];
        //if(i & 1) f[i][1] = f[i][2];
        if(p[i] > 1){
            g[i][0] += p[i] / 2;
        }
    }
    //for(int j = 0; j < n; j ++)cout << f[3][j] << endl;
    for(int i = 0; i < m; i ++){
        //printf("f[%d] = %d\n", i, f[i]);
        for(int j = 0; j < n; j ++){
            res[j] += g[i][j];
        }
    }
    for(int i = n - 2; i >= 0; i --){
        res[i] += res[i + 1];
    }
    for(int i = 0; i < n; i ++){
        if(i)
            printf(" ");
        printf("%d", res[i]);
    }
    puts("");
    return 0;
}

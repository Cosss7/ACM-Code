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

const int N = 1e7 + 7;

int n;
string s[N];

struct Node{
    int l, r, x;
    Node(){}
    Node(int  l, int r, int x): l(l), r(r), x(x){}

    bool operator < (const Node& t) const{
        return l < t.l;
    }
};
vector<Node> a;

int main(){
    ios::sync_with_stdio(false);
#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
#endif
	//freopen("out.txt","w",stdout);
    cin >> n;
    REP(i, 0, n){
        cin >> s[i];
        int len = s[i].length();
        int m;
        cin >> m;
        REP(j, 0, m){
            int x;
            cin >> x;
            x --;
            a.push_back(Node(x, x + len, i));
        }
    }
    sort(ALL(a));
    int r = 0;
    for(auto x : a){
        //printf("%d, %d, %d\n", x.l, x.r, x.x);
        if(x.r > r){
            if(x.l < r){
                REP(i, r - x.l, s[x.x].length()){
                    cout << s[x.x][i];
                }
            }
            else{
                REP(i, 0, x.l - r){
                    cout << 'a';
                }
                REP(i, 0, s[x.x].length()){
                    cout << s[x.x][i];
                }
            }
            r = x.r;
        }
    }
    cout << endl;
    return 0;
}

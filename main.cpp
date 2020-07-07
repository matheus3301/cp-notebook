#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cerr << #x << " = " << x << "\n";
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int n, k;

const int mxN = 1e5;
const int R = 1;

int t[4*mxN + 1];

int query(int i, int l, int r, int ql,int qr){
    if(ql <= l && r <= qr) return t[i];
    if(qr < l || r < ql) return 1;

    int m = (l+r)/2;

    return query(2*i,l,m,ql,qr) * query(2*i + 1, m+1, r, ql, qr);

}

void update(int i, int l, int r, int p, int x){
    if(l == r){
        if(x > 0) t[i] = 1;
        else if(x < 0) t[i] = -1;
        else t[i] = 0;
    }else{
        int m = (l+r)/2;

        if(p <= m) update(2*i,l,m,p,x);
        else update(2*i + 1, m+1,r,p,x);
        
        t[i] = t[2*i] * t[2*i + 1];
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int tmp;
    char c;
    int a, b;

    while(cin >> n >> k){
        for(int i = 1; i <= n; i++){
            cin >> tmp;
            update(R,1,n,i,tmp);
        }

        string ans;
        
        while(k--){
            cin >> c >> a >> b;
            if(c == 'C'){
                update(R,1,n,a,b);
            }else if(c == 'P'){
                tmp = query(R,1,n,a,b);

                if(tmp == 0){
                    ans.push_back('0');
                }else if(tmp < 0){
                    ans.push_back('-');
                }else{
                    ans.push_back('+');
                }
            }
        }

        cout << ans << endl;
    }
    

    return 0;
}
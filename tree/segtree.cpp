// SEGTREE DE SOMA ACUMULADA, EXPLICAÇÃO NO MARATONUSP
#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;
const int R = 1;
const int VN = 0;

int t[4*mxN];

int n,q;


int query(int i, int l, int r, int ql,int qr){
    if(ql <= l && r <= qr) return t[i];
    if(qr < l || r < ql) return VN;

    int m = (l+r)/2;

    // O QUE PROVAVELMENTE VAI MUDAR
    return query(2*i,l,m,ql,qr) + query(2*i + 1, m+1, r, ql, qr);

}

void update(int i, int l, int r, int p, int x){
    if(l == r){
        t[i] = x;
    }else{
        int m = (l+r)/2;

        if(p <= m) update(2*i,l,m,p,x);
        else update(2*i + 1, m+1,r,p,x);
        
        //O QUE PROVAVELMENTE VAI MUDAR
        t[i] = t[2*i] + t[2*i+1];
    }
}



int main(){
    cin >> n >> q;

    int tmp;

    for(int i = 1; i <= n; i++){
        cin >> tmp;
        update(1,1,n,i,tmp);
    }

    
    int a, b;
    while(q--){
        cin >> a >> b;

        cout << query(1,1,n,a,b) << endl;

    }

    return 0;
}
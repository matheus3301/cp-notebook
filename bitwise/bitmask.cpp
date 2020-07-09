#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cerr << #x << " = " << x << "\n";

using namespace std;

typedef long long ll;

int n,tmp;

ll mask;

void insert(int a){
    a = 1 << a;
    mask = mask | a;
}

void remove(int a){
    a = 1 << a;
    a = ~a;

    mask = mask & a;
}

bool check(int a){
    ll b = mask >> a;
    return b & 1;
}

void invert(int a){
    ll b = 1 << a;
    mask = mask ^ b;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;

        insert(tmp);
    }    

    return 0;
}
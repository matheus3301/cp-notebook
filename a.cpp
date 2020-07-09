#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cerr << #x << " = " << x << "\n"
#define PB push_back

using namespace std;

int n, x;
bool v[100010];

void remove(int i){
    if(i != n){

    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> x;

    int f = x + 1;

    while(n > 1){
        remove(f);
        
        n--;
    }

    cout << v[1] << endl;
    return 0;
}
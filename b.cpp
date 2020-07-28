#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const ll mxN = 1e16+1;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a = 1, b = 5, c = 50;
    ll tmp;
    cout << "is[" << a << "] = true;" << endl;
    cout << "is[" << b << "] = true;" << endl;
    cout << "is[" << c << "] = true;" << endl;

    for(int i = 1; i <= 1500000; i++){
        tmp = c + b - a;
        a = b;
        b = c;
        c = tmp;
    
        cout << "is[" << tmp << "] = true;" << endl;

        
    }
    
    

}
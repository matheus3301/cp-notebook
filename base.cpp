#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef long long ll;

int n;
vector<int> v;
vector<pair<int,int>> p;
//se eu dividir, o minimo sempre é 2, eu acho .0. 
int ans = 2; 

int main(){
    cin >> n;
    v.push_back(0);

    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;

        if(tmp != v.back()){
            v.push_back(tmp);
        }
    }

    for(int i = 1; i < v.size()-1; i++){
       if(v[i] > v[i-1] && v[i] > v[i+1]){
           p.push_back({v[i], 1});
       }

       if(v[i] < v[i-1] && v[i] < v[i+1]){
           p.push_back({v[i], -1});
       }
    }

    v.push_back(0);



    return 0;
}
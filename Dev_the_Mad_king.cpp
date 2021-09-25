#include<bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define ll long long
ll mod=1e9+7;
int32_t main(){
    //     #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);//fast input output
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        cout<<max(1ll,(a*b)-(a+b)+1)<<"\n"; //chicken mcnugget theorem.
    }
}

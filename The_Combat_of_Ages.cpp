#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

ll query(ll idx, ll BIT[]) {
    ll result = 0;
    while(idx) {
        result = max(BIT[idx], result);
        idx -= (idx & -idx);
    }
    return result;
}

void add(ll idx, ll BIT[], ll value, ll n) {
    while(idx <= n) {
        BIT[idx] = max(BIT[idx], value);
        idx += (idx & -idx);
    }
}
void solve(ll t) {
    ll n;
    cin>>n;
    vector<ll> strength(n), age(n);
    for(ll i = 0; i < n; i++)
        cin>>strength[i];
    for(ll i = 0; i < n; i++)
        cin>>age[i];
    ll BIT[n + 1];
    memset(BIT, 0, sizeof BIT);
    vector<pair<ll, ll>> pp(n);
    for(ll i = 0; i < n; i++) {
        pp[i] = {strength[i], age[i]};
    }
    sort(pp.begin(), pp.end(), [&](const pair<ll, ll> &a, const pair<ll, ll> b) {
        if(a.first == b.first) 
            return a.second < b.second;
        return a.first < b.first;
    });

    for(ll i = 0; i < n; i++) {
        ll idx = pp[i].second;
        ll value = query(idx - 1, BIT) + pp[i].first;
        add(idx, BIT, value , n);
    }
    cout<<query(n, BIT)<<endl;

}
int main() {

    fastIO;// fast input output
    ll t;
    t=1;
    cin>>t;
    for(ll i = 1; i <= t; i++) solve(i);
    return 0;
}

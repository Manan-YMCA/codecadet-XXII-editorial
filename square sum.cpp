#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int mod=1e9+7;
const int N=110;
int sq[1010];
int dp[110][1000][2];
int calc(string &s){
	int n=s.length();
	memset(dp,0,sizeof dp);

	dp[0][0][0]=1;

	for(int i=0;i<n;i++){
		for(int sum=0;sum<=900;sum++){
			for(int tight=0;tight<2;tight++){

				//if already smaller
				if(tight){
					for(int dig=0;dig<=9;dig++){
						int nsum=sum+dig;
						dp[i+1][nsum][1]=(dp[i+1][nsum][1]+dp[i][sum][tight])%mod;
					}
				}
				else{
					int lim=s[i]-'0';
					for(int dig=0;dig<=lim;dig++){
						int nsum=sum+dig;
						if(dig<lim){
							dp[i+1][nsum][1]=(dp[i+1][nsum][1]+dp[i][sum][tight])%mod;
						}
						else{
							dp[i+1][nsum][tight]=(dp[i+1][nsum][tight]+dp[i][sum][tight])%mod;
						}
					}
				}
			}
		}
	}

	int ans=0;
	for(int i=0;i<=909;i++){

		if(sq[i])
		ans=(ans+dp[n][i][0]+dp[n][i][1])%mod;
	}
	return ans;
}
int ok(string &s){
	int n=s.length();
	int res=0;
	for(auto i:s)res+=(i-'0');
	return sq[res];
}
void solve(){
	string l, r;
	cin>>l>>r;
	cout<<(calc(r)-calc(l)+ok(l)+mod)%mod<<"\n";
}
int32_t main(){

	for(int i=0;i*i<=1000;i++)sq[i*i]=1;

	int t;
	cin>>t;
	while(t--)solve();

}

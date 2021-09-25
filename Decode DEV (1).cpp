    #include<bits/stdc++.h>
    using namespace std;
    #define pi (3.141592653589)
    #define ll long long
    #define float double
    #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define  popcount(x) __builtin_popcount(x);
    #define  popcountll(x) __builtin_popcountll(x);
    #define rev greater<int>()
    #define all(v) v.begin(),v.end()
    ll a[5000007],b[5000007],primes[5000007],binaryNum[50];
    ll mod=1e9+7;
    vector<ll>primefactors;
    unordered_map<ll,ll> Fib; 
    long long power(long long x, ll y, ll p)
    {
         long long res = 1; 
        x = x % p; 
        while (y > 0) 
        {
            if (y & 1)
                res = (res * x) % p;
            y = y >> 1; 
            x = (x * x) % p;
        }
        return res;
    }
    long long modInverse(long long n,  ll p)
    {
        return power(n, p - 2, p);
    }
    long long nCrModPFermat(long long n, ll r, ll p)
    {
        if (n < r)
            return 0;
        if (r == 0)
            return 1;
        long long fac[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = (fac[i - 1] * i) % p;
     
        return (fac[n] * modInverse(fac[r], p) % p
                * modInverse(fac[n - r], p) % p)
               % p;
    }
    void SieveOfEratosthenes(ll n)
    {
        bool prime[n + 1];
        ll j=0;
        memset(prime, true, sizeof(prime));
     
        for (ll p = 2; p * p <= n; p++)
        {
            if (prime[p] == true) 
            {
                for (ll i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        for (ll p = 2; p <= n; p++)
            if (prime[p]) primes[j++]=p;
    }
    ll __lcm(ll arr[], ll n) 
    { 
        ll ans = arr[0]; 
        for (int i = 1; i < n; i++) 
            ans = (((arr[i] * ans)) / 
                    (__gcd(arr[i], ans))); 
        return ans; 
    } 
    ll fib(ll n)
    {
        if(n<2) return 1;
        if(Fib.find(n) != Fib.end()) return Fib[n];
        Fib[n] = (fib((n+1) / 2)*fib(n/2) + fib((n-1) / 2)*fib((n-2) / 2)) % mod;
        return Fib[n];
    }
    bool isPrime(int n)
    {
       
        if (n <= 1)
            return false;
     
       
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
     
        return true;
    }
    void primeFactors(ll n) 
    { 
        while (n % 2 == 0) 
        { 
            primefactors.pb(2);  
            n = n/2; 
        } 
        for (int i = 3; i <= sqrt(n); i = i + 2) 
        { 
            while (n % i == 0) 
            { 
                primefactors.pb(i); 
                n = n/i; 
            } 
        } 
        if (n > 2) 
            primefactors.pb(n); 
    }
    bool isPalindrome(string str)
    {
        int l = 0;
        int h = str.length() - 1;
      
        while (h > l)
        {
            if (str[l++] != str[h--])return false;
            
        }
        return true;
    } 
    void decToBinary(ll n)
    {
        ll binarynum[50];
        ll i = 0;
        while (n > 0) {
     
            
            binarynum[i] = n % 2;
            n = n / 2;
            i++;
        }
        ll k=0;
        for (int j = i - 1; j >= 0; j--)
             binaryNum[k++]=binarynum[j];
    }
    string stringMex(string S) {
        vector<string> strings = {""};
     
        while (true) {
            vector<string> nstrings;
     
            for (auto &str : strings)
                for (int c = 0; c < 26; c++) {
                    string nstr = str + char('a' + c);
                    nstrings.push_back(nstr);
     
                    if (S.find(nstr) == string::npos)
                        return nstr;
                }
     
            strings.swap(nstrings);
        }
    }
    int32_t main(){
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
        #endif
       
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll t=1;
        cin>>t;
        while(t--){
         ll i, j, k, l, ans = 0, count = 0, n, m, x, y,r;
         bool flag=0;
         string s,s1;
         map<ll,ll>mp1;
            ll maxa = -1000000000000000, mina = 1000000000000000;
            cin>>s;
            n=s.length();
            x=n;
           for(i=0;i<n;i++){
               if(s[i]=='D')count++;
               if(s[i]=='V'){
                   x=i;
                  break;
                }
           }
           for(i=0;i<n;i++)if(s[i]=='E')ans++;
           for(i=x;i<n;i++){
               if(s[i]!='E')s1.pb(s[i]);
           }
           for(i=0;i<count+ans;i++){
               if(i<count)cout<<'D';
               else cout<<'E';
           }
           
           cout<<s1<<" ";
           cout<<"\n";
          
            
        }
    }

 
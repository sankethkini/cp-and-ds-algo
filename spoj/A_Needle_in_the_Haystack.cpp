//to-do to-do

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(string pat,v32& table){
    int len=0;
    int i=0;
    while(i<pat.size())
    {
        if(pat[i]==pat[len])
        {
            table[i]=++len;
            i++;
        }
        else{
            if(len==0)
            {
                table[i]=0;
                i++;
            }
            else
            {
                len=table[len-1];
            }
        }
    }
}
int main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif 
    int t;
    string pat;
    
    while(cin>>t && cin>>pat)
    {
        string str;
        v32 table(t,0);
        solve(pat,table);
        ll st=0;
        char a;
        int len=0;
        while(cin>>a)
        {
            st++;
            if(a==pat[len])
            {
                ++len;
                if(len==pat.size()-1){
                    cout<<st-pat.size()<<endl;
                } 
            }
            else
            {
                while(len!=0 || a!=pat[len])
                {
                    len=table[len-1];
                }
            }
        }
        cout<<endl;
    }   
    
    return 0;
}
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h>  
// #include <complex>
// #include <queue>
// #include <set>
// #include <unordered_set>
// #include <list>
// #include <chrono>
// #include <random>
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <map>
// #include <unordered_map>
// #include <stack>
// #include <iomanip>
// #include <fstream>
 
// using namespace std;
 
// typedef long long ll;
// typedef long double ld;
// typedef pair<int,int> p32;
// typedef pair<ll,ll> p64;
// typedef pair<double,double> pdd;
// typedef vector<ll> v64;
// typedef vector<int> v32;
// typedef vector<vector<int> > vv32;
// typedef vector<vector<ll> > vv64;
// typedef vector<vector<p64> > vvp64;
// typedef vector<p64> vp64;
// typedef vector<p32> vp32;
// ll MOD = 998244353;
// double eps = 1e-12;
// #define forn(i,e) for(ll i = 0; i < e; i++)
// #define forsn(i,s,e) for(ll i = s; i < e; i++)
// #define rforn(i,s) for(ll i = s; i >= 0; i--)
// #define rforsn(i,s,e) for(ll i = s; i >= e; i--)
// #define ln "\n"
// #define dbg(x) cout<<#x<<" = "<<x<<ln
// #define mp make_pair
// #define pb push_back
// #define fi first
// #define se second
// #define INF 2e18
// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define all(x) (x).begin(), (x).end()
// #define sz(x) ((ll)(x).size())
 

// int solve(string str,int st,int end){
//     if(st>=end)
//         return 0;
//     if(str[st]==str[end])
//     {
//         return solve(str,st+1,end-1);
//     }
//     return 1+min(solve(str,st+1,end),solve(str,st,end-1));
// }
// int main()
// {
//     fast_cin();
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     // #endif 
//     ll t;
//     cin >> t;
//     while(t--){
//         string str;
//         cin>>str;
//         int n=str.size();
//         vector<vector<int>> dp(n,vector<int>(n,0));
//         for(int i=0;i<n;i++)
//         {
//             dp[i][i]=0;
//         }
//         for(int i=0;i<n-1;i++)
//         {
//             if(str[i]==str[i+1])
//                 dp[i][i+1]=0;
//             else
//                 dp[i][i+1]=1;
//         }
//         for(int k=3;k<=n;k++)
//         {
//             for(int i=0;i<n-k+1;i++)
//             {
//                 int j=k+i-1;
//                 if(str[i]==str[j])
//                 {
//                     dp[i][j]=1+dp[i-1][j-1];
//                 }
//                 else
//                 {
//                     dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         cout<<dp[0][n-1]<<endl;
//     }
//     return 0;
// }
#include<bits/stdc++.h>
#include<algorithm>
#define ll long long int 
using namespace std; 

ll max ( ll a , ll b  )
{
    return (a>b)? a:b ;  
}

var[1001][1001] ;
//Var varies with posn and the budget limit so storage consists of these two variables 
ll Goods ( int cur , int n ,ll lim )
{
    ll v = 0 ;
    if ( lim <= 0 || cur <= 0 ) return v  ;
    else    if ( var[cur][lim] ==-1 )
    {
        var[cur][lim] = max ( Goods(cur-1,n,lim) , 1+ Goods(cur-1,n,lim-a[cur]) , 2+ Goods(cur-2,n,lim-a[cur]) , 3 + Goods(cur-3,n,lim-a[cur]) ) ;
    }
    return var[cur][lim] ;  
}

ll Goods( ll cur, ll n , ll k , ll lim )
{
    ll v=0 ; 
    if ( lim<=0 || cur<=0)return v ;
    else    if ( var[cur][lim] == -1 )
    {
        for ( ll i=0 ; i<k ; i++ )
        {
            var[cur][lim] = var[cur-1][lim] ;
            var[cur][lim] = max ( i + 1 + Goods(cur-(i+1),n,lim-a[cur] ) , var[cur][lim]  ) ;
        }
    }
    return var[cur][lim] ;
}

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        ll n ;
        cin >> n ;
        ll a[n+1] ;
        a[0] = 0 ;
        ll x ;
        for ( ll i=1 ; i<=n ; i++ )
        {
            cin >> a[i] ;
        }
        sort(a,a+n) ;
        for ( int i=1 ; i<=n ; i++ )
        {
            for(int j=1 ; j<3 ; j++ )
            var[i][j] = -1 ;
        }
        cin >> x ;
      cout << Goods( n , n , x ) << "\n" ;
    }
    return 0 ;
}
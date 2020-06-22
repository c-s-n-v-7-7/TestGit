#include<bits/stdc++.h>
#include<algorithm>
#define ll long long int
#define max 10000000000 
using namespace std ;

ll LCM ( ll a , ll b )
{
    ll c = 1 , c1=0 , c2=0 , ca=a , cb = b ;
    for ( ll i=2 ; i*i <= ca ; i++ )
    {
        if ( a==1 )break ;
        if ( b==1 )break ; 
        while(a%i!=0&&b%i!=0)
        {
            if(b%i!=0) b/=i ;
            if(a%i!=0) a/=i ;
            c *= i ;
        }
    }
    if ( a==1 && b!=1 ) c*=b ;
    else c*=a ;
return c ;
}

int main()
{  
    int t ;
    cin >> t ;
    while(t--)
    {
        ll n ;
        cin >> n ;
        ll a[n] ;
        for ( ll i=0 ; i<n ; i++ )
        cin >> a[i] ;
      sort( a  , a+n ) ;
      if ( a[1]%a[0] == 0 ) cout << a[1] << "\n" ;
      else
      { ll x , y=max ;
        for ( ll i=1 ; i<n ; i++)
        {
            for ( ll j=0 ; j<i ; j++ )
            {
                x = LCM ( a[i] , a[j] ) ;
                if ( y > x ) y=x ;
            }
        }
         cout << y << "\n" ;
        
      }
    }
    return 0 ;
}
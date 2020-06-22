#include<iostream>
#define ll long long int 
#include<vector>
using namespace std ;

vector<ll> points ;
ll a , b ;
ll min ( ll a , ll b )
{
    return (a<b)? a:b ;
}
//vector<ll>

int Points( ll n )
{
    if ( n%(a*b) == 0 ) return 1 ;
    else
    {
        ll x = n%(a*b) ;
        //if ( x > a )    return 0 ;
        ll i=0 ;
        while(x>=0)
        {
            if(i%2==0)  x-=a ;
            else    x-=b ;
            i++ ;
        }
        if(i%2!=0)  return 1 ;
        else    return 0 ;
    }
}

int main()
{
        int n  ;
        cin >> n ;
        ll k , x ;
        cin >> a >> b >> k ;
        //ll h[n] ;
        for ( ll i=0 ; i<n ; i++ )
            {
                cin >> x ;
                points.push_back(Points(x)) ;
            }
        ll m = 0 ;
        for ( int i=0 ; i<n ; i++ )
        {
            if(points[i]==0)    m++ ;
        }
        //cout << m ;
       if ( m<=k )  cout << n ;
        else    cout << n - m + k ;
    return  0 ;
}
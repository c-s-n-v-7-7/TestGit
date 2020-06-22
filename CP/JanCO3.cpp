#include<iostream>
//#include<vector>
#include<stack>
#define ll long long int
#define m 100000000
#define g 1000100
using namespace std;

ll min ( ll a , ll b )
{
    return (a<b)? a:b ;
}
//vector<vector<ll>> v ;
stack<ll> points; 
ll NoSteps ( ll n , ll cur , string s[] )
{
        ll x = - 1 , in=m ;
    if (s[n] == '1' && ((cur+k)>=(n+1)) )   return 0 ;
    for ( int i=points.top()+1 ; i<k ; i++ )
    {
        if ( s[cur][i] == '1' )
        {   
            points.push(i) ;
            x = NoSteps( n , i , s ) ;
            if ( x!=-1 ) 
            {
                if ( in > x )   in = x ;
            }       
        }
    }
    if ( in == m ) in = -1 ;
return in ;
}

int main()
{
    ll t ;
    cin >> t ;
    while(t--)
    {
        ll n , k ;
        cin >> n >> k ;
        string s[n] ;
        for ( ll i=0 ; i<n ; i++)
        {
            cin >>s[i] ;
         //   for ( ll j=0 ; j<n ; j++ )
       //         v[i][j] = -1 ;
     //           v[i][n] = 0 ;
   //             v[n][i] = 0 ;
        }
 //       v[n][n] = 0 ;
        if ( k>=n-1 ) cout << "0\n" ;
        else    
        {
            points.push(0);
            cout << NoSteps( n , 0 , s ) ;
            points.clear() ;
        }    
    }
    return 0 ;
}
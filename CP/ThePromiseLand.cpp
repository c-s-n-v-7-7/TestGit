#include<iostream>
//#include<vector>
#define ll long long int 
using namespace std ;

ll mod ( ll a )
{
    return (a<0)? -a:a ;
}

int main()
{
ll t ;
cin >> t ;
while(t--)
{
    ll n , m ;
    cin >> n >> m ;
    ll x , y , s ;
    cin >> x >> y >> s ;
    ll r[2] = { 0 , 0 } , c[2] = { 0 , 0 } , rm=0 , cm=0  ;
    //vector<ll> v1 , v2 ;
    for ( ll i = 0 ; i<x ; i++ )
        {
            cin >> r[i%2] ;
            if ( mod(r[i%2] - r[(i+1)%2]) >= s ) 
            {
                rm += mod( r[i%2] - r[(i+1)%2] )/s ;
            } 
        }
    for ( ll i = 0 ; i<y ; i++ )
        {
            cin >> c[i%2] ;
            if ( mod(c[i%2] - c[(i+1)%2]) >= s ) 
            {
                cm += mod( c[i%2] - c[(i+1)%2] )/s ;
            } 
        }
        cout << rm*cm << "\n" ;          
}

return 0 ;
}
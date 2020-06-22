#include<iostream>
#define ll long long int 
#define m 1000001
using namespace std;

ll cost[m] ;
ll a[m] ;
ll b[m] ;
float min ( float x , float b )
{
    return (x<b)? x : b ;
}

float MinX( ll n , ll cur , ll prev )
{
    ll var = 1000000000000 ;
    if ( cost[cur] == -1 )
    {
        for ( int i=prev ; i<a[n] ; i++ )
        {
                cost[cur] = min ( (i-a[cur])*(i-a[cur]) + MinX( n , cur+1,prev ) , var ) ;
        }
    }
return cost[cur] ;
}

float MinY( ll n , ll cur , ll prev )
{
    ll var = 1000000000000 ;
    if ( cost[cur] == -1 )
    {
        for ( int i=prev ; i<=b[n] ; i++ )
        {
                var = min ( (i-b[cur])*(i-b[cur]) + MinX( n , cur+1 , prev ) , var ) ;
        }
        cost[cur] = var ;
    }
return cost[cur] ;
}

int main()
{
    ll n ;
    cin >> n ;
    ll a[n] , b[n] ; 
    for ( ll i=0 ; i<n ; i++ )
    {
        cin >> a[i] >> b[i] ;
    }
    for ( ll i=0 ; i<n ; i++ )
    cost[i] = -1 ;
   cout << MinY(n,0,0) + MinX (n,0,0) ;
    return 0 ;
}
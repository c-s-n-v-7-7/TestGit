#include<iostream>
using namespace std ;

int mod ( int x )
{
    return (x>0)? x:-x ;
}
int main()
{
    int n ;
    int t ;
    cin >> t ;
    while ( t-- )
    {
        cin >> n ;
    int a[n] ;
    for ( int i=0 ; i<n ; i++ )
    {
        cin >> a[i] ;
    }
    int u , v ;
    int max = 0 ;
    for ( int i=0 ; i<n-1 ; i++ )
    {
        cin >> u >> v ;
        if ( mod(u-v) > max )   max = mod(u-v) ; 
    }
    cout << max ;
    }
    return 0 ;
}
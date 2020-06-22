#include<iostream>
#define ll long long int 
using namespace std ;

int main()
{
    int t ;
    ll n ;
    cin >> t ;
    while(t--)
    {
        cin >> n ;
        ll v[n] , a , b , c ;
        ll max = 0 ;
        for ( ll i=0 ; i<n ; i++ )
        {
            cin >> a >> b >> c  ;
            v[i] = (c*b)/(a+1) ;
            if ( max < v[i] )   max = v[i] ;
        }
    cout << max << "\n" ;
    }
    return 0 ;  
}
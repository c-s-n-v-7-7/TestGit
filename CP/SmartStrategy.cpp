#include<iostream>
#define ll long long int 
using namespace std ;

int main()
{
    ll t , n , q ;
    cin >> t ;
    while(t--)
    {
        cin >> n >> q ;
        ll d[n] ;
        for ( ll i=0 ; i<n ; i++ )
        cin >> d[i] ;
        ll x[n];
        for ( ll i=0 ; i<q ; i++ )
        {
            cin >> x[i] ;
            for ( int j=0 ; j<n ; j++ )
            {
                x[i]/=d[j];
            }
        }   
        for ( ll i=0 ; i<q ; i++ )
        {
            cout << x[i] << " " ;
        }
        cout << "\n" ;
    }
    return 0 ;
}
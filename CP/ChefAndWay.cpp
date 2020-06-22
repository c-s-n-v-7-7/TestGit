#include<iostream>
#define ll long long int 
#define max 1000000000
#define N 100000
using namespace std ;
// Doing the same using DP 
/*ll MinProd( int a[] , int n , int cur , int lim )
{
                
    ll prod = max , var=max ;
            for ( ll i=1 ; i<=lim,cur+i<=n ; i++ )
            {
                
            }
}
*/
Product[N+1] ;

ll MinProd ( int a[] , int n , int cur , int lim )
{
    if ( Product[cur] == -1)    
    {
        ll var , pos = max ;
        for ( ll i=1 ; i<=lim , cur+i<=n ; i++ )
        {
            var = Product( a , n , cur+i , lim ) ;
            if ( pos > var )    pos = var ;
        }
        Product[cur] = var ;
    }
    return Product[cur] ;
}

int main()
{
    ll t ;
    cin >> t ;
    
    while(t--)
    {
        ll n , k ;
        cin >> n >> k ;
    ll a[n+1] ;
    a[0] = max ;
    for ( ll i=1 ; i<=n ; i++ )
    {
        cin >> a[i] ;
    }
    
    for ( ll i=1 ; i<=n-k-1 ; i++ )
    {
        Product[i] = -1 ;
    }

    for( ll i=n-k ; i<n ; i++ )
    Product[i] = a[n]*a[i] ;
    
    Product[n] = a[n] ;
    
        cout << MinProd ( a , n , 1 , k) << "\n" ;
    }
    
    return  0 ;
}
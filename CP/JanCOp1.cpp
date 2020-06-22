#include<iostream>
#define ll long long int
using namespace std ;

ll mod ( ll a ) {
    if ( a < 0 )    return -a ;
    else    return a ;
}

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        ll max , n , a , b , c ;
        cin >> n >> a >> b >> c ;
        int f[n] ;
        int flag = 0 ;
        max = 1000000000000 ;
        for ( ll i=0 ; i<n ; i++ )
        {
            cin >> f[i] ;
            if ( f[i] <= b && f[i] >= a )
            {   flag=1 ;
                max = b -a ;
            }
            if ( max >  mod(f[i]-a) + mod(f[i]-b) ) max = mod( f[i] - a ) + mod ( f[i] - b )  ; 
        }

        cout << max + c << "\n" ;
        
    }
    return 0 ;
}
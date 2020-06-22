#include<iostream>
using namespace std ;

int main()
{
        int t ;
        cin >> t ;
            while(t--)
            {
                int n , d ;
                    cin >> n >> d ;
                int a[n] ;
                for ( int i=0 ; i<n ; i++ )
                {
                    cin >> a[i] ;
                }
                if ( n == 1 ) {  cout << a[0] << "\n" ; continue ; }
                if ( a[1] >= d  )   { cout << d+a[0] << "\n" ; continue ; }
                else
                {
                        int j=2 ;
                    while ( d > a[1] )
                    {
                        a[1] ++ ;
                        a[j]-- ;
                         d-= (j-1) ;
                        if ( a[j] == 0 )    j++ ;
                        if ( j==n ) break ;
                    }
                        if ( d < a[1] )    a[1]-- ;
                        cout << a[0] + a[1] << "\n" ;
                    
                }
            }
    return 0 ;
}
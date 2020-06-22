#include<iostream>
#define ll long long int 
#define p 1000000007
using namespace std ;

ll choose( ll n , ll r , ll** x )
{
        if(x[n][r] == -1)
        {
            x[n][r] = (choose(n-1,r-1)+choose(n-1,r))%p ;
        }
return x[n][r] ;
}
int main()
{
    ll m ;
    int  k , x ;
    cin >> m >> k ;
    ll taken=0 ;
    for ( int i=0 ; i<k ; i++ )
    {
            cin >> x ;
            taken += x ;
    }
    if ( taken > m )    cout << "0" ;
    if ( taken == m )   cout << "1" ;
    else   
        {
            m-= taken ;
            ll c[m+k][k+1] ;
            for ( int i=0 ; i<m+k ; i++ )
            {
                for ( int j=0 ; j<=k ; j++ )
                {
                    if ( i<j ) c[i][j] = 0 ;
                    if ( i==j ) c[i][j] = 1 ;
                    if ( i==j+1 )  c[i][j] = j+1 ;
                    else    c[i][j] = -1 ; 
                }
            }
            cout << choose(m+k-1,k,c) ;
        }
    return 0 ;
}
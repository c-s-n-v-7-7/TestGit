#include<iostream>
using namespace std ;

int NoS ( int c[] , int s , int n , int rhs )
{
    if ( rhs ==0 )  return 1 ;
    if ( rhs < 0 )  return 0 ;
    if ( valtable[s][rhs] == -1 )
    {
        int var = 0 ;
        for ( int i=0 ; i<n ; i++ )
        {
            var += NoS( c , s+1 , n , rhs-c[s]*i ) ;
        }
    valtable[s][rhs] = var ;
    }
return valtable[s][rhs] ;
}

int main()
{
    int n ;
    cin >> n ;
    for ( int i=0 ; i<n ; i++ )
    {
        cin >> c[i] ;
    }
    int rhs ;
    cin >> rhs ;
    for ( int i=0 ; i<n ; i++ )
    {
        for ( int j=rhs ; j>=0 ; j++ )
        {
                valtable[i][j] = -1 ;
                if ( c[j] > j ) valtable[i][j] = 0 ;
        }
    }
    cout << NoS( c , 1 , n , rhs ) ;
    return 0 ;
}
#include<bits/stdc++.h>

using namespace std ;

float valExp ( int src , int n , int a[] )
{
    float var ;
    if ( a[src] == 0 )  var = 0 ;
    else
    {
        a[src]-- ;
        var = 1 ;
        for ( int i=0 ; i<n ; i++ )
        {
            var += valExp(i,n,a)/(float)n ;
        }
    }
    return var ;
}

/*float StepsProb ( int n , int a[] )
{
    float f = 0 ; 
    
}*/

int main()
{
    int n ;
    cin >> n ;
    int a[n] ;
    for ( int i=0 ; i<n ; i++ )
    {
        cin >> a[i] ;
    }
    cout << StepsProb( int n , int a ) ;
    return 0 ;
}
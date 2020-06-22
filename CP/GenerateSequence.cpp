#include<iostream>
#include<vector>
using namespace std; 
long long int choose ( int n , int r )
{
    if ( n == r )   return 1 ;
    if ( n<r )  return 0 ;
    long long int var = choose( n-1 , r-1 ) + choose( n-1 , r );
return var ;
}
int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int n ;
        cin >> n ;
        int x , y , z ;
        int a[n+1] ;
        vector<int> alr ;
        for ( int i=0 ; i<n+1 ; i++ )   alr[i] = 0 , a[i] = 0 ;
        for ( int i=0 ; i<n ; i++ )
        {
            cin >> x >> y >> z ;
            a[z] = x ;
            alr[z] = y-1 ;
        }
        int carry = 0 ;
        long long int ways = 0 ;
        for ( int j=0 ; j<n ; j++ )
        {
            if ( alr[j] != 0 )  {   ways += choose ( carry , alr[j] ) ;  }    
            if ( a[j] == 0 )    carry++ ;    
        }
    cout << ways%1000000007 ;
    }
    return 0 ;
}
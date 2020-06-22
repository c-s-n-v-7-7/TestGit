#include<iostream>
#include<algorithm>
using namespace std ;

/*int Check ( int k , int a[] , int n , int id )
{
    if ( k==0 ) return (id+1)%2 ;
    else
    {
        int l ;
        for ( int j=n-1 ; j>=0 ; j-- )
        {
            if ( ( k-id ) >= a[j] ) return id%2 ;  
        }
        int j = n-1-i ;
        for(int i=0 ; i<j ; )
        {
            if (a[i]+a[j] == k )    return (id+1)%2 ;
            if ( a[i]+a[j] > k )    j-- ;
            if ( a[i] + a[j] < k )  i++ ;
        }
    return Check( k-a[n-1] , a , n , id++ ) ;
    }
}*/
int dp[202] ;
int* create_dp ( )
int main()
{
    int n , k ;
    int a[n] ;
    for ( int i=0 ; i<n ; i++ )
    {
        cin >> a[i] ;
        dp[i] = 0 ;
    }    
    sort(a,a+n) ;
    int l = 1 ;
    //int y = Check( k , a , n , 1 ) ;
    for( int i=0 ; i<=k ; i++ )
    {
        
    }

    return 0 ;
}
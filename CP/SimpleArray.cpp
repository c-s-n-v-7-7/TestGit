#include<iostream>
#define ll long long int
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int n ;
        cin >> n ;
        int a[n] ;
        int count[n+1] ;
        int diff[2*n+1] ;
        for ( int i=0 ; i<n ; i++ )
        {
            count[i] = 0 ;
            diff[i] = 0 ;
            diff[2*i] = 0 ;
        }    
        diff[2*n-1] = 0 ;
        for ( int i=0 ; i<n ; i++ )
        {
            cin >> a[i] ;
            count[a[i]]++ ;
        }
        for ( int i=0 ; i<n ; i++ )
        {
            for ( int j=0 ; j<n ; j++ )
            {
                if(i==j)    continue ;
                diff[(a[i]-a[j])+n]++ ;
            }
        }
        int m1=0 , m2=0 ;
        for ( int i=0 ; i<n ; i++ )
        {
            if ( count[i] > m1 )    m1=count ;
            if ( max (diff[i] , diff[2*i]) > m2 )   m2=max( diff[i],diff[2*i]) ; 
        }
        m2 = max ( m2 , diff[2*n-1]) ;
        cout << m2 << " " << m1 << "\n" ;
    }
    return 0 ;
}
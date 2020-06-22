#include<iostream>
using namespace std ;

int max ( int a, int b)
{
    return (a>b)? a:b ;
}

int LGS ( int a[] , int n , int s )
{
    if ( arr[i] == -1 )
    {

    for ( int i=s-1 ; i>=0 ; i--)
        {
            if (a[i]<a[s])
            {
                arr[s] = max ( 1+ LGS(a,n,i) , arr[s] )  ;
            }   
        }
    }
return arr[s] ;
}

int main()
{
    int n ;
    cin >> n ;
    int a[n] ;
    for ( int i=0 ; i<n ; i++ )
    cin >> a[i] ;
    int arr[n] ;
    arr[0] = 0 ;
    for ( int i=1 ; i<n ; i++ )
    arr[i] = -1 ;
   cout <<  LGS( a , n , n-1 ) ;
    return 0 ;
}
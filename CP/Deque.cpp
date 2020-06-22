#include<iostream>
using namespace std ;

int value[101][101] ;

int Maximize ( int l , int h , int[] a , int j )
{
     if ( value[l][h] == - 1 )
        
        {
            value[l][h] =  max ( a[l] + Maximize(l+1,h,a,j+1) , a[h] + M aximize(l,h-1,a,j+1) ) ;
            
        }
    if ( j%2 == 0 ) return value[l][h] ;
            else    return -value[l][h] ;    
}

int main()
{
    int n ;
    cin >> n ;
    int a[n] ;
    for ( int i=0 ; i<n ; i++ )
    cin >> a[i] ;
    for ( int i=0 ; i<101 ; i++ )
    {
        for ( int j=0 ; j<101 ; j++ )
        {
            value[i][j] = -1 ;
        }
    }
    cout << Maximize ( 0 , n-1 , a , 0 ) ;
    return 0 ;
}
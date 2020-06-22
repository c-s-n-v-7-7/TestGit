#include<iostream>
using namespace std;

int max ( int a , int b )
{
    return (a<b)? b:a ;
}

int min ( int a , int b )
{
    return (a<b)? a : b ;
}

int mat[1001][1001] ;

int SCS ( char x[] , char y[] , int n , int s1 , int s2 ) 
{
    if ( s1<0 )    return s2+1 ;
    if ( s2<0 )    return s1+1 ;
    if ( mat[s1][s2] == -1 )
    {
        int var ;
        if ( x[s1] == y[s2] )   var =  LCS ( x , y , n , s1-1 , s2-1 )+1 ;
            else    
                {
                    var = min ( LCS ( x , y , n , s1-1 , s2 )+1 , LCS( x , y , n , s1 , s2-1 )+1 ) ;
                }
        mat[s1][s2] = var ;
    }
return mat[s1][s2] ;
}

int main()
{
    int n ;
    cin >> n ;
    char x[n+1] , y[n+1] ;
    for ( int i=0 ; i<n ; i++ )
    {
        cin >> x[i] ;
    }
    for ( int j=0 ; j<n ; j++ )
    {
        cin >> y[i] ;
    }
    for ( int i=0 ; i<n ; i++ )
    {
        for ( int j=0 ; j<n ; j++ )
        {
            mat[i][j] = -1 ;
        }
    }
    cout << SCS ( x , y , n , n-1 , n-1 ) ;
   
    return 0 ;
}
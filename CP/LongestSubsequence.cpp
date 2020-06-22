#include<iostream>
using namespace std ;

int max ( int a , int b , int c=0 )
{
    if ( a>=b && a>=c ) return a ;
    if ( b>=a && b>=c ) return b ;
    if ( c>=a && c>=b ) return c ;
}
//The following algorithm is the recurssive algorithm :-
/*int LongestSequence ( int a1[] , int a2[] , int n , int s1 , int s2 , int cont=0 )
{
    int var = 0 ;
    if ( s1 == n || s2 == n )  return var ;
    if ( a[s1] == a[s2] )  {    var = cont+1+LongestSequence( a1 , a2 , n , s1+1 , s2+1 , cont++ ) ;    return var ; } 
    if ( a[s1]!= a[s2] )
    {
        var = max( LongestSequence( a1 , a2 , n , s1+1 , s2 ) , LongestSequence( a1 , a2 , n , s1 , s2+1 ) , 0 ) ;
    } 
}
*/
//This is the DP based algorithm :- // Yet to be Completed.
int ComMat[101][101] ;
int LongestSequence ( int a1[] , int a2[] , int s1 , int s2 , int cont )
{
    if ( a1[s1] == a2[s2] ) ComMat[s1][s2] = ComMat[s1-1][s2-1]+1 ;
    if ( a1[s1] != a2[s2] ) 
    {
        ComMat[s1][s2] = 0 ; 

    }
}
int main()
{
    int n ;
    cin >> n ;
    int arr1[n+1] , arr2[n+1] ;
    arr1[0] =0 ; arr2[0] = 0;
    for ( int i=0 ; i<=n ; i++ )
    {
        for(int j=0 ; j<=n ; j++ )
        {
            ComMat[i][j] = -1 ;
        }
    } 
    for( int i=1;i<=n ; i++ )
    {
        cin >> arr1[i] ;
    }
    for ( int i=1;i<=n ; i++ )
    {
        cin >> arr2[i] ;
    }
    cout <<  LongestSequence ( arr1 , arr2 , n , 1 , 1  ) ;
    return 0 ;
}
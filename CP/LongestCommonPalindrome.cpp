#include<iostream>
using namespace std ;

int arr[101][101] ;

int LongestPalindromicSubsequence( int a[] , int st , int end )
{
    if ( st < end ) return 0 ;
    if ( arr[st][end] !=-1)
    {
    int var = 0 ;
    if ( a[st] == a[end] )  var = 1+LongestPalindromicSubsequence( a , st+1 , end-1 ) ;
    else    
    {
        var = max ( LongestPalindromicSubsequence(a,st+1,end) , LongestPalindromicSubsequence(a,st,end-1)) ;
    }
    arr[st][end] = var ;
    }
return arr[st][end] ;
}

int main()
{
    int n ;
    cin >> n ;
    int a[n] ;
    for ( int i=0 ; i<n ; i++ )
    {
        cin >> a[i] ;
    }
    for ( int i=0 ; i<n ; i++ )
    {
        for ( int j=0 ; j<n ; j++ )
        {
            a[i][j] = -1 ;
        }
    }
    cout << LongestPalindromicSubsequence( a , 0 , n-1 ) ;
    return 0 ;
}
#include<iostream>
#include<vector>
using namespace std;

vector<int> position ;

int length[101][101] ;

int LongestRepeatingSubsequence( int a[] , int n , int s1 , int s2 )
{
    if ( length[s1][s2] == -1)
    {
        int l = 0 ;
        for ( auto it = position.begin() ; it!=position.end() ; ++it )  
        if ( *it == s1 )    l= LongestRepeatingSubsequence( a , n , s1+1 , s2 ) ;
        if ( a[s1] == a[s2] )   
        {
            l += LongestRepeatingSubsequence( a , n , s1+1 , s2+1 ) ;
        }
        else
        {
            l =  LongestRepeatingSubsequence(a , n , s1 , s2+1) ;
        }
        length[s1][s2] = l ;
    }
return length[s1][s2] ;
}

int main()
{
    int n ;
    cin >> n ;
    int a[n] ;
    for ( int i=0 ; i<n ; i++ )
    cin >> a[i] ;
    for ( int i=0 ; i<n ; i++ )
    {
        for ( int j=0 ; j<n ; j++ )
            length[i][j] = -1 ;
    }
    length[n][n] = 0 ;
    cout << LongestRepeatingSubsequence( a , n , 0 , 1 ) ;
    return 0 ;
}
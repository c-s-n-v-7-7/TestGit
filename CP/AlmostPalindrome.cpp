#include<iostream>
using namespace std ;

/*long long int totalWays( int arr[] , int n )
{
    
}*/

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int n ;
        cin >> n ;
        string s ;
        cin >> s ;
        int l , r ;
        cin >> l >> r ;
        arr[26] ;
        for ( char ch = 'a' ; ch<='z' ; ch++ )  arr[ch] = 0 ;
        for ( int i=l ; i<=r ; i++ )
        {
            arr[s[i]] ++ ;
        }
        for ( char ch = 'a' ; ch<='z' ; ch++ )
        {
            arr[ch] /= 2 ;   
        }
        cout << totalWays ( arr , r-l+1 ) ;
    }
    return 0 ;
}
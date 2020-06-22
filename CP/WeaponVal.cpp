#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int n ;
        cin >> n ;
        string s ;
        int x[10]={0,0,0,0,0,0,0,0,0,0} ;
        while(n--)
        {
            cin >> s ;
            for ( int i=0 ; i<10 ; i++ )
            {
                x[i] = (s[i]-48)^x[i] ;
            }
        }
        int sum = 0 ;
        for ( int i=0 ; i<10 ; i++ )
        sum += x[i] ;
    cout << sum << "\n" ;
    }
    return 0 ;
}
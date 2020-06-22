#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std ;

int main()
{
    long int t , c[3] ;
    cin >> t ;
    while(t--)
    {
        cin >> c[0] >> c[1] >> c[2] ;
        sort( c , c+3 ) ;
        if ( c[2] > c[1]+c[0]+1 )   cout << "No\n" ;
        else        cout << "Yes\n" ;
    }
    return 0 ;
}
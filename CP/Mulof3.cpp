#include<iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        long long int k , d0 , d1 ;
        cin >> k >> d0 >> d1 ;
        if ( d0%3 == 0 && d1%3 == 0 )   cout << "YES\n" ;
        if ( d0%3 == 1 && d1%3 = 2 || d0%3 = 2 && d1%3 == 1 )   cout << "NO\n" ;
        else    cout << "NO\n" ;
    }
    return 0 ;
}
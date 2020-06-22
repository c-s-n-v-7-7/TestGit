#include<iostream>
using namespace std ;

int main()
{
    ll t ;
    cin >> t ;
    while(t--)
    {
        ll a , b , c , r ;
        cin >> a >> b >> c >> r ;
        ll time=0 , total = b-a , av = 0 ;
        if ( b < a )
        {
            int temp = a ;
            a = b ;
            b = temp ;
        }
        if ( c =< a )
        {
            av = 2*c - a + r ;
        }
        if ( c >= b )
        {
            av = c-a-r ;
        }
        if ( c < b && c > a )
        {
            if ( c-r <= a ) av = 0 ;
            else if ( c-r > a ) av += c-r-a ;
            if ( c+r >= b ) av += c+r-a ;
        }
        cout << total - av << "\n" ;
    }
    return 0 ;
}
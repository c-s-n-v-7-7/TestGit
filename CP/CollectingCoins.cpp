#include<iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        long int a , b , c , n ;
        cin >> n >> a >> b >> c ;
        if ( (n+a+b+c)%3 ==0 )  cout << "YES\n" ;
        else    cout << "NO\n"
    }

    return 0 ;
}
#include<iostream>
using namespace std;

int main()
{
    int n ;
    cin >> n ;
    int a[n],b[n] ;
    for ( int i=0 ; i<n ; i++ )
    {
        cin >> a[i];
        b[n-1-i] = a[i] ;
    }
    for ( int o=0 ; o<n ; o++ )
    cout << b[o] <<  "  " ;
        return 0; 
}
#include<iostream>
#define ll long long int
#define p 1000000007
using namespace std ;

ll fact[100001] ;

ll factorial( int x )
{
    if (fact[x]==-1)
    {
        fact[x] = (factorial(x-1)*x)%p ;
    }
return fact[x] ;
}

int main()
{
    int t ;
    cin >> t ;
    fact[0]=1 ;
    fact[1]=1 ;
    for ( int i=2 ; i<n ; i++ )
    {
        fact[i] = -1 ;
    }
    while(t--)
    {
        int n ;
        cin >> n ;
            int x = n-1 , y = 1 ;
            ll sum = 0 ;
        for (x <= y )
        {
            ll sum = 2*factorial(x)+2*factorial(y) ;
        }
        cout << sum << "\n"; 
    }
    return 0 ;
}
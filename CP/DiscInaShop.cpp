#include<iostream>
using namespace std ;

long long int NoDigs( long long int n )
{
    long long int p = 1 ;
    while(n!=0)
    {
        p*=10 ;
        n/=10 ;
    }
return p ;
}

int main()
{
    int t ;
    long int n,m ;
    cin >> t ;
    while(t--)
    {
        cin >> n ;
        m = n ;
        int max = 0 ;
        long long int pow ;
        long long int p = NoDigs(n)/10 ;
        while(p!=1)
        {
            m = n/p ;
            if ( m%10 > max )  {   max = m%10 ; pow = p ;}
            p/=10 ;
            if ( m%10 == 0 )    break ;
        }
        cout << n - m*pow << "\n" ;
    }
    return 0 ;
}
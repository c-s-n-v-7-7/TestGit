#include<iostream>
#define p 1000000000
#include<vector> 
using namespace std;

vector<int> v ;
vector<int> primes ( p ) 
{
    for ( long int i=3 ; i*i<=p ; i++ )
    {
        int flag = 0 ;
        for ( auto it=primes.begin() ; it!=primes.end() ; ++it )
        {
            if( i%(*it)==0 )    flag = 1 ;
        }
        if(flag) v.push_back(i) ;
    }
return v ;
}

int main()
{
    v.push_back(2) ;
    primes(p) ;
    int t ;
    cin >> t ;
    while(t--)
    {
    int n ;
    cin >> n ;
    vector<int> y ;
    
    int fact=0 ;
    for ( auto it=v.begin() ; it!=v.end() ; ++it )
    {
        if ( n%(*it) == 0 ) {   y.push_back( *it) ; fact++ ; }
        if ( fact == 3 || *it==n )  break ;
    }
    if ( fact == 3 )
    {
        cout << "YES\n" ;
        cout << y[0] << y[1] << n/(y[0]*y[1]) ;
    }
        else    cout << "NO\n" ;
    y.clear() ;
    }
    return 0 ;
}
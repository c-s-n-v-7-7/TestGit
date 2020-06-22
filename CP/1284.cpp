#include<bits/stdc++.h>
#define ll long long int 
#include<algorithm>
using namespace std ;

class problem
{
    public : 
    ll cost ;
    ll time ;
    bool operator < ( problem& h )
    {
        if ( time < h->time ) return true ;
        return false ;  
    }
} ;

int main()
{
    int m ;
    cin >> m ;
    while(m--)
    {
        ll n , t , a , b ;
        cin >> n >> t >> a >> b ;
        problem test[n] ;
        int y ;
        for ( ll i=0 ; i<n ; i++ )
        {
            cin >> y ;
            if ( y == 0 )   test[i].cost = a ;
            else    test[i].cost = b ;
        }  
        for ( ll i=0 ; i<n ; i++ )
        {
            cin >> test[i].time ;
        } 
        sort(test,test+n) ;
        ll probs = 0;
        for ( ll t=0 ; t<n ; t+=test[t].time )
        {
            if ( t <= test[t].time )    problem++ ;
            else    break ;
        }
        cout << problem << "\n" ;
    }
    return 0 ;
}
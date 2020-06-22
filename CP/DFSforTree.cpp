#include<iostream>
using namespace std ;

int main()
{
    int n , x , y ;
    vector<int> G[n+1] ;
    for ( int i=0 ; i<n-1 ; i++ )
    {
        cin >> x >> y ;
        G[x].push_back(y) ;
    } 
    for ( int i=0 ; i<n; i++ )
    {
        for ( auto it = G[i].begin() ; it!=G[i].end() ; ++it )
            cout << *it << " " ; 
    }
    return 0 ;
}
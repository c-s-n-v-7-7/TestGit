#include<iostream>
using namespace std ;

set<int>* Transpose( set<int>G[] , int n )
{
    set<int> Transpose[n+1] ;
    for ( int i=1 ; i<=n ; i++ )
    {
        for ( auto it=G[i].begin() ; it!=G[i].end() ; ++it )
        {
            Transpose[*it].insert(y) ;
        }
    } 
return Transpose ;
}

int main()
{
    int n ;
    cin >> n ;
    int x , y ;
    set<int>G[n+1] ;
    while(1)
    {
        cin >> x >> y ;
        if ( x<0 || y<0 )   break ;
        G[x].insert(y) ;
    }
    set<int>*T = Transpose( G , n ) ;
    for ( int i=1 ; i<=n;i++)
    {
        cout << "\t" << i << "\n" ;
            for ( auto it = T[i].begin() ; it!=T[i].end() ; ++it)
            {
                cout << *it << " " ;
            }
        cout << "\n" ;
    }
    return 0 ;  
}
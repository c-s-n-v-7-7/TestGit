#include<iostream>
#include<set>
using namespace std ;

set<int> G[n+1] ;
set<int> s[2] ;

bool bipartite( int x )
{
    
}

int main()
{
    int n ;
    cin >> n ;
    int x,y; 
    while(1)
    {
    cin >> x >> y ;
    if ( x<0 || y<0 )   break ;
    G[x].insert(y) ;
    G[y].insert(x) ;
    }
    s[0].insert(1) ;
    set<int>::iterator j[2] ;
    j[0] = s[0].begin() ;
    j[1] = s[1].begin() ;
    int flag = 0 , i = 0 ;
    while(s[0].size()+s[1].size()!=n)
    {
    for ( auto it = G[*j[i%2]].begin() ; it!=G[*j[i%2]].end(); ++it )
    {
             if (s[(i+1)%2].find(*it)==s[(i+1)%2].end() )
             {
                 s[i%2].insert(*it) ;
             }
             else
             {
                 flag = 1 ; // Basically means that there's an interconnection b/w the two edges !
                 break ;
             }
             
    }
    i++ ;
    if ( flag ) break ;
    }
    if ( flag ) cout << " Graph is not Bipartite\n" ;
    else
    {
        cout << "Graph is Bipartite :-\n\n   Set1:-\n" ;
        for ( auto it = s[0].begin() ; it!=s[0].end() ; ++it)
        {
            cout << *it << "\n " ;
        }
        cout << "   Set1:-\n" ;
        for ( auto it = s[1].begin() ; it!=s[1].end() ; ++it)
        {
            cout << *it << "\n" ;
        }
    }
    
    return 0 ;
}
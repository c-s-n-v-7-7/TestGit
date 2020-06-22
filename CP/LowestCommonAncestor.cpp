#include<iostream>
using namespace std ;

int LCA ( int n1 , int n2 )
{
    if ( G[n1].begin() == G[n2].begin() )   return -G[n1].begin() ;
    else    return LCA ( -G[n1].begin() , -G[n2].begin() ) ;
}

int main()
{
    int n ;
    cin >> n; 
    int x , y ;
    while(1)
    {
        cin >> x >> y ;
        if ( x < 0 || y < 0 )   break;
        G[x].insert(y) ;
        G[y].insert(-x) ;
    }
    cout << "Enter the nodes : "  ;
    int n1 , n2 ;
    cin >> n1 >> n2 ;
    cout << LCA ( n1 ,n2 ) ;
    return 0 ;
}
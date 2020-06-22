#include<iostream>
#include<utility>
#include<set>
using namespace std ;

int mod ( int n )
{
    return (n<0)? -n : n ;
}

set<int> Route ;

void update( int c )
{
    set<pair<int,int>> :: iterator it = Route.find(c) ;
    if ( it!=Route.end())   it->second=distance[c]; 
    else
    {
        Route.insert(pair<int,int>(c,distance[c])) ;
    }
    
}

int Astar ( int d )
{
    //if ( s==d ) return 0 ;
    
        //Route.insert(pair<int,int>(s,0)) ;
        set<pair<int,int>> temp ;
        for ( auto it = G[Route.begin()].begin() ; it!=G[Route.begin()].end() ; ++it )
        {
           if (  distance[it->first] >  distance[s] + it->second ) 
           {
               distance[it->first] =  ( distance[s] + it->second ) ;
               if ( distance[s]+it->second == d )   return 1 ;
               temp.insert( pair<int,int>(it->first,d-distance[it->first]) ) ;   
           }
        }
        Route.erase(Route.begin()) ;
    for ( auto it = temp.begin() ; it!=temp.end() ; ++it )
        update(it->first) ;
return AStar(d) ;

}

int main()
{
    int n ;
    cin >> n ;
    int x , y , w ;
    while(1)
    {
        cin >> x >> y >> w ;
        if ( x < 0 || y < 0 )   break ;
        G[x].insert(pair<int,int>(y,w)) ;
        G[y].insert(pair<int,int>(x,w)) ;
    }
    cout << "Src : " ;
    cin >> x ;
    cout << "Dest : " ;
    cin >> y ;
    Route.insert(pair<int,int>(x,0)) ;
    distance[x] = 0 ; 
    cout << Astar( mod(y-x) , y ) ;
    return 0 ;

}
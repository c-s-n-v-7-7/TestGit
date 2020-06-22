#include<iostream>
#include<map>
#include<utility>
using namespace std ;
//Bellman Ford is exactly the same algorithm only the difference is it works for negative edges as well !!
map<int,int> G ;

int distances[101] ;

void display ( map<int,int> M )
{
    for( auto it = M.begin() ; it!=M.end() ; ++it )
    {
        cout << it->first << " " << it->second << "\n" ;
    }
}

void Dijkstra( int src )
{
    map<int,int> Cost ;
    Cost.insert(pair<int,int>(src,0)) ;
    map<int,int>::iterator j = Cost.begin() ;
    while(1)
    {
        for ( auto it = G[j->first].begin() ; it!=G[j->first].end();++it)
        {
            if ( distances[it->first] > j->second+it->second )  
            {   
               distances[it->first] = j->second+it->second ;
               int flag = 0 ;
               for ( auto k = Cost.begin() ; k!=Cost.end() ; ++k )  
               {
                   if ( k->first == it->first ) flag = 1 , k->second = distances[it->first] ;
               }
                if(!flag)   Cost.insert(pair<int,int>( k->first,distances[it->first] ) ) ;
            }
        }
    }
    display(Cost);
}


int main()
{
    int n ;
    cin >> n ;
    int x , y , w ;
    for ( int i=0 ; i<=n ; i++ )
    distances[i] = 99999 ;
    while(1)
    {
        cin >> x >> y >> w ;
        if ( x < 0 || y < 0 )   break ; 
        G[x].insert(pair<int,int>(y,w)) ;
        G[y].insert(pair<int,int>(x,w)) ;
    }

    Dijkstra( 1 , 1 ) ;
    return 0 ;
}
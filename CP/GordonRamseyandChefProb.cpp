#include<iostream>
#include<set>
#include<queue>
#define max 2000001
using namespace std ;

//int visited[max]; 

ll triangles = 0 ;
queue<int> nodes; 
mulitset<int> parent ;
void bfs( int x , int par=-1 )
{
        parent.insert(par) ;
        for ( auto it =g[x].begin() ; it!=g[x].end() ; ++it )
        {
            if (!visited[*it] ) nodes.push(*it) ;
                
        }
    
} 

int main()
{
    int n ;
    cin >> n ;
        bool setable[n+1] ; 
        for ( int i=0 ; i<=n ; i++ )
            visited[i] = 0 ;
        for ( int i=0 ; i<n-1 ; i++ )
        {
            cin >> x >> y ;
            g[x].insert(y) ;
            g[y].insert(x) ;
        }
            for ( int i=1 ; i<=n ; i++ )
            {
                cin >> setable[i] ;
            }
        for ( int i=1 ; i<=n ; i++ )
        {
            if(!visited[i]) bfs(i) ;
        }
    return 0 ;
}
#include<iostream>
#include<set>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

int visited[1001] ;

int height ( int k , int n )
{
    int h =0 , t ;

    queue<pair<int,int>> Tree ;
    vector<int> traversed ;
   
    while(!Tree.empty())Tree.pop() ;    
    traversed.clear() ;
   
    Tree.push(pair<int,int>(0,k)) ;
   
   for ( int i=1 ; i<=n ; i++ )
   {
       visited[i] = 0 ;
   }
   visited[0] = 1 ;
   visited[k] = 1 ;
    while(!Tree.empty())
    {
    for ( auto it = g[Tree.front()].begin() ; it!=g[Tree.front()].end() ; ++it )
        {
            if ( !visited[it->first] )
            {
                Tree.push(pair<int,int>(Tree.front(),it->first)) ;
                visited[it->first] = 1 ;
                if ( traversed.size()+Tree.size() == n ) return h ;
            }
        }
    t = Tree.front().first ;
    traversed.push_back(t) ;
    Tree.pop();
    if ( t != Tree.front().first)   h++ ;
    }

}

int PossibleHt( int n )
{
    int m = 1000 , l ;
    for (int i=1 ; i<=n ; i++ )
        {
            l = height( i , n ) ;
            if ( l < m )    m=l ;
        }
return m ;
}

int main()
{
    int n ;
    cin >> n ;
    for ( int i=0 ; i<n-1 ; i++ )
    {
        cin >> x >> y ;
        g[x].insert(y) ;
        g[y].insert(x) ;
    }
   cout << PossibleHt( n ) ;
    return 0 ;
}
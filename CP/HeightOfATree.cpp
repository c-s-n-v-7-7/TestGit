#include<iostream>
#include<set>
#include<vector>
#include<utility>
#include<queue>
using namespace std; 

int visited[101] ;

vector<pair<int,int>> BFS ( int s , set<int>G[] , n )
{
    vector<pair<int,int>> v ;
    queue<int> q ;
    q.push(s); 
    if (v.empty())  v.push_back(pair<int,int>(s,0)) ;
    int u = v[v.size()-1] ;
 while(!q.empty())
 {
    for ( auto it = G[s].begin() )
    {
        if(*it<0)   continue ;
        if ( !visited[*it] )   
        {
            q.push(*it) ;
             v.push_back(*it,u+1) ;
        }    
    }
q.pop();
s = q.front ;
}
return v ;
}

int main()
{
    int n ;
    cin >> n ;
    set<int> G[n+1] ;
    int m,x,y ;
    cin >> m ;
    for ( int i=0 ; i<m ; i++ )
    {
        cin >> x >> y ;
        G[x].insert(y);
        G[y].insert(-x) ;
    }
    for ( int i=0 ;i<=n ; i++)visited[i] = -1 ;
    cout << "Enter source : " ;
    cin >> x ;
    BFS( x , G , n ) ;
    return 0 ;
}
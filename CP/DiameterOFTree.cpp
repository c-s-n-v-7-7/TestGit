#include<iostream>
#include<map>
#include<bits/stdc++.h>
#include<utility>
#include<set>
using namespace std;

//vector<int> length[n] ;
int visited[1001] ;
set<int> G[1001] ;
int k ;
pair<int,int> dfs( int x )
{
    pair<int,int>var ;
    var.first = 0 ; var.second = x ; 
    set<int>::iterator it , j=G[x].begin() ;
    int flag=0 ;
    for ( ; j!=G[x].end();++j)
    {
        if (!visited[*j])
        {
            visited[*j] = 1 ;
            k = *j ;
            if ( var.first < dfs(k).first+1 )
            {
                var.first = dfs(k).first+1 ;
                var.second = dfs(k).second ;
                flag = 1 ;
            }
        }
    }
    if ( flag ) 
    {
        return var ;
    }
    if ( !flag )    return pair<int,int>(1,x) ;

}

int main()
{   
    int n ;
    cin >> n ;
    int x , y; 
    for ( int i=0 ; i<n-1 ; i++ )
    {
        cin >> x >> y ;
        G[x].insert(y) ;
        G[y].insert(x) ;
    }
    set<int> leaves ;
    for ( int i=0 ; i<=n ; i++ )
    visited[i] = 0 ;
    for ( int i=1 ; i<=n ; i++ )
    {
        if (G[i].size()==1)   leaves.insert(i) ;
    }
    int count = 0 ;
    pair<int,int> corners ;
    map<int,pair<int,int>,greater<int>> possible ;
    for ( auto it = leaves.begin() ; it!=leaves.end() ; ++it )
    {
        visited[*it] = 1 ;
        corners = dfs( *it ) ;
        //possible.insert(pair<int,pair<int,int>>(*it,corners)) ;
        cout << corners.second << "\n" ;
        visited[*it] = 0 ;
    }
    //map<int,pair<int,int>>:: iterator j = possible.begin() ;
    
    return  0 ;
}
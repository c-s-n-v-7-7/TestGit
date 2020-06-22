#include<iostream>
#include<map>
#include<utility>
#include<unordered_map>
#define int_MAX 300001
using namespace std ;

int cur[int_MAX] , prev[int_MAX] , min[int_MAX] ;

int max ( int a , int b )
{
    return ( a > b )? a:b ;
}

void visit( int x , int t )
{
    if ( Log.empty() )
    {
        Log.insert(pair<int,int>(i,x)) ;
        Update.insert(pair<int,int>(x,i)) ;
    }
    else
    {
        unordered_map<int,int>::iterator it ;
        it = Update.find(x) ;
            if ( it == Update.end() )   
            {
                prev[x] += (Update.size()-1) ;
                if (Update.rbegin()->first>x) prev[x] ++ ;
                Update.insert(pair<int,int>(x,i)) ;
                Log.insert(pair<int,int>(i,x)) ;
            }
            if ( it!= Update.end() )
            {
                j = it++ ;
                Update.erase(j) ;
                    int u=0 ;
                    for ( auto k = it ; k!=Update.end() ; ++k)
                    { u++ ; }
                    prev[v] += u ;
                if(Update.rbegin()->first<x) prev[x] -- ;
            }
    }
}

int main()
{
    int n , m ;
        cin >> n >> m ;
        
        for ( int i=0 ; i<=n ; i++ )
        {
            cur[i] = (i+1) ;
            prev[i] = (i+1) ;
            min[i] = (i+1) ;
        }
        
            int x ;
            for ( int i=0 ; i<m ; i++ )
            {
                cin >> x ;
                visit(x,i) ;
            }
    return 0 ;
}
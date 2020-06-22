#include<iostream>
#define ll long long int 
#define max 1000000001
#include<map>
#include<utility>
using namespace std;

bool sbv ( pair<ll,ll>&a , pair<ll,ll>&b )
{
    return( a->second > b->second )? true : false ;
}
multimap<ll,ll,sbv> m1 , m2 ; 
ll mod ( ll n )
{
    return (n<0)? -n : n ;
}
    map<ll,ll> m1 , m2 ;

int visited[2001] ;

bool pass ( map<ll,ll>::iterator i1 , map<ll,ll>::iterator i2 )
{

}
int main()
{
    ll n , m ;
    cin >> n >> m ;
    ll x ;
    for ( int i=0 ; i<n ; i++ )
        visited[i]  = 0 ;
    map<ll> xoy ;
    map<ll,ll>:: iterator i1 , i2 ;
    for ( int i=0 ; i<n ; i++ )
    {
        cin >> x ;
        i1=xoy.find(x%m) ;
        if ( i1==xoy.end() )
        {
            xoy.insert(pair<ll,ll>(x%m,1));
        }
        else    i1->second++ ;
    }
    
    
    for ( auto it = xoy.begin() ; it!=xoy.end() ; ++it )
    {
        m1.insert( pair<ll,ll> (it->second,it->first)) ;
    }
    
    xoy.clear() ;
    
    for ( int i=0 ; i<n ; i++ )
    {
        cin >> x ;
         i2=xoy.find(x%m) ;
        if ( i2==xoy.end() )
        {
            xoy.insert(pair<ll,ll>(x%m,1));
        }
        else    i2->second++ ;
    }
    
    for ( auto it =xoy.begin() ; it!=xoy.end() ; ++it )
    {
         m2.insert( pair<ll,ll> (it->second,it->first)) ;
    }
    multimap<ll,ll>::iterator j=m1.begin() ;
    int flag = 0 ;
    for ( auto it = m2.begin() ; it!=m2.end() ; ++it)
    {
        if ( it->first !=j->first)  {   flag = 1 ; break ; }
    ++j;
    }
//    else    flag = 1 ;
    ll x = -1 ;
    while(!flag&&i<n)
    {
            multimap<ll,ll>::iterator j=m2.begin() ;
        for ( auto it=m1.begin(); it!=m1.end();++it)
        {
            if ( it == m1.begin() )
            {
                if ( it->second >= j->second)
                x = m1.begin()->second-m2.begin()->second ; 
            
                else    x = j->second*m - it->first ;
            }
            else
            {
                if ( (it->second+x)%m != j->second )
                {
                    f = 1 ;
                break ;
                    
                }
                    
            }
            
        }
    if(f){
        x += m2.begin()->second ;
        x*=m ;
        x -= m2.begin()->second ;
    }
    i++ ;    
    }

    return 0 ;
}
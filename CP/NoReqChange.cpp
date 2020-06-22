#include<bits/stdc++.h>
#define ll long long int 
#include<set>
#include<vector>
#include<queue>
#define max 1000000005
using namespace std; 

ll least ;
vector<ll> deno ;
set<ll> poss ;
int n ;
//bool amount[max] ;
bool visited[max]; 
set<ll>c ;
 
void  P( ll p )
{
        c.clear() ;
        visited[0] = 1 ;    
    set<ll> poss ;
    poss.insert(0) ;
        
        set<ll>::iterator j , it = poss.begin() ;    
        bool flag =0 , f=0 ;
        int count = 0 ;
    
    while( *it+least<=p || c.size() < n )
    { //  cout << "1\n" ;
        for ( ll i : deno )
            {
                
               if(*it+i == p )
               {
                    flag = 1 ;
                    poss.clear() ;
                    break ;
                } 
               
               if( *it+i > p )
                {
                    poss.clear() ;
                     if ( c.size() < n ) 
                    c.insert(*it+i) ;
                    continue ;
                }   
               if (!visited[*it+1])
                {
                    poss.insert(*it+i) ;  
                    visited[*it+i] = 1 ;
                }
            }
    if(flag)   break ;
        
        ++it ;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin >> t ;
        while(t--)
        {
           // int n ;
            ll p ;
            cin >> n >> p ;
                //set<ll> deno ;
                for ( ll i=0 ; i<=p ; i++ )
                    visited[i]=0 ;
                ll x ;
                    least = max ;
                for ( int i=0 ; i<n ; i++ )
                {
                    cin >> x ;
                    if ( x < least ) least = x ;
                    deno.push_back(x) ;
                }
             P(p) ;
            if(c.empty() ) cout << "NO \n" ; 
            else    
            {
                cout << "YES " ;
            for ( ll x : c )
            {
                cout << x << " " ;
            }
            cout << "\n" ;
            }
            deno.clear() ;
        }
    return 0 ;
}
#include<iostream>
#define ll long long int
using namespace std;

int max ( ll arr[] , ll n )
{
    int x=0 ; 
    for ( int i=0 ; i<n ; i++ )
    {
        if ( arr[x] < arr[i] ) x=i ;
    }
return x ;
}

int main()
{
    ll n , sx , sy , x , y ;
    cin >> n >> sx >> sy ;
    //vector<pair<ll,ll>> G ;
     pair<ll,ll> p[4] ;
    p[0].first = sx-1 ;
    p[0].second= sy ;
    p[1].first = sx ;
    p[1].second= sy-1 ;
    p[2].first = sx+1 ;
    p[2].second= sy ;
    p[3].first = sx ;
    p[3].second= sy+1 ;
    ll c[4] = { 0 , 0 , 0 , 0 };
    for( ll i=0 ; i<n; i++)
    {
        cin >> x >> y ;
        
        if ( x <= p[0].first )  c[0] ++ ;
        if ( y <= p[1].second ) c[1] ++ ;
        if ( x >= p[2].first)    c[2] ++ ;
        if ( y >= p[3].second) c[3] ++ ;
        
        
        //G.push_back(pair<int,int>(x,y));
    }
   
   /* for ( auto it = G.begin() ; it!=G.end() ;++it )
    {
        
    }*/
    int z = max ( c , 4 ) ;
    cout << c[z] << "\n" ;
    cout << p[z].first << " " << p[z].second << "\n" ; 
    return 0 ;
}
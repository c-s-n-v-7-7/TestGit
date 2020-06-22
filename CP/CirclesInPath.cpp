#include<iostream>
#include<map>
#include<utility>

using namespace std ;

map<int,int> Matrix ;
map<int,int> Circles ;

double distance ( int x , int y )
{
    for ( auto it = Circles.begin() ; it!=Circles.end() ; ++it )
    {
        if ( (x - it->first)**2 + (it->second - y )**2 <= r**2 )  return 1 ;
    }
    return 0 ;
}

int main()
{
    int n,flag=0,m,k,r ;
    cin >> n >> m >> k >> r ;
    int x , y ;
    for ( int i=0 ; i<k ; i++ )
    {
        cin >> x >> y ;
        Circles.insert(pair<int,int>(x,y));
    }
    if ( distance (n,m) || distance(1,1) )   flag = 1 ;
    if (!flag)
    {
    for ( int i=1 ; i<=n ; i++ )
    {
        for ( int j=1; j<=m ; j++ )
       {
           if ( distance(i,j)  ) continue ;
           else   Matrix.insert(pair<int,int>(i,j));
       }
    }   
    }
    else    cout << "No Such Path" ;
    return 0 ;
}
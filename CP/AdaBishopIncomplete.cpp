#include<iostream>
#include<utility>
#include<vector>
using namespace std ;

pair<int,int> se(pair<int,int>(p))
{
    if(1<=p.second+8-p.first<=8)    return (pair<int,int>(8,p.second+8-p.first)) ;
    else    return (pair<int,int>(p.first+8-p.second,8)) ;
}
pair<int,int> nw(pair<int,int>(p))
{
    if(1<=1-p.first+p.second<=8)    return (pair<int,int>(1,1-p.first+p.second)) ;
    else    return (pair<int,int>(p.first+1-p.second,1)) ;
}
pair<int,int> sw(pair<int,int>(p))
{
    if(1<=p.second-8+p.first<=8)    return (pair<int,int>(8,p.second-8+p.first)) ;
    else    return (pair<int,int>(p.first+p.second-1,1)) ;
}
pair<int,int> ne(pair<int,int>(p))
{
    if(1<=-1+p.first+p.second<=8)    return (pair<int,int>(1,-1+p.first+p.second)) ;
    else    return (pair<int,int>(p.first-8+p.second,8)) ;
}
int main()
{
    int t ;
    cin >> t ;
        while(t--)
        {
            int r , c ;
            cin >> r >> c ;
            pair<int,int> p ;
            p.first = r ;
            p.second = c ; 
            vector<pair<int,int>> mov ;
            int x=4 , y=4 ;
              pair<int,int> u , d ;
            while(x>=1&&y<=8)
            {
                mov.push_back(pair<int,int>(x,y)) ;
                d = sw(*mov.rbegin()) ;
                u = ne(*mov.rbegin()) ;
                mov.push_back(d) ;
                mov.push_back(u) ;
                mov.push_back(pair<int,int>(x,y)) ;
                x-- ;
                y++ ;
            }
            x=7 ; y=0 ;
            while(x>4&&y<=8)
            {
                mov.push_back(pair<int,int>(x,y)) ;
                d = sw(*mov.rbegin()) ;
                u = ne(*mov.rbegin()) ;
                mov.push_back(d) ;
                mov.push_back(u) ;
                mov.push_back(pair<int,int>(x,y)) ;
                x-- ;
                y++ ;
            }
            cout << mov.size() << "\n" ;
            
            for ( auto it = mov.begin() ; it!=mov.end() ; ++it )
            {
                cout << it->first << " " << it->second << "\n" ; 
            }
        }
    return 0 ;
}
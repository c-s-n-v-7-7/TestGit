#include<iostream>
#include<map>
#include<utility>
#include<vector>
using namespace std ;

int G[1001][1001] ;

int main()
{
    int t ;
    cin >> t ;
    int x , y ;
    while(t--)
    {
        int n ;
        cin >> n ;
    multimap<int,int> G ;
    int flag = 0 ;
        for ( i=0 ; i<n ; i++ )
        {
                cin >> x >> y ;
                G.insert(pair<int,int>(y,x)) ;
        }
        map<int,int>::iterator j ;
        vector<char> v ;
        for ( auto it = G.begin() ; it!= G.end() ; ++it )
        {
            j = advance(it,1) ;
            if ( j == G.end() ) break ;
                    if ( j->first > it->first )
                    {
                    int diff = j->first-it->first ;
                        while(diff--)
                        {
                            v.push_back('U') ;
                        }
                    } 
                    if ( j->second > it->second )
                        {   
                            int diff = j->second-it->second ;
                            while ( diff-- )
                            {
                                v.push_back('R') ;
                            }
                        }
            else    {   flag = 1 ; break ; }
        }
        if (!flag) 
        {
            cout << "YES\n" ;
            for ( auto it=v.begin() ; it!=v.end() ; ++it )
            cout << *it ;
            cout << "\n" ;
        }
        else    cout << "NO\n" ;
    }
    return 0 ;
}
#include<iostream>
#include<set>
#define ll long long int
using namespace std ;

int main()
{
        int t ;
        cin >>  t;
        while(t--)
        {
            long int n , m ;
            cin >> n >> m ;
           set<long int> posx , posy ;
           set<int,greater<int>> negx , negy ;
            int pos ;
            long int k ;
            for ( int i=0 ; i<n ; i++ )
            {
                cin >> pos ;
                if(pos>0) posx.insert(pos) ;
                else    negx.insert(-pos) ;
            }
            for ( int i=0 ; i<m ; i++ )
            {
                cin >> pos ;
                if (pos>0)  posy.insert(pos) ;
                if (pos<0)  negy.insert(-pos) ;
            }
            ll c = 0 ;
            for ( auto it=posx.begin() ; it!=posx.end() ; ++it )
            {
                for ( auto j=posy.begin() ; j!=posy.end() ; ++j )
                {
                      if ( ((*it)*(*it))%(*j) == 0 )
                    {
                     k = ((*it)*(*it))/(*j) ;
                    if (negy.find(k)!=negy.end())   c++ ;
                    } 
                }
            }
            for ( auto it=negx.begin() ; it!=negx.end() ; ++it )
            {
                for ( auto j=posy.begin() ; j!=posy.end() ; ++j )
                {
                      if ( ((*it)*(*it))%(*j) == 0 )
                    {
                     k = ((*it)*(*it))/(*j) ;
                    if (negy.find(k)!=negy.end())   c++ ; 
                    }
                }
            }
            for ( auto it=posy.begin() ; it!=posy.end() ; ++it )
            {
                for ( auto j=posx.begin() ; j!=posx.end() ; ++j )
                {
                    if ( ((*it)*(*it))%(*j) == 0 )
                    {
                        k = ((*it)*(*it))/(*j) ;
                    if (negx.find(k)!=negx.end()) c++ ; 
                    }
                }
            }
            for ( auto it=negy.begin() ; it!=negy.end() ; ++it )
            {
                for ( auto j=posx.begin() ; j!=posx.end() ; ++j )
                {
                      if ( ((*it)*(*it))%(*j) == 0 )
                    {
                       k = ((*it)*(*it))/(*j) ;
                    if (negx.find(k)!=negx.end())   c++ ;
                    } 
                }
            }
            negx.clear() ;
            negy.clear() ;
            posx.clear() ;
            posy.clear() ;
            cout << c << "\n" ;
        }
    return 0 ;
}
#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std ;

vector<vector<int>> money_vals ;

void permute( vector<int> m )
{
    vector<int> :: iterator i1 , i2 ;
    i1 = m.begin() ;
    i2 = m.end() ;
     do {
        money_vals.push_back(m) ;
    }   while( next_permutation ( i1 , i2 ) ) ;

}


int main()
{
    
            vector<int> mon ;
            for ( int i=0 ; i<4 ; i++ )
            {
                mon.push_back((i+1)*25) ;
            }
            permute ( mon );
    int t ;
    cin >> t ;
        while(t--)
        {
            int n ; 
            cin >> n ;
                    
                      //  enum ch ;
                        char ch ;
                        int g ;
                        int mat[4][4] = {{0},{0},{0},{0}} ;
                for ( int i=0 ; i<n ; i++ )
                {
                    cin >> ch >> g ;
                    mat[ch-65][(g/3)%4] ++ ;
                }

            
/*                
            mon[w] = 100 ;
            mon[x] = 75 ;
            mon[y] = 50 ;
            mon[z] = 25 ;
          
*/      
  int max_prof = -450 ;
set<int> tra ;
            int prof ;
                for ( int i=0 ; i<4 ; i++ )
                {
                    for ( int j=0 ; j<4 ; j++ )
                    {
                        for ( int k=0 ; k<4 ; k++ )
                        {
                            for ( int l=0 ; l<4 ; l++ )
                            {
                                tra.insert(i) ; tra.insert(j) ; tra.insert(k) ; tra.insert(l) ;
                                       for ( vector<int> v : money_vals )
                                       {
                                           prof = 0 ;
                                            prof += mat[i][0]*mon[(v[i])] + mat[j][1]*mon[(v[j])] + mat[k][2]*mon[(v[k])] + mat[l][3]*mon[(v[l])] ;
                                            prof -= (4-tra.size())*100 ;
                                        if ( prof > max_prof )
                                        {
                                            max_prof = prof ;
                                        }
                                      }
                                tra.clear() ;      
                            }
                        }
                    }
                }    
            
            cout << max_prof << " " ;
        }
    return 0 ;
}
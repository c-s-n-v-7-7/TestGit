#include<bits/stdc++.h>
using namespace std ;

int main()
{
    string s ;
    cin >> s ;
        int q ;
        cin >> q ;
        vector<int> a; 
        a[26] = {0} ;
        int count[s.size()][26] ;
        for ( int i=0 ; i<s.size() ; i++ )
        {
            a[s[i]-97]++ ; 
            for ( int j= 0 ; j<26 ; j++ )   count[i][j] = a[j] ;
        }
        map<int,int> m ;
     while(q--)
     {
         int a ;
         cin >> a ;
         if (a==1)
         {
             int pos ;
             char x ;
             cin >> pos >> x ;
             m.insert(pair<int,int>(pos-1,(int)(x-97))) ;
         }
         if (a==2)
         {
             int l , r ;
             int c[26] ;
             
             for ( int i=0 ; i<26 ; i++ )
             {
                 c[i] = count[r-1][i] ;
                 if(l>1)
                    c[i]  -= count[l-2][i] ;
             }
             for ( auto it = m.lower_bound(l-1) ; it->first < r ; ++it )
             {
                 c[s[it->first]-97]-- ;
                 c[it->second-97]++ ;
             }
             int cnt = 0 ;
             for ( int i=0 ; i<26 ; i++ )
             {
                 if(c[i]!=0) cnt ++ ;    
             }
             cout << cnt << "\n" ;
         }
     }
    return 0 ;
}
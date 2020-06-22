#include<bits.stdc++.h>
#include<vector>
#include<algorithm>
using namespace std ;

char* max ( char* a , char* b )
{
    for ( int i=0 ; a[i]!='\0' ; i++ )
    {
        if ( b[i] == '\0')  return a ;
    }
    return b ;
}

int max ( int a , int b )   {   return (a>b)? a:b ; }
int common[101][101] ;
/*int LCSlength ( string s1 , string s2 , int l1 , int l2 )
{
    if ( l2<0 || l1<0 ) return 0 ;
    if ( common[l1][l2] == -1)
    {
        if ( s1[l1-1]==s2[l2-1] )   return 1+LCS(s1,s2,l1-1,l2-1) ;
        else    return max ( LCS(s1,s2,l1-1,l2) , LCS(s1,s2,l1,l2-1) ) ;
    }
    else    return common[l1][l2] ;
} */
vector<vector<char>> v[101][101] ;
vector<char*> LCS ( char* s1 , char* s2 , int l1 , int l2 ) 
{
    if(s1[l1-1] == s2[l2-1] ) 
    {
      v[l1][l2].push_back(s1[l1-1]);   
        v[l1][l2].push_back(LCS(s1,s2,l1-1,l2-1)) 
    }
    else
    {
        v[l1][l2].push_back( max ( LCS(s1 , s2 , l1-1, l2) , LCS(s1,s2,l1,l2-1) ) ) ;
    }
   return v[l1][l2] ; 
}
int main()
{
    stirng s1 , s2 ;
    cin >>s1 ;
    cin >> s2 ;
    for ( int i=0 ; i<=n ; i++ )
    {
        for ( int j=0 ; j<=n ; j++ )
        {
            common[i][j] = -1 ;
        }
    }

    int l1 = s1.length() ;
    int l2 = s2.length() ;
    cout << LCS( s1 , s2 , l1 , l2 ) ;
    //cout<<LCSlength( s1 , s2 , l1 , l2 ) ;
    
    return 0 ;
}
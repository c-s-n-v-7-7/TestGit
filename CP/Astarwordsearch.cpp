#include<iostream>
#include<set>
//#include<queue>
#define max 1000000 
using namespace std;

set<string> words ;

int visited[101] ;
int min ( int a , int b )
{
    return (a<b)?a:b ;
}
int distance ( set<string>::iterator i1 , set<string>::iterator i2 )
{
    int d=0 ;
    for ( int i=0 ; *i1[i]!='\0' ; i++ )
    {
        if ( *i1[i] !=*i2[i] )  d ++ ;
    }
return d ;
}

int SmallestLadder( set<string>::iterator i1 , set<string>::iterator i2 , steps=0 )
{
    i1 == i2  return steps ;
    int s = max ; 
    for ( auto it =words.begin() ; it!=words.end() ; ++it )
    {
        if ( distance(it,i1) == 1 )
        {
            if ( distance(i1,i2) <= distance(it,i2) )   s = min ( s , SmallestLadder( it , i2 , steps+1) ) ; 
        }  
    }
return s ;
}
int main()
{
    int n ;
    cin >> n ;
    for ( int i=0 ; i<n ; i++ )
    {
        string s ;
        cin >> s ;
        words.insert(s) ;
    }
    for ( int i=0 ; i<=n ; i++ ) 
    visited[i] = 0 ;
    cout << "Enter start and target words : " ;
    string s1 , s2 ;
    cin >> s1 >> s2 ;
    set<string>::iterator i1,i2 ;
    i1=words.find(s1) ;
    i2=words.find(s2) ;
    cout << SmallestLadder( i1 , i2 ) ;
    return 0 ;
}
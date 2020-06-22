#include<iostream>
#include<unordered_set>
using namespace std ;

unordered_set<int> areach , breach ;
unordered_set<int>:: iterator it1=areach.begin() , it2=breach.begin() ; 
void abfs( unordered_set<int>::iterator j )
{
    for ( int it : g[*j] )
    {
        if(areach.find(it)==areach.end())
        areach.insert(it) ;
    }
        j++ ;
        if(j!=areach.end()) 
        abfs(j) ;
}
void bbfs( unordered_set<int>::iterator j )
{
    for ( int it : g[*j] )
    {
        if(breach.find(it)==breach.end())
        breach.insert(it) ;
    }
        j++ ;
        if(j!=breach.end()) 
        bbfs(j) ;
}
int main()
{
    /*int t ;
    cin >> t ;
        while(t--)
        {*/
            int n , m , a , b ;
            cin >> n >> m >> a >> b ;
            int x , y ;
                for ( int i=0 ; i<m ; i++ )
                {
                    cin >> x >> y ;
                    g[x].insert(y) ;
                    g[y].insert(x) ;
                }
                areach.insert(a) ;
            abfs(it1) ;
                breach.insert(b) ;
            bbfs(it2) ;
        
        int num = 0 ;
    for ( int i:areach )
    {
        if(breach.find(i)==breach.end()) num ++ ;    
    }
    for ( int i:breach )
    {
        if(breach.find(i)== areach.end() )  num++ ;
    }
    cout << num << "\n" ;
    return 0 ;
}
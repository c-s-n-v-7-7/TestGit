#include<iostream>
#include<vector>
using namespace std ;

int main()
{
    int n ;
    int x , y ;
    vector<int> v ;
    for  (int i=0; i<n ; i++ )
    {
        v.push_back (0) ;
    }
    for ( int i=0 ; i<n-1 ; i++ )
    {
        cin >> x >> y >> c ;
        if ( i==0 ) v[x] = x ;
        if ( c=='L')    v[2*x+1] = y ;
        else   v[2*x+2] = y ;
    }
    int flag= 0  ;
    for ( int i=0 ; i<n ; i++ )
    {
        if ( v[i] !=0 ) 
        {
            if ( v[2*i+1] == 0 && v[2*i+2]!=0 || v[2*i+2]==0&&v[2*i+1]!=0) { cout << "Not Foldable\n" ; flag=1 ; break ; } 
        }
        else    if (!flag)  cout << "Foldable\n" ;
    }
    return 0 ;
}
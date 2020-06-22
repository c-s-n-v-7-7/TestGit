#include<iostream>
#include<utility>
#include<map>
#include<unordered_map>
using namespace std ;

int main()
{
	int t ;
	cin >> t ;
		while(t--)
		{
			int n , m ;
			cin >> n >> m ;
		    unordered_map<int,int> v ;
		    int x ;
		    int a[n] ;
		    for ( int i=0 ; i<n ; i++ )
		    {
		        cin >> a[i] ;
		       
		    }
		    for ( int i=0 ; i<n ; i++ )
		    {
		        cin >> x ;
		        v[a[i]]+=x ;
		    }
		    int minv =100000 ;
		    for ( auto it = v.begin() ; it!=v.end() ; ++it )
		    {
		       
		        if(minv>it->second) 
		        {
		            minv=it->second;
		        }
		    }
		    cout << minv << "\n" ;
		}
	return 0 ;
}

#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_set>
#include<utility>
#define intMAX 200005
#include<queue>
using namespace std ;

unordered_set<int> g[intMAX] ;
unordered_set<int> existing ;
int mod ( int n )
{
	return (n<0)? -n:n ;
}

int main()
{
		int n , m , k ;
		bool flag = 0 ;
		int path_length ;
		cin >> n >> m >> k ;
			int a[k] ;
			unordered_set<int>::iterator i1,i2 ;
			for ( int i=0 ; i<k ; i++ )
			{
			    cin >> a[i] ;
		  	existing.insert(a[i]) ;
			}
			int x , y ;
		  while(m--)
		  {
		  	cin >> x >> y ;
		  		g[x].insert(y) ;
		  		g[y].insert(x) ;
		  		i1=existing.find(x) ;
		  		i2=existing.find(y) ;
		  		    if (i1!=existing.end()&&i2!=existing.end())
		  		    flag = 1 ;
		  }
  
      	int cp[n+1] ;

      		for ( int i=2 ; i<=n ; i++ )	cp[i] = -1 ;
      		cp[0] = 0 ;
      		cp[1] = 0 ;
      	queue<int> cs ;
      		cs.push(1) ;

      		while(!cs.empty())
      		{
      			int p = cs.front() ;
      				cs.pop() ;
      			for ( auto it=g[p].begin() ; it!=g[p].end() ; ++it)
      			{
      				if ( cp[*it] == -1 )
      					{
      						cp[*it] = cp[p]+1 ;
      						cs.push(*it) ;
      					}
      			}
      		}
  		path_length = cp[n] ;
   // cout << "Path = " << path_length ;

        if(!flag)
        {
      		int dp[n+1] ;
      		for ( int i=0 ; i<=n ; i++ )	dp[i] = -1 ;
      		 dp[n] = 0 ;
      	queue<int> ds ;
      		ds.push(n) ;
  
      			while(!ds.empty())
      			{
      				int p = ds.front() ;
      					ds.pop() ;
      				for ( auto it = g[p].begin() ; it!=g[p].end() ; ++it)
      				{
      					if(dp[*it] == -1 )
      						{
      							dp[*it] = dp[p]+1 ;
      								ds.push(*it) ;
      						}
      				}
      			}

      			int astr[k] ;
      for ( int i=0 ; i<k ; i++ )
      {
      		astr[i] = cp[a[i]] + dp[a[i]] ;
      }
      	sort( astr , astr+k ) ;
      
      	int diff = path_length;
        //int diff ;
      	pair<int,int> u = pair<int,int>(0,diff) ;

      for ( int i=0 ; i<k-1 ; i++ )
      {
      		
      			if (diff > astr[i+1] - astr[i]) 
      				{
      					u.first = astr[i] ;
      					u.second = astr[i+1] ;
      				}
      }
        cout << u.first+u.second ;
        }
      if(flag) cout << path_length ;
              
	return 0; 
}

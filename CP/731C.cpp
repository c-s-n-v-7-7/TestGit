#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<utility>
#include<queue>
using namespace std ;

int c[100001] ;
queue<int> sock ;
unordered_set<int> sock_pair[100001] ;

//We need a time stamp for each edge and then we'll vote for color considering each edge and store it in a dp[timeStamp] array then we make the least no. of changes needed

int bfs ( int src )
{
	int frequency[k+1]= {0} ;
	bool visited[k+1] = {0};
		visited[src] = 1 ;
		frequency[c[src]]++ ;
		sock.push(src) ;
		
			while(!sock.empty())
			{
				int l = sock.front() ;
					sock.pop() ;
					for ( auto it = sock_pair[l].begin() ; it!=sock_pair.end() ; ++it )
						{
							if(!visited[*it])	
							{
								sock.push(*it) ;
								visited[*it] = 1 ;
								frequency[c[*it]]++ ;
							}
						}
			}
		int sum = 0 , max = 0 ;
			for ( int i=0 ; i<k ; i++ )
			{
				sum += frequency[i] ;
					if ( max < frequency[i]) max = frequency[i] ;
			}
return sum-max ;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		int n , m , k ;
		cin >> n >> m >> k ;
			//int freq[k]={0} ;
		
			for ( int i=0 ; i<n ; i++ )
				{
					cin >> c[i] ;
			//		freq[c[i]] ++ ;
				}
		
		int i=0 ;
		
		int l , r ;
			unordered_map<int,pair<int,int>> time_stamp ;

			while(i<m)
			{
				cin >> l >> r ;
					pair<int,int> p = (l,r) ;
					time_stamp.insert(i,p) ;
					if ( c[l-1]!=c[r-1] )	
					sock_pair[l].insert(r) ;
					sock_pair[r].insert(l) ;
			}
				bool taken[m]={0} ;
				unordered_map<int,pair<int,int>> :: iterator j ;
				int changes = 0 ;
				for ( int i=0 ; i<m ; i++ )
				{
					if(!taken[m]) 
						{
							j = time_stamp.find(m) ;
								changes += bfs( j->second.first ) ;
						}
				}

	return 0 ;
}
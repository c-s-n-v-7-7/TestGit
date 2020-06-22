#include<bits/stdc++.h>
#define ll long int
using namespace std ;

int max ( int a , int b )
{
	return (a>b)? a:b ;
}

int min ( int a , int b )
{
	return (a<b)? a:b ; 
}

void dfs(vector<ll>&cnt,int ind , vector<ll>&a,int k)
{
	if(cnt[ind]==-1)
	{
		if(a[ind]==0)	cnt[ind]= 0;
		else
		{
			ll var = 0 ;
			for ( int i = max(a[i]-1-k,0) ; i<min(n,a[i]-1+k) ; i++ )
			{
					if ( i== ind )	continue ;
					var += (1+dfs(cnt,i,a,k) ) ;
			}
			cnt[ind] = var ;
		}
	}
return cnt[ind] ;
}

int main()
{
	int t ;
	cin >> t ;
		while(t--)
		{
			ll n , k ;
			cin >> n >> k ;
			vector<ll> a ;
			a = vector<ll> (n) ;
		//	bool vis[n] = {0} ; 
			for ( ll i=0 ; i<n ; i++ )
			{
				cin >> a[i]  ;
			}
			//if(k==1)
			
				vector<ll> cnt ;
				cnt = vector<ll> (n,-1) ;
				for ( int i=0 ; i<n ; i++ )
				{
					if(cnt[i]==-1)
					{
						dfs(cnt,i,a,k) ;
					}
				}
			
			for ( int i=0 ; i<n ; i++ )
			{
				cout << cnt[i] << " " ;
			}
		}
	return 0 ;
}
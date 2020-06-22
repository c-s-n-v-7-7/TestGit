#include<bits/stdc++.h>
#define ll long int
using namespace std ;

int max ( int a , int b )
{
	return (a<b)? b:a ;
}

unordered_set<int> node[200001] ;
int ht[200001] ;

int height ( int par , int cur )
{
	if (ht[cur]==-1)
	{
		int h=0 ;
	for ( int i : node[cur] )
	{
		if(i==par)	continue ;
		h = max ( h , 1+height(cur,i) ) ;
	}
	ht[cur] = h ;
	}
return ht[cur] ;
}

int diameter ( int root )
{
	multiset<int> diffs ;
	for ( int i : node[root] )
	{
		diffs.insert(height(root,i)) ;
	}
	multiset<int>::reverse_iterator rit ;
	rit = diffs.rbegin() ;
	int l1 = *rit ;
	++rit ;
	int l2 = *rit ;

return 1+l1+l2 ;
}

int main()
{
	int n ;
	cin >> n ;
	ll s ;
	cin >> s ;
	map<int,int> fre ;
	int x , y ;
	ht[0] = -1 ;
	ht[1] = -1 ;
	for ( int i=0 ; i<n-1 ; i++ )
	{
		ht[i+2] = -1 ;
		cin >> x >> y ;
		node[x].insert(y) ;
		node[y].insert(x) ;
		fre[x]++ ;
		fre[y]++ ;
	}	
		int root = fre.rbegin()->first ;
	//if (node[root].size()==1)
//	cout  << (float)(s) ;
//	else
	//{
		int d = diameter ( root ) ;
		cout << d << "\n" ;
		for ( int i=0 ; i<=n ; i++ )    cout << ht[i] << " " ;
	//	cout << (float)((float)(s*d)/(float)(n)) ;
//	}
	return 0 ;
}
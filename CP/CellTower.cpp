#include<bits/stdc++.h>
using namespace std ;

vector<int> h ;

int main()
{
	int n ;
	cin >> n ;

	h = vector<int> (n) ;

	for ( int i=0 ; i<n ; i++ )
	{
		cin >> h[i] ;
	}

	vector<int> tower ;
	for ( int i=0 ; i<n ; i++ )
	{
		if(tower.empty()||*tower.rbegin()+7<h[i])	tower.push_back(h[i]+7) ;
	}
	for ( int i : tower )
	{
		cout << i << " " ;
	}
	
	return 0 ;
}
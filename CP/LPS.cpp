#include<bits/stdc++.h>
using namespace std ;

unordered_map<pair<int,int>,string> dp ;

string max ( string a , string b )
{
	return (a>b)? a:b ;
}

string LCS ( string s , string r , int i , int j ) 
{

	if (i<0||j<0)	return "" ; 
	pair<int,int> p ;
	p.first = i ;
	p.second = j ;
	if (dp.find(p)==dp.end())
	{
		string g = max ( LCS(s,r,i-1,j) , LCS(s,r,i,j-1) ) ;
	if (s[i]==s[j])
	{
			g =  max ( s[i] + LCS(s,r,i-1,j-1) , g ) ;
 	}
 		dp.insert(pair<pair<int,int>,string>(p,g)) ;
 	}
return dp[p] ;
}

int main()
{
	string s ;
	cin >> s ;
		// LONGEST PALINDROMIC SUBSEQUENCE 
	string r = reverse (s,s+s.length()) ;

	// We find reverse the string and find the longest common subsequuence in the two strings .

	string t =	LCS ( r , s , r.size()-1 , s.size()-1 ) ;

	cout << t << "\n" ;

	return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

unordered_set<string> pals ;

int max ( int a , int b )
{
	return (a>b)? a:b ;
}

vector<vector<string>> dp ;

string longest ;

string LCS ( string s , string t , int i=0 , int j=0 )
{
	if ( s[i]=='\0'||t[j]=='\0')	return "" ;
	
	if ( s[i] == s[j] )	
	{
		string s1 = s[i] + LCS (s,t,i+1,j+1) ;
		string s2 = LCS ( s , t , i+1 , j ) ;
		string s3 = LCS ( s , t , i , j+1 ) ;
		if ( s1.size() >= s2.size() && s1.size() >= s3.size() )
		dp[i][j] = s1 ;
		if ( s3.size() >= s1.size() && s2.size() >= s1.size() )
		dp[i][j] = s3 ;
		if ( s2.size() >= s1.size() && s2.size() >= s3.size() )
		dp[i][j] = s2 ;
	}
	
	else
	{
		string s1 = LCS ( s , t , i+1 , j ) ;
		string s2 = LCS ( s , t , i , j+1 ) ;
		if ( s1.size() > s2.size() )	dp[i][j] = s1 ;
		else	dp[i][j] = s2 ; 
	}
	
	return dp[i][j] ;
}

int main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		longest = "" ;
		string s ;
		cin >> s;
		dp = vector<vector<string>> (s.size()) ;
		for ( int i=0 ; i<dp.size() ; i++ )
			dp[i] = vector<string> (s.size()) ;
	
	/*	string pre = "" ;
		string suf = "" ; 
		*/
			string r = reverse ( s.begin() , s.end() ) ;
			cout << LCS ( s , r ) ;
	}
	return 0 ;
}
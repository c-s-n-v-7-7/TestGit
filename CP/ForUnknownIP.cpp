#include<iostream>
using namespace std ;

void solve( string s )
{
    for (auto i:s)
    {
        if (i=='.') {cout << "float" ;
        return ;}
        if (i<='9'&&i>='0')
        {
            cout << "int" ;
            return; }
            cout << "string" ;
        }
    }
}

int main()
{
    string s ;
    while(cin>>s)
    {
        solve(s) ; 
        cout << "\n" ;
    }
    return 0 ;
}
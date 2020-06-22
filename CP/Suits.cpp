#include<iostream>
#define ll long long int 
using namespace std;

ll min ( ll a , ll b )
{
    return (a<b)? a:b ;
}

int main()
{
   
        ll e , f , a , b, c , d ;
    cin >> a  ; 
     cin >> b ;
     cin >> c ;
     cin >> d ;
     cin >> e ; 
     cin >> f ;
    ll cost = 0 ;
    int flag = 0 ;
    if ( e > f )
    {
        flag = 1 ;
        if ( a >= d )  {   cost = d*e ; d=0 ;}
        else    {   d =-a ; cost+= a*e ; } 
    }
    else
    {
        flag = 2 ;
        if ( min(b,c) >= d )    {  cost+=d*f ; d=0 ;}
        else    {   d-=min(b,c) ; cost+=min(b,c)*f ;}
    }
    if ( d>0 )
    {
        if (flag==1)    cost+= min(min(b,c),d)*f ;
        if (flag==2)    cost+= min(a,d)*e ; 
    }
    cout<< cost << "\n" ; 
   
    return 0 ;
}

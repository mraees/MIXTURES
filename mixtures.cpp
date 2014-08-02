#include<iostream>
#include<cstdio>
using namespace std;
int mixture[105];
int m[105][105];
    //function to get modulus of a given interval
int module(int a,int b)
{
    	int sum =0;
    	for(int i=a;i<=b;++i)
    	{
    		sum=sum+mixture[i];
    	}
    	return (sum % 100);
}
    //function to get minimum smoke
void getminsmoke(int n)
{
    	int i,j,k,l,q;
    	for(int i=1;i<=n;++i)
    	{
    		m[i][i]=0;
    	}
    	for(l=2;l<=n;++l)
    	{
    		for(i=1;i<=(n-l+1);++i)
    		{
    			j=i+l-1;
    			m[i][j]=-1;
    			for(k=i;k<j;++k)
    			{
    				q=m[i][k]+m[k+1][j]+(module(i,k)*module(k+1,j));
    				if((q<m[i][j]) or (m[i][j]==-1))
    				{
    					m[i][j]=q;
    				}
    			}
    		}
    	}
}
    //main function
int main()
{
    	int n;
    	while(scanf("%d",&n)!=EOF)
    	{
    		for(int i=1;i<=n;++i)
    		{
   			 for(int j=i;j<=n;++j)
  			  {
 				   m[i][j]=0;
  			  }
  		  }
  		  for(int i=1;i<=n;++i)
 		  {
  			  cin>>mixture[i];
  		  }
    		  getminsmoke(n);
    		  cout<<m[1][n]<<"\n";
    	}
return 0;
} 

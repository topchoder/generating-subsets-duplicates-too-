#include <bits/stdc++.h>
using namespace std;

void print(int *b,int n)
{
	for(int i=0;i<n;i++)
		cout<<b[i];
	cout<<"\n";
}
//dont swap if any 2 characters match
int check(int *b,int idx,int to,int n)
{
	for(int i=idx;i<to;i++)
	{
	    if(b[i]==b[to])
	        return 0;
	}
	return 1;
}
//function for generating subsets of given subsequence
void permute(int *b,int size,int idx)
{
        
	if(idx==size)
	{
		print(b,size);
		return;
	}
	for(int i=idx;i<size;i++)
	{
		if(check(b,idx,i,size))
		{
		  swap(b[idx],b[i]);
		  permute(b,size,i+1);
		  swap(b[idx],b[i]);
	  }
	}
}
//for generating  a subsequence
void subseq(int *a,int n,int *b,int b_size,int idx)
{
    
  permute(b,b_size,0);
	for(int i=idx;i<n;i++)
	{
	  b[b_size]=a[i];
		subseq(a,n,b,b_size+1,i+1);
		while(a[i]==a[i+1])//check for unique subsequence keep skipping until adjacent duplicates
		   i++;
	}
}

signed main()
{
    int *a,n;
    cout<<"n?"<<"\n";
    cin>>n;
    a=new int[n];
    for(int i=0;i<n;i++)
    {
    	cout<<"a["<<i<<"]"<<"\n";
    	cin>>a[i];
    }
    int *b=new int[n];
    sort(a,a+n);
    subseq(a,n,b,0,0);
	return 0;
}

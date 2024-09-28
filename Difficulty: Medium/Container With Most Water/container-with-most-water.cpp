//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    long long maxArea=0;
    
    int i=0, j=len-1;
    
    while(i<j)
    {
        int side = min(A[i],A[j]);
        int dist = j-i;
        
        long long area = side*dist;
        
        maxArea = max(maxArea,area);
        
        if(A[i]<A[j])
        {
            i++;
        }
        else if(A[j]<=A[i])
        {
            j--;
        }
    }
    return maxArea;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends
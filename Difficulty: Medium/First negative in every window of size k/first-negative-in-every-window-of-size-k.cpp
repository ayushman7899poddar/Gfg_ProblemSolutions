//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

typedef long long ll;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) 
                                             
{
    vector<ll>vec;
    deque<ll>dq;
    int i=0,j=0;
    
    while(j<N)
    {
        if(A[j] < 0)
        {
            // cout<<"push ele : "<<A[j]<<" ";
            dq.push_back(A[j]);
        }
        
        if(j-i+1 == K)
        {
            if(!dq.empty())
            {
                // cout<<"first neg ele : "<<dq.front()<<" ";
                vec.push_back(dq.front());
            }
            else{
                vec.push_back(0);
            }
            
            // slide the window:
            if(A[i]<0 && !dq.empty())
            {
                // cout<<"poped ele : "<<A[i]<<" ";
                dq.pop_front();
            }
            i++;
        }
        j++;
    }
    return vec;
                                                 
 }
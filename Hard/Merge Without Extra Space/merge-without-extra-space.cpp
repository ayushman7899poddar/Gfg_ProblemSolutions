//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends

#include<vector>
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            vector<int>vec;
          
            
            for(int i=0; i<n; i++)
            {
                vec.push_back(arr1[i]);
               
            }
            for(int i=0; i<m; i++)
            {
                vec.push_back(arr2[i]);
               
            }
            
            sort(vec.begin(),vec.end());
          
            
            
            
            for(int i=0; i<n; i++)
            {
                arr1[i]=vec[i];
            }
            for(int i=n; i<vec.size(); i++)
            {
                arr2[i-n]=vec[i];
            }
        } 
};


//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends
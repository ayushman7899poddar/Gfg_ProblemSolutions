//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void solved(int index, string temp, string s, vector<string>&ans)
	    {
	        if(index>=s.size())
	        {
	            if(temp.size()>0)
	            {
	                ans.push_back(temp);
	            }
	            return;
	        }
	        
	        //exclude:
	        solved(index+1,temp,s,ans);
	        
	        //include:
	        char ch = s[index];
	        temp.push_back(ch);
	        solved(index+1,temp,s,ans);
	        
	    }
		vector<string> AllPossibleStrings(string s)
		{
		    vector<string>ans;
		    int index=0;
		    string temp="";
		    
		    solved(index,temp,s,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
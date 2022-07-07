 
#include <bits/stdc++.h>
using namespace std;
 

class Solution{
public:
    pair<string,int> getOrder(int i,int j,int p[],vector<vector<pair<string,int>>> &dp){
        // Base condition if there is no matrix to multiply
        if(i == j){
            string s = "";
            s += 'A' + i-1;
            return {s,0};
        }
        
        if(dp[i][j].second != -1){
            return dp[i][j];
        }
        
        int mini = INT_MAX;
        string ans = "";
        // find the optimal partition
        for(int k = i; k < j; k++){
            auto fir = getOrder(i,k,p,dp);
            auto sec = getOrder(k+1,j,p,dp);
            string s = "(" + fir.first + sec.first + ")";
            int val = fir.second + sec.second + p[i-1]*p[k]*p[j];
            if(mini > val){
                mini = val;
                ans = s;
            }
        }
        return dp[i][j] = {ans,mini};
    }
    string matrixChainOrder(int p[], int n){
       
        vector<vector<pair<string,int>>> dp(n,vector<pair<string,int>>(n,{"",-1}));
        auto ans = getOrder(1,n-1,p,dp);
        return ans.first;
    }
};
 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  

// Time Complexity  - O(N^3)
// Space Complexity - O(2*(N^2))
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findPath(int i,int j,int n,int m,vector<vector<int>> &grid,vector<int> &v,vector<vector<int>> &ans){
        if(i >= n || j >= m ){
            return;
        }
        if(i == n-1 and j == m-1){
            v.push_back(grid[i][j]);
            ans.push_back(v);
            v.pop_back();
            return;
        }
      
        v.push_back(grid[i][j]);
        findPath(i+1,j,n,m,grid,v,ans);
        findPath(i,j+1,n,m,grid,v,ans);
        v.pop_back();
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        
        vector<int> v;
        vector<vector<int>> ans;
        findPath(0,0,n,m,grid,v,ans);
        return ans;
    }
};

// Time Complexity - O(2^N*M)
// Space Complecity - O(N)
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[]) {
        // Initialize a dynamic programming (DP) array to store the maximum value for each weight.
        vector<int> dp(W + 1, 0);

        // Iterate through each possible weight from 0 to W.
        for (int i = 0; i <= W; i++) {
            // Iterate through each item (N items) to consider adding them to the knapsack.
            for (int j = 0; j < N; j++) {
                // Check if it's possible to add the j-th item without exceeding the current weight limit (i).
                if (i - wt[j] >= 0) {
                    // Update the DP array at weight (i) by choosing the maximum value between the current value
                    // (dp[i]) and the value of adding the j-th item (val[j]) to the maximum value obtained with the
                    // remaining weight (i - wt[j]).
                    dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
                }
            }
        }

        // The final value in the DP array at weight (W) represents the maximum value achievable within the given weight limit.
        return dp[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
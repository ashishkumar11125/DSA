//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
    int isPossible(int N, int arr[])
    {
        int sum = 0; // Initialize a variable to keep track of the sum of remainders.

        for (int i = 0; i < N; i++) 
        {
            while (arr[i] > 0)
            {
                sum += (arr[i] % 10); // Add the last digit of arr[i] to the sum.
                arr[i] /= 10; // Remove the last digit from arr[i].
            }
        }

        if (sum % 3 == 0)
            return true; // If the sum of digits is divisible by 3, return true.
        else 
            return false; // Otherwise, return false.
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
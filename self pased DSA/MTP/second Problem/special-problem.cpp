#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if a bicoloring balances all subsets
bool isBalanced(vector<vector<int>>& subsets, vector<int>& bicoloring) {
    int m = subsets.size(); // number of subsets
    int n = bicoloring.size(); // size of each subset
    
    // Check if each subset is balanced
    for (int i = 0; i < m; i++) {
        int sum_pos = 0, sum_neg = 0;
        for (int j = 0; j < n; j++) {
            if (bicoloring[j] == 1) {
                sum_pos += subsets[i][j];
            } else {
                sum_neg += subsets[i][j];
            }
        }
        if (sum_pos != sum_neg) {
            return false;
        }
    }
    
    // If all subsets are balanced, return true
    return true;
}

// Function to generate all possible bicolorings
vector<vector<int>> generateBicolorings(int n) {
    vector<vector<int>> bicolorings;
    int num_bicolorings = pow(2, n/2);
    for (int i = 0; i < num_bicolorings; i++) {
        vector<int> bicoloring(n);
        for (int j = 0; j < n/2; j++) {
            bicoloring[j] = ((i >> j) & 1) * 2 - 1;
            bicoloring[j+n/2] = ((i >> j) & 1) * 2 - 1;
        }
        bicolorings.push_back(bicoloring);
    }
    return bicolorings;
}

// Main function to find the unique bicoloring that balances all subsets
int main() {
    // Input the subsets
    vector<vector<int>> subsets = {{1, 2, 3, 5, 7, 8}, {2, 6, 7, 8}, {0, 3, 6, 8}};
    int m = subsets.size(); // number of subsets
    int n = subsets[0].size(); // size of each subset
    cout<<"Yes i am";
    // Generate all possible bicolorings
    vector<vector<int>> bicolorings = generateBicolorings(n);
    cout<<bicolorings.size()<<endl;
    // Evaluate each bicoloring and return the unique bicoloring that balances all subsets
    for (int i = 0; i < bicolorings.size(); i++) {
        // if (isBalanced(subsets, bicolorings[i])) {
        //     // Print the first bicoloring that balances all subsets
        // }
            for (int j = 0; j < n; j++) {
                cout << bicolorings[i][j] << " ";
            }
            cout << endl;
            // break;
    }
    
    return 0;
}

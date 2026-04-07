#include <iostream>
#include <vector>
using namespace std;

int n, target;
vector<int> setArr;

// Function to find subsets
void sumOfSubsets(int index, int currentSum, vector<int>& subset) {
    
    // If target achieved
    if (currentSum == target) {
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}" << endl;
        return;
    }

    // If sum exceeds or no elements left
    if (index == n || currentSum > target)
        return;

    // Include current element
    subset.push_back(setArr[index]);
    sumOfSubsets(index + 1, currentSum + setArr[index], subset);

    // Exclude current element
    subset.pop_back();
    sumOfSubsets(index + 1, currentSum, subset);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    setArr.resize(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> setArr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> subset;

    cout << "Subsets with sum " << target << " are:\n";
    sumOfSubsets(0, 0, subset);

    return 0;
}
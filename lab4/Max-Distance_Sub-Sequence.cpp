#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

// Function to check if we can place `C` elements with at least `minDist` distance apart
bool canPlace(const vector<int>& positions, int C, int minDist) {
    int count = 1; // Place the first element
    int lastPosition = positions[0];

    for (int i = 1; i < positions.size(); i++) {
        if (positions[i] - lastPosition >= minDist) {
            count++;
            lastPosition = positions[i];
            if (count == C) {
                return true; // Successfully placed C elements
            }
        }
    }
    return false; // Not possible to place C elements
}

// Function to find the maximum minimum distance
int maxMinDistance(const vector<int>& positions, int C) {
    int left = 0;
    int right = positions.back() - positions.front();
    int bestDist = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlace(positions, C, mid)) {
            bestDist = mid; // Found a valid distance
            left = mid + 1; // Try for a larger distance
        } else {
            right = mid - 1; // Try for a smaller distance
        }
    }
    return bestDist;
}

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N, C;
        cin >> N >> C; // Number of positions and elements to choose
        vector<int> positions(N);

        for (int i = 0; i < N; i++) {
            cin >> positions[i]; // Read positions
        }

        sort(positions.begin(), positions.end()); // Sort positions

        // Find and print the maximum minimum distance
        cout << maxMinDistance(positions, C) << endl;
    }

    return 0;
}
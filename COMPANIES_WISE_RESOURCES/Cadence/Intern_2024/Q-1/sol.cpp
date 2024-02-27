#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

int calculateMaxManhattanDistance(vector<pair<int, int>>& points, int n) {

    int miniSum = points[0].first + points[0].second;
    int maxiSum = miniSum;
    int miniDiff = points[0].first - points[0].second;
    int maxiDiff = miniDiff;
   
    for (int i = 1; i < n; i++) {
        int sum = points[i].first + points[i].second;
        int diff = points[i].first - points[i].second;
        miniSum = min(miniSum, sum);
        maxiSum = max(maxiSum, sum);
        miniDiff = min(miniDiff, diff);
        maxiDiff = max(maxiDiff, diff);
    }
    
    return  max(maxiSum - miniSum, maxiDiff - miniDiff);
}

int main() {
    int n;

    cin >> n;
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    int x=calculateMaxManhattanDistance(points, n);
    cout<<x<<endl;
    return 0;
}
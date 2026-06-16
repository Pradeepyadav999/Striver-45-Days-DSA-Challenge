#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){

        int n = Arrival.size();
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());
        int i = 0;
        int j = 0;
        int platforms = 0;
        int ans = 0;
        while(i < n && j < n){
            if(Arrival[i] <= Departure[j]){
                platforms++;
                ans = max(ans, platforms);
                i++;
            }
            else{
                platforms--;
                j++;
            }
        }
        return ans;
    }
};

int main() {
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;
    cout << "Minimum number of Platforms required "
         << obj.countPlatforms(n, arr, dep) << endl;

    return 0;
}

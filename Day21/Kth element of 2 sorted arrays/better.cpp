class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        vector<int> temp;
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] <= b[j])
                temp.push_back(a[i++]);
            else
                temp.push_back(b[j++]);
        }
        while(i < a.size())
            temp.push_back(a[i++]);
        while(j < b.size())
            temp.push_back(b[j++]);
        return temp[k-1];

    }
};
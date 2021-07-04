#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool Check(int mid , vector<int>& weights , int DATE){
        int n=weights.size();
        int days=1;
        int total=0;
        bool isValid=true;
        for(int i=0;i<n;i++){
            if(weights[i]>mid)
                isValid=false;
            if(total+weights[i]<=mid)
                total+=weights[i];
            else{
                days++;
                total=weights[i];
            }
        }
        if(!isValid)
            return false;
        else
            return (days<=DATE);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=1;
        int r=50000*500;
        while(l<r){
            int mid=(l+r)/2;
            if(Check(mid,weights,days))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};

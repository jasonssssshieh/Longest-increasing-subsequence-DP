#include <iostream>
#include <vector>
using namespace std;

class LongestIncreasingSub{
private:
    vector<int> nums;
public:
    LongestIncreasingSub(vector<int> num){
        nums = num;
    }
    
    int DP(){
        int n = (int)nums.size();
        vector<int> dp(n,1);
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        cout<<"The length of the longest Increasing Subsequence is: " << dp[n-1] <<endl;
        return dp[n-1];
    }
};


int main(int argc, const char * argv[]) {
    vector<int> num = {3,4,-1,0,6,2,3};
    LongestIncreasingSub* test = new LongestIncreasingSub(num);
    test->DP();
    return 0;
}

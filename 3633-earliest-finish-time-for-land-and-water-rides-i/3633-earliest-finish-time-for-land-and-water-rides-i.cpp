class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minTime = INT_MAX;
        int jay=0;

        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < m; ++j) {

                int landS= landStartTime[i];
                int landE = landS + landDuration[i];

                int waterS = max(landE, waterStartTime[j]);
                int f1 = waterS + waterDuration[j];
                
                int waterFirstS = waterStartTime[j];
                int waterE = waterFirstS + waterDuration[j];

                int landSecondS= max(waterE, landStartTime[i]);
                int f2 = landSecondS + landDuration[i];
                
                minTime = min({minTime, f1, f2});
            }
        }

        return minTime;
    }
};

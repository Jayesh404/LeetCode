class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> open(n + 1, 0), close(n + 1, 0);

        for (int i=1;i<=n;i++){
            open[i]=open[i-1]+(customers[i-1]=='N'?1:0);
        }

        for (int i=n-1;i>=0;i--) {
            close[i]=close[i+1]+(customers[i]=='Y'?1:0);
        }
        int minUnwantedCustomers = INT_MAX;
        int bestHour = 0;
        for (int i = 0; i <= n; ++i) {
            int unwantedCustomers = open[i] + close[i];
            if (unwantedCustomers < minUnwantedCustomers) {
                minUnwantedCustomers = unwantedCustomers;
                bestHour = i;
            }
        }

        return bestHour;
    }
};
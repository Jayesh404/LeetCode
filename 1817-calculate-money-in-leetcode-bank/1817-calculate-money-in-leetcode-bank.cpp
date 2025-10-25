class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;

        // sum of full weeks:
        // week1 = 28, week2 = 35, ... → Arithmetic progression
        int fullWeeksSum = weeks * (2 * 28 + (weeks - 1) * 7) / 2;

        // remaining days sum starts from (weeks+1)
        int start = weeks + 1;
        int remainingDaysSum = days * (2 * start + (days - 1)) / 2;

        return fullWeeksSum + remainingDaysSum;
    }
};

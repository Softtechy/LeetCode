class Solution {
public:

    bool canShip(vector<int>& weights, int days, int capacity) {
        int usedDays = 1;
        int currentWeight = 0;

        for (int weight : weights) {

            if (currentWeight + weight > capacity) {
                usedDays++;
                currentWeight = 0;
            }

            currentWeight += weight;

            if (usedDays > days)
                return false;
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());

        int right = 0;
        for (int weight : weights)
            right += weight;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canShip(weights, days, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
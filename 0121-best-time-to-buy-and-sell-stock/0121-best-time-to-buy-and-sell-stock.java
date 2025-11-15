class Solution {
     public static int maxProfit(int[] prices) {
        int minimumPriceSoFar = Integer.MAX_VALUE;
        int profit = 0;
        for (int i = 0; i < prices.length; i++){
            int currentPrice = prices[i];

            if(profit < currentPrice - minimumPriceSoFar){
                profit = currentPrice - minimumPriceSoFar;
            }
            if(currentPrice< minimumPriceSoFar){
                minimumPriceSoFar = currentPrice;
            }
        }

        return profit;
    }
}
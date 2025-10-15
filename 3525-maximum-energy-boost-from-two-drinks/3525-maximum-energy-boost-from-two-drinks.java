class Solution {
    public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
            long maxA = 0;
          long maxB = 0;
        for(int i = 0; i < energyDrinkA.length; i++){
            long tempA = Math.max(maxA + energyDrinkA[i], maxB);
            long tempB = Math.max(maxB + energyDrinkB[i], maxA);
            maxA = tempA;
            maxB = tempB;
        }
        return Math.max(maxA, maxB);
    }
}
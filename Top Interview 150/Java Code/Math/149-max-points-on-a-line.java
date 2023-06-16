class Solution {
    public double calculateSlope(int x1, int y1, int x2, int y2) {
        if (x1 == x2) return Integer.MAX_VALUE;
        if(y1==y2) return 0;
        double slope = (double) (y2 - y1) / (double) (x2 - x1);
        return slope;
    }

    public int maxPoints(int[][] points) {
     int maxi = 0;
        for (int i = 0; i < points.length; i++) {
            Map<Double, Integer> mp = new HashMap<>();
            for (int j = i + 1; j < points.length; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                double slope = calculateSlope(x1, y1, x2, y2);
                mp.put(slope, mp.getOrDefault(slope, 0) + 1);
                maxi = Math.max(maxi, mp.get(slope));
            }
        }
        return maxi + 1;   
    }
}

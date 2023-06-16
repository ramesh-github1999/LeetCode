class Solution {
public:
    double calculateSlope (int x1,int y1,int x2,int y2){
        if(x1==x2) return INT_MAX;
         double slope=(double)(y2-y1)/(double)(x2-x1);
        return slope;
    }
     
    int maxPoints(vector<vector<int>>& points) {
         int maxi=0;
         for(int i=0;i<points.size();i++){
             map<double,int>mp;
             for(int j=i+1;j<points.size();j++){
                     int x1=points[i][0];
                     int y1=points[i][1];
                     int x2=points[j][0];
                     int y2=points[j][1];
                     double slope=calculateSlope(x1,y1,x2,y2);
                     mp[slope]++;
                     maxi=max(maxi,mp[slope]);
             }
         }
        return maxi+1;
    }
};

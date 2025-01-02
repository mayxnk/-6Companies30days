class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size(),cols = img[0].size();
        vector<vector<int>> ans(rows,vector<int>(cols,0));

        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                ans[i][j] = average(img,i,j,rows,cols);
            }
        }
        return ans;
    }
    private:
    int average(const vector<vector<int>>& img,int r,int c,int rows,int cols){
        int sum = 0,count = 0;

        int top = max(0, r-1);
        int bottom = min(rows, r+2);
        int left = max(0, c-1);
        int right = min(cols,c+2);
        for(int i = top;i<bottom;i++){
            for(int j = left;j<right;j++){
                sum += img[i][j];
                ++count;
            }
        }
        return sum/count;
    }
    
};
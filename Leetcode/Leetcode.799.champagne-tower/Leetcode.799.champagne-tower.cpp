class Solution { // Learned from solution
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> currRow(101, 0);
        vector<double> nextRow(101, 0);
        double* curr(currRow.data());
        double* next(nextRow.data());
		curr[0] = poured;
        for(int i=0; i <= query_row; ++i){
            for(int j = 0; j <= i + 1; ++j) {
                next[j] = 0;
            }
            for(int j = 0; j <= i; ++j){
                if(curr[j]>=1){
                    double half((curr[j] - 1) / 2.0);
                    next[j] += half;
                    next[j+1] += half;
                    curr[j] = 1;
                }
            }
            if(i!=query_row) {
                currRow = nextRow;
            }
        }
        return currRow[query_glass];
    }
};
/* TC->O(n*m), SC->O(n*m) 
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(); //rows
        int m = matrix[0].size(); //cols
        // cout<<n<<" "<<m<<endl;
        vector<int> ans;

        int row_st=0; //start of row
        int row_ed=n-1; //end of row
        int col_st=0;
        int col_ed=m-1; 
        int count=0;
        int total=n*m;

        while(count<total){
             //left to right traversal 
            for(int col=col_st; count<total && col<=col_ed; col++){
                // cout<<matrix[row_st][col]<<" ";
                ans.push_back(matrix[row_st][col]);
                count++;
            }
            ++row_st;

            //top to down traversal
            for(int row=row_st; count<total && row<=row_ed; row++){
                // cout<<matrix[row][col_ed]<<" ";
                ans.push_back(matrix[row][col_ed]);
                count++;
            }
            --col_ed;

            //right to left traversal
            for(int col=col_ed; count<total && col>=col_st; col--){
                // cout<<matrix[row_ed][col]<<" ";
                ans.push_back(matrix[row_ed][col]);
                count++;
            }
            --row_ed;

            //down to top traversal
            for(int row=row_ed; count<total && row>=row_st; row--){
                // cout<<matrix[row][col_st]<<" ";
                ans.push_back(matrix[row][col_st]);
                count++;
            }
            ++col_st;
        }
       
        return ans;
    }
};
/* 
    TC-> O(N^3); SC->O(N)
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // cout<<m<<" "<<n<<endl;

        vector<pair<int,int>> pairs;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(matrix[i][j]==0){
                    pairs.push_back({i,j});
                }
            }
        }
        
        cout<<pairs.size()<<endl;
        for(int idx=0; idx<pairs.size(); ++idx){
            int x=pairs[idx].first;
            int y=pairs[idx].second; 

            for(int i=0; i<m; ++i){
                for(int j=0; j<n; ++j){
                    if(i==x || j==y){
                        matrix[i][j]=0;
                    }
                }
            }
           
        }
    }
};

/* approach-2, TC->O(N^2), SC->O(N) */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // cout<<m<<" "<<n<<endl;

        vector<pair<int,int>> pairs;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(matrix[i][j]==0){
                    pairs.push_back({i,j});
                }
            }
        }
        
        // cout<<pairs.size()<<endl;
        for(int idx=0; idx<pairs.size(); ++idx){
            int x=pairs[idx].first;
            int y=pairs[idx].second;
            cout<<x<<" "<<y<<endl;

            //set rows
            for(int i=0; i<m; ++i){
                matrix[i][y]=0;
            }

            //set cols
            for(int i=0; i<n; ++i){
                matrix[x][i]=0;
            }

        }
    }
};
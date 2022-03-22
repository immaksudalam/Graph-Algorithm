//LeetCode: 542. 01 Matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int, pair<int, int>>>q;
        vector<vector<int>>dist(m, vector<int>(n, INT_MAX));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    dist[i][j] =0;
                    q.push({0, {i, j}});
                }
            }
        }
        
        while(!q.empty()){
            int val = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            
            if(x+1 < m && val+1 < dist[x+1][y]){
                dist[x+1][y] = val+1;
                q.push({dist[x+1][y], {x+1, y}});
            }
            if(x-1 >=0 && val+1 < dist[x-1][y]){
                dist[x-1][y] = val+1;
                q.push({val+1, {x-1, y}});
            }
            if(y+1 <n && val+1 < dist[x][y+1]){
                dist[x][y+1] = val+1;
                q.push({val+1, {x, y+1}});
            }
            if(y-1 >=0 && val+1< dist[x][y-1]){
                dist[x][y-1] = val+1;
                q.push({val+1, {x, y-1}});
            }
        }
        return dist;
         
    }
};

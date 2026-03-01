class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        // int m  = grid.size();
        // int n = grid[0].size();
        // vector<int>prev;
        // prev.push_back(0);
        // for(int i = 0;i<m;i++)
        //     {
        //             vector<int>curr;
        //             for(int j =0;j<n;j++)
        //             {
        //                 for(auto it:prev)
        //                     {
        //                         curr.push_back(it | grid[i][j]);
        //                     }
        //             }
        //             sort(curr.begin(),curr.end());
        //             curr.erase(unique(curr.begin(),curr.end()),curr.end());
        //             if(curr.size()>1024)
        //             {
        //                 curr.resize(1024);
        //             }

        //         prev = curr;
        //     }
        // int mini = INT_MAX;
        // for(auto it: prev)
        //     {
        //         mini = min(mini,it);
        //     }
        // return mini;
        auto can=[&](int mask){
            for(auto &row: grid){
                bool ok = false;
                for(int x: row){
                    if((x | mask) == mask){
                        ok = true;
                        break;
                    }
                }
                if(!ok) return false;
            }
            return true;
        };
        int ans = (1<<17) -1;
        for(int i=16;i>=0;i--)
        {
            int mask = ans & ~(1<<i);
            if(can(mask)) ans = mask;
        }
        return ans;
    }
};
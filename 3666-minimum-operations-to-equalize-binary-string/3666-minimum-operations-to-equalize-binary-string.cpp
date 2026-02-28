class Solution {
public:
    int minOperations(string s, int k) {
        // int n = s.length();
        // int zero = 0;

        // for (char c : s)
        //     if (c == '0') zero++;

        // if (zero == 0) return 0;

        // if (n == k) {
        //     if (zero == n) return 1;
        //     if (zero == 0) return 0;
        //     return -1;
        // }

        // int one = n - zero;
        // int base = n - k;

        // int ans = INT_MAX;

        // if ((k % 2) == (zero % 2)) {
        //     long long m = max(
        //         (zero + k - 1) / k,
        //         (one + base - 1) / base
        //     );

        //     if (m % 2 == 0) m++;

        //     ans = min(ans, (int)m);
        // }

        // if (zero % 2 == 0) {
        //     long long m = max(
        //         (zero + k - 1) / k,
        //         (zero + base - 1) / base
        //     );

        //     if (m % 2 == 1) m++;

        //     ans = min(ans, (int)m);
        // }

        // return ans == INT_MAX ? -1 : ans;
        int n = s.length();
        int startZeroes = 0;
        for(char &ch:s)
        {
            if(ch == '0') startZeroes++;
        }
        if(startZeroes == 0) return 0;
        vector<int> operations(n + 1, -1);
        set<int> evenSet;
        set<int> oddSet;
        for(int count = 0; count<=n; count++)
        {
            if(count%2 ==0)
            {
                evenSet.insert(count);
            }
            else
            {
                oddSet.insert(count);
            }
        }
        queue<int>que;
        que.push(startZeroes);
        operations[startZeroes] = 0;
        if(startZeroes%2 == 0)
        {
            evenSet.erase(startZeroes);
        }
        else
        {
            oddSet.erase(startZeroes);
        }

        while(!que.empty())
        {
            int z = que.front();
            que.pop();
            int min_newz = z + k - 2 * min(k,z);
            int max_newz = z + k - 2 * max(0, k-n+z);
            set<int> &currSet = (min_newz%2 == 0) ? evenSet : oddSet;

            auto it  = currSet.lower_bound(min_newz);

            while(it != currSet.end() && *it <= max_newz)
            {
                int newZ = *it;
                if(operations[newZ] == -1)
                {
                    operations[newZ] = operations[z] + 1;
                    if(newZ == 0)
                    {
                        return operations[newZ];
                    }
                    que.push(newZ);
                }
                it = currSet.erase(it);
            }          
        }
        return -1;

    }
};
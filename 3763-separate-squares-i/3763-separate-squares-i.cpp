class Solution {
public:
    double getmin(vector<vector<int>>&squares)
    {
        double mini=squares[0][1];
        for(const auto &square:squares)
        {
            mini=min(mini,square[1]*1.0);
        }
        return mini;
    }
    double getmax(vector<vector<int>>&squares)
    {
        double maxi=squares[0][1]+squares[0][2];
        for(int i=0;i<squares.size();i++)
        {
            maxi=max(maxi,(squares[i][1]+squares[i][2])*1.0);
        }
        return maxi;
    }
    bool lowerhalflarger(vector<vector<int>>&squares,double midy)
    {
        double lowerarea=0,upperarea=0;
        for(const auto &square:squares)
        {
          double bottomy=square[1],side=square[2],topy=bottomy+side;
          if(topy<=midy)
          {
            lowerarea+=side*side;
          }
          else if(bottomy>=midy)
          {
            upperarea+=side*side;
          }
          else
          {
             lowerarea+=(midy-bottomy)*side;
             upperarea+=(topy-midy)*side;
          }
        }
        return lowerarea>=upperarea;   
    }     
    double separateSquares(vector<vector<int>>& squares) {
        double miny=getmin(squares);
        double maxy=getmax(squares);
        double precision=1e-5;
        while(maxy-miny>=precision)
        {
            double midy=(maxy+miny)/2;
            if(lowerhalflarger(squares,midy))
            {
                maxy=midy;
            }
            else
            {
                miny=midy;
            }
        }
        return miny;
    }
};
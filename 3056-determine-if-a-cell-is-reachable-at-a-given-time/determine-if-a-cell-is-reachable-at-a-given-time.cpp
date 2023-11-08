class Solution {
    bool solve(int sx, int sy, int fx, int fy){
        if(fx==sx && fy==sy) return true;
        if(sx<=0  || sy<=0)return false;

          int a = solve(sx-1, sy+1, fx, fy);
          int b = solve(sx, sy+1, fx, fy);
          int c = solve(sx+1, sy+1, fx, fy);
          int  d = solve(sx+1, sy, fx, fy);

          int e = solve(sx+1, sy-1, fx, fy);
          int f = solve(sx, sy-1, fx, fy);
          int g   = solve(sx-1, sy-1, fx, fy);
          int h = solve(sx-1, sy, fx, fy);
          return a|b|c|d|e|f|g|h;

        
    }
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
      if(sx==fx && fy==sy){
          if(t==1) return false;
          return true;
      }
     int dist= max(abs(fy-sy), abs(fx-sx));
       if(dist<=t) return true;
       return false;

    // return solve(sx , sy, fx, fy);
    }
};
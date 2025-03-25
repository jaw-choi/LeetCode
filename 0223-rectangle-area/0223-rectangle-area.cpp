class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int s1 = (ax2-ax1) * (ay2-ay1);
    int s2 = (bx2-bx1) * (by2-by1);
    int area = 0;
    int cx1 = max(ax1,bx1);
    int cy1 = max(ay1,by1);
    int cx2 = min(ax2,bx2);
    int cy2 = min(ay2,by2);
    area = (cx2-cx1) * (cy2 - cy1);
    if(cx1>cx2 || cy1>cy2)
        area = 0;
    return s1+s2-area;    
    }
};
//24
//6
//27
//51
//45
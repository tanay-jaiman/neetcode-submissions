class Solution {
    struct point { int i, j; };
    struct cmp { bool operator() (point& p1, point& p2) { return sqrt(p1.i*p1.i + p1.j*p1.j) > sqrt(p2.i*p2.i + p2.j*p2.j); }};
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<point, vector<point>, cmp> pq;
        vector<vector<int>> ret;
        
        for (auto p : points) {
            point point = {p[0], p[1]};
            pq.push(point);
        }

        while (k > 0) {
            point p = pq.top(); pq.pop();
            ret.push_back({p.i, p.j});
            k--;
        } 

        return ret;
    }
};

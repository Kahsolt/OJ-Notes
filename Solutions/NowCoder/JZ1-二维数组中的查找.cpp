// 2021/07/02
// NOTE: 注意处理 array==[[]] 的傻吊情况

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {        
        for (auto it=array.begin(); it!=array.end(); it++) {
            auto p = it->begin();
            if (p == it->end() || *p > target) return false;
            
            for (; p!=it->end(); p++)
                if (*p == target) return true;
                else if (p == it->end() || *p > target) break; 
        }
        return false;
    }
};
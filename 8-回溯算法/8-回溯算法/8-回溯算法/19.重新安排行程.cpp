#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
private:
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>& result) {
        if (result.size() == ticketNum + 1) return true;

        //对同个出发机场能到达的所有到达机场进行遍历
        //for中拿到的是最后一个机场对应的ma
        //map 中的元素默认情况下是按照键从小到大排序的。因此，如果对一个 map 进行迭代，其元素将按照升序排列
        for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
            if (target.second > 0) {
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;

    }
public:  
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        vector<string> result = { "JFK" };
        for (const auto& ticket : tickets) {
            targets[ticket[0]][ticket[1]]++;
        }
        backtracking(tickets.size(), result);
        return result;
    }
};


int main() {
    vector<vector<string>> tickets = { {"MUC", "LHR"},{"JFK", "MUC"},{"SFO", "SJC"},{"LHR", "SFO"} };

    Solution so;
    vector<string> res = so.findItinerary(tickets);

    for (auto& s : res) {
        cout << s << " ";
    }
    return 0;
}
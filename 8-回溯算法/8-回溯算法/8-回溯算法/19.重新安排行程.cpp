#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
private:
    // unordered_map<��������, map<�������, �������>> targets
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>& result) {
        if (result.size() == ticketNum + 1) return true;

        //��ͬ�����������ܵ�������е���������б���
        //for���õ��������һ��������Ӧ��ma
        //map �е�Ԫ��Ĭ��������ǰ��ռ���С��������ġ���ˣ������һ�� map ���е�������Ԫ�ؽ�������������
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
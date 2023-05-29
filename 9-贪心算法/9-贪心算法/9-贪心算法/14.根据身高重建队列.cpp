#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

/*
�����ڰ�����ߴӴ�С�����
�ֲ����ţ����Ȱ���߸ߵ�people��k�����롣������������people�����������
ȫ�����ţ������������������������������Ŀ��������
*/
// ʹ��C++�е�list���ײ�����ʵ�֣���vector�����飩Ч�ʸߵöࡣ
class Solution {
public:
    // ��ߴӴ�С�ţ������ͬkС��վǰ�棩
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> que; // list�ײ�������ʵ�֣�����Ч�ʱ�vector�ߵĶ�
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1]; // ���뵽�±�Ϊposition��λ��
            std::list<vector<int>>::iterator it = que.begin();
            while (position--) { // Ѱ���ڲ���λ��
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};


int main() {
    vector<vector<int>> people = { {7,0} ,{ 4,4},{7,1},{5,0},{ 6,1},{5,2} };

    Solution so;
    vector<vector<int>> res = so.reconstructQueue(people);

    for (vector<int>& vec : res) {
        for (int& t : vec) {
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}
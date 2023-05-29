#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�ֲ����ţ�ֻҪ�ұ����ֱ���ߴ��ұߵĺ��ӾͶ�һ���ǹ�
//ȫ�����ţ����ڵĺ����У����ָߵ��Һ��ӻ�ñ���ߺ��Ӹ�����ǹ�
//����������̰�ĵĲ��ԣ�
//һ���Ǵ����ұ�����ֻ�Ƚ��ұߺ������ֱ���ߴ�������
//һ���Ǵ��ҵ��������ֻ�Ƚ���ߺ������ֱ��ұߴ�������
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        // ��ǰ���
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        // �Ӻ���ǰ
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        // ͳ�ƽ��
        int result = 0;
        for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
        return result;
    }
};


int main() {
    vector<int> ratings = { 1,0,2 };

    Solution so;
    int res = so.candy(ratings);

    cout << res;
    return 0;
}
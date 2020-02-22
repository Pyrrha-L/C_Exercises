#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
struct Commodity {  //��Ʒ��
    long long id, score;  //id�ͷ���
    Commodity(long long i, long long s) : id(i), score(s) {}
    bool operator<(const Commodity& c) const {  //����С�������
        return this->score != c.score ? this->score > c.score : this->id < c.id;
    }
};
int main() {
    const long long mul = (long long)(1e9);
    int m, n, id, score, op, t, c, k;
    cin >> m >> n;
    vector<int> K(m);  //�洢ÿ����Ʒ��ѡ�е�������
    set<Commodity> commodities;  //��������Ʒ��������
    unordered_map<long long, set<Commodity>::iterator> um;  //�洢��Ʒid�Ͷ�Ӧ��set�еĵ�����
    for (int i = 0; i < n; ++i) {
        cin >> id >> score;
        for (int j = 0; j < m; ++j) {
            long long a = j * mul + id;
            um[a] = commodities.insert(Commodity(a, score)).first;
        }
    }
    cin >> op;
    while (op--) {
        cin >> c;
        if (c == 1) {  //�����Ʒ
            cin >> t >> id >> score;
            long long a = t * mul + id;
            um[a] = commodities.insert(Commodity(a, score)).first;
        } else if (c == 2) {  //ɾ����Ʒ
            cin >> t >> id;
            long long a = t * mul + id;
            commodities.erase(um[a]);
            um.erase(a);
        } else {
            vector<vector<int>> ans(m);
            cin >> k;
            for (int i = 0; i < m; ++i)
                cin >> K[i];
            for (auto& i : commodities) {  //��������set
                t = i.id / mul;
                if (ans[t].size() < K[t]) {
                    ans[t].push_back(i.id % mul);
                    if (--k == 0)  //��Ʒ��ѡ��k������������
                        break;
                }
            }
            for (auto& i : ans)
                if (i.empty()) {  //û��ѡ�е���Ʒ�����-1
                    cout << "-1\n";
                } else {
                    // sort(i.begin(), i.end());//��С��������ע�͵����д������õ����֣���ע�͵�ֻ��60��
                    for (auto j : i)
                        cout << j << " ";
                    cout << "\n";
                }
        }
    }
    return 0;
}


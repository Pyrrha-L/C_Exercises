#include <bits/stdc++.h>
using namespace std;
int main() {
    long long light[3], N, a, b, ans = 0;
    cin >> light[0] >> light[2] >> light[1] >> N;
    long long sum = light[0] + light[1] + light[2];  //sumΪ���̵Ʊ任һ�ܵ���ʱ��
    while (cin >> a >> b)
        if (a == 0)  //�ǵ�·
            ans += b;  //ʱ��ֱ�ӵ���
        else {  //�Ǻ��̵�
            if (a == 1)  //�����̵Ʊ�ű�Ϊlight������±�
                a = 0;
            else if (a == 3)
                a = 1;
            b = (light[a] - b + ans) % sum;  //�ú��̵Ʊ任�����һ�ܵ�ʱ��
            while (b > light[a]) {  //��b�ȵ�ǰ���̵�ʱ����
                b -= light[a];  //��ȥ��ǰ�ĺ��̵�ʱ��
                a = (a + 1) % 3;  //ת����һ�����̵�
            }
            if (a == 0)  //�Ǻ��
                ans += light[a] - b;  //���Ϻ��ʣ��ʱ��
            else if (a == 2)  //�ǻƵ�
                ans += light[a] - b + light[0];  //���ϻƵ�ʣ��ʱ���Լ����ʱ��
		}
    cout << ans;
    return 0;
}


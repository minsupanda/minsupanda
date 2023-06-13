#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s)
{
    int zeros{ 0 }, num_transform{ 0 }; vector<bool> bin;

    for_each(s.cbegin(), s.cend(), [&bin](const char c) {bin.emplace_back(c == '1'); });  //s�� �������� ��ȯ

    // [](){} ���ٽ�
    // emplace_back : ��ü�� ���� ��Ḧ ������ ���� ��ü�� ���� ������ �ִ´�. 
    // push_back : ��ü�� ���� ���� �ִ� ��
    // ��ü��? c++�� Ŭ����(ex. ��Ű Ʋ <-> �ν��Ͻ��� ��Ű)
    // => bin.emplace_back(c == '1') ��, �Ű� ������ ������ c�� 1�϶� bool true�� ����, �� �ܴ� false�� �����ϰ� �ȴ�.

    while (true)
    {
        if (bin == vector<bool>{true}) break;
        // bin�� ��� true�� �� break; (�迭 �ʱ�ȭ �� �� {0} ���� �ϸ� ��� 0���� �ʱ�ȭ �Ǵ� ��)

        int ones = count(bin.cbegin(), bin.cend(), true);    //1������ ��
        // count : algorithm�� �ִ� �Լ� (bin���� ���� ������ ã���鼭 true�� ������ ���� ��)

        zeros += bin.size() - ones;                          //0������ ��
        // bin�� �迭���� 1�� ������ŭ ���� �װ� 0�� ����

        bin.clear();

        while (ones > 0)
        {
            bin.emplace_back(ones % 2);
            ones /= 2;
        }//1������ 2������ �ٲ�. ������ �Ųٷ����� ��꿡�� �������
        ++num_transform;                                   //������ȯ Ƚ�� ���
    }
    return { num_transform,zeros };
}
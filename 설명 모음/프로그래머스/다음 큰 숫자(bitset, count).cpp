#include<iostream>
#include<string>
#include<vector>
#include<bitset>

//void main()
//{
//    int n = 78;
//
//    int num = std::bitset<20>(n).count();
//    // https://www.crocus.co.kr/549
//    // count() : 1�� ������ ���°�?
//    // ������ algorithm�� ���Ե� ���? first ~ end���� val�� ���� ī���� �ϴ� �Լ�
//    while (std::bitset<20>(++n).count() != num);
//    std::cout << n;
//}

//********************************************************************************************************//

int getCntNum1(int n)
{
    int nCnt = 0;
    for (int i = 0; i < 31; i++)
    {
        // 0x01 == 1��
        // �긦 0���� 30���� ��Ʈ����
        // ��, i��ŭ 0x01(1)�� ����Ʈ ����Ʈ �����ڷ� 10, 100 �̷������� �ڸ��� ������Ű�鼭 n�� ������ ���� �� �ڸ��� Ȯ���ϴ� ��
        // & ���� �����ڷ� �� �ڸ��� 1�� �� ī��Ʈ ����
        if (n & 0x01 << i)
            nCnt++;
    }
    return nCnt;
}

int nextBigNumber(int n)
{
    int nNum1Cnt = getCntNum1(n);

    while (1)
    {
        n++;
        if (nNum1Cnt == getCntNum1(n))
            return n;
    }
}

int main()
{
    int n = 832656;

    //�Ʒ��� �׽�Ʈ ����� ���� �ڵ��Դϴ�.
    std::cout << nextBigNumber(n);
}
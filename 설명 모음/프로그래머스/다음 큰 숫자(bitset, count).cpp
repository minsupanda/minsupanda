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
//    // count() : 1의 갯수를 세는거?
//    // 원래는 algorithm에 포함된 기능? first ~ end까지 val의 갯수 카운팅 하는 함수
//    while (std::bitset<20>(++n).count() != num);
//    std::cout << n;
//}

//********************************************************************************************************//

int getCntNum1(int n)
{
    int nCnt = 0;
    for (int i = 0; i < 31; i++)
    {
        // 0x01 == 1임
        // 얘를 0부터 30까지 비트연산
        // 즉, i만큼 0x01(1)을 레프트 시프트 연산자로 10, 100 이런식으로 자릿수 증가시키면서 n의 이진수 값의 각 자리를 확인하는 것
        // & 엔드 연산자로 그 자리가 1일 때 카운트 증가
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

    //아래는 테스트 출력을 위한 코드입니다.
    std::cout << nextBigNumber(n);
}
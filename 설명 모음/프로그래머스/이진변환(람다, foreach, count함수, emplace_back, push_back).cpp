#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s)
{
    int zeros{ 0 }, num_transform{ 0 }; vector<bool> bin;

    for_each(s.cbegin(), s.cend(), [&bin](const char c) {bin.emplace_back(c == '1'); });  //s를 이진수로 변환

    // [](){} 람다식
    // emplace_back : 객체를 만들 재료를 넣으면 직접 객체를 만들어서 가지고 있는다. 
    // push_back : 객체를 직접 집어 넣는 것
    // 객체란? c++의 클래스(ex. 쿠키 틀 <-> 인스턴스는 쿠키)
    // => bin.emplace_back(c == '1') 즉, 매개 변수로 들어오는 c가 1일때 bool true를 저장, 그 외는 false를 저장하게 된다.

    while (true)
    {
        if (bin == vector<bool>{true}) break;
        // bin이 모두 true일 때 break; (배열 초기화 할 때 {0} 으로 하면 모두 0으로 초기화 되는 것)

        int ones = count(bin.cbegin(), bin.cend(), true);    //1갯수를 셈
        // count : algorithm에 있는 함수 (bin시작 부터 끝까지 찾으면서 true의 갯수를 세는 것)

        zeros += bin.size() - ones;                          //0갯수를 셈
        // bin의 배열에서 1의 갯수만큼 빼면 그게 0의 갯수

        bin.clear();

        while (ones > 0)
        {
            bin.emplace_back(ones % 2);
            ones /= 2;
        }//1갯수를 2진수로 바꿈. 순서는 거꾸로지만 계산에는 영향없음
        ++num_transform;                                   //이진변환 횟수 기록
    }
    return { num_transform,zeros };
}
#include<iostream>
//.h : c++은 붇지않는다. 
// c++에서도 c언어를 사용할수 있는데 이떄 .h를 붙이지 않아서 뜨는 오류는 c언어 문법이라고 생각하면 된다.
void main()
{ //cout [씨아웃] : printf와 동일한 기능 
	std::cout << "Hello" << printf("\n");
	std::cout << "World" << std::endl;
	//endline : c언어의 \n과 동일한 기능
	//c언어는 저수준언어라 c++보다 더 빠르게 작동할 수 있다. -> 언어측에서 고려해야할 부분이 적기때문에
}
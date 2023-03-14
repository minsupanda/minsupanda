#include<stdio.h>

void While(int n)
{
	printf("%d\n", n);
	if (n <= 0)
		return;
	else
		While(n - 1);
	//여기서 9를 가지고 갈때 While(10)함수는 여기서 잠시 멈춰있는 것이고 메모리가 그대로 남아있다
	//그렇게 쭉가다가 return할때 해당함수를 호출함 시점으로 되돌아가면서 남은 메모리들을 회수하는 형식으로 다시 되돌아간다
	printf("%d\n", n);
}
void main()
{
	While(10);

	return;
}
//Zadanie Plakatowanie
//Mateusz Grzelak


#include <iostream>
#include <stack>
const int MAX1 = 250000;
const int MAX2 = 1000000000;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int len, height, num;
	int posters = 0;
	stack<int> stack;

	cin >> num;
	if (num == 0 || num>MAX1) { return 0;}

	for (int i = 0; i < num; i++)
	{
		cin >> len;
		cin >> height;
		while (!stack.empty() && stack.top() > height) // redundant
			stack.pop();
		if (stack.empty() || stack.top() < height) 
		{
			stack.push(height);    // not redundant 
			posters++;
		}
	}
	cout << posters;
}
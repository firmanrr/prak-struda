//Program HEAP MIN

#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue <int, vector<int>, greater<int>> gq)
{
	priority_queue <int, vector<int>, greater<int>> g = gq;
	while (!g.empty())
	{
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

int main ()
{

	priority_queue <int, vector<int>, greater<int>> gquiz;
	gquiz.push(45);
	gquiz.push(20);
	gquiz.push(14);
	gquiz.push(12);
	gquiz.push(31);
	gquiz.push(7);
	gquiz.push(11);
	gquiz.push(13);
	gquiz.push(7);
	
	cout << "The priority queue gquiz is : ";
	showpq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.top()  : " << gquiz.top();

	cout << "\ngquiz.pop()  : ";
	gquiz.pop();
	showpq(gquiz);

	cout << endl;
	system("pause");
	return 0;
}

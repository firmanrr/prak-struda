//Program HEAP MAX

#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue <int> gq)
{
	priority_queue <int> g = gq;
	while (!g.empty())
	{
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

int main ()
{


	priority_queue <int> gquiz;
	gquiz.push(14);
	gquiz.push(6);
	gquiz.push(99);
	gquiz.push(25);
	gquiz.push(100);

	cout << "push pertama = 14"<<endl;
	cout << "push kedua   = 14 6"<<endl;
	cout << "push ketiga  = 99 14 6"<<endl;
	cout << "push keempat = 99 25 14 6"<<endl;
	cout << "push terakhir=   100 99 25 14 6"<<endl;

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.top()  : " << gquiz.top();
	
	cout << "\ngquiz.pop()  : ";
	gquiz.pop();
	showpq(gquiz);
	cout << "\ngquiz.pop()  : ";
	gquiz.pop();
	showpq(gquiz);
	cout << "\ngquiz.pop()  : ";
	gquiz.pop();
	showpq(gquiz);
	cout << "\ngquiz.pop()  : ";
	gquiz.pop();
	showpq(gquiz);
	
	cout << endl;
	system("pause");
	return 0;
}

/*
	Queue using Stack
*/
#include <bits/stdc++.h>
using namespace std;
void display(stack<int> &q1, stack<int> &q2)
{
	cout << "\nQueue --> ";
	int x,size = q1.size();
	vector<int> v;
	for(int i = 0; i < size; ++i)
	{
		x = q1.top();
		v.push_back(x);
		q1.pop();
		q2.push(x);
	}
	for(int i = v.size()-1; i >= 0; --i)
	{
		cout << v[i] << " ";
	}
	int size1 = q2.size();
	for(int i = 0; i < size1; ++i)
	{
		x = q2.top();
		q2.pop();
		q1.push(x);
	}
	cout << "\n";
}
void remove(stack<int> &q1, stack<int> &q2)
{
    int size = q1.size();
    for(int i = 0; i < size-1; ++i)
    {
        int x = q1.top();
    	q2.push(x);
        q1.pop();
    }
    q1.pop();
    int size1 = q2.size();
    for(int i = 0; i < size1; ++i)
    {
        int x = q2.top();
        q1.push(x);
        q2.pop();
    	}
}
int main()
{
	stack<int> q1,q2;
	while(true)
	{
		int i;
		cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n\n";
		cin >> i;
		if(q1.size() == 0 && i == 2)
		{
			cout << "\nSize of queue is 0\n\n";
			continue;
		}
		else if(q1.size() == 0 && i == 3)
		{
			cout << "\nSize of queue is 0\n\n";
			continue;
		}
		if(i == 1)
		{
			int n;
			cout << "\nEnter the number:\n";
			cin >> n;
			q1.push(n);
		}
		else if(i == 2)
	    {
			remove(q1,q2);
		}
		else if(i == 3)
		{
			display(q1,q2);
		}
		else
		{
			return 0;
		}
		cout << "\n";
	}
}
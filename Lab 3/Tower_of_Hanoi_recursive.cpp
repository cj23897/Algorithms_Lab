/*
										Tower of Hanoi(Recursive)
	---------------------------------------------idea----------------------------------------------------
	The basic idea is that we know that when there is only one ring then we can simply transfer it.
	So, we'll transfer n-1 rings from source to auxiliary rod and then nth ring from source to destination
	rod and then again n-1 from auxiliary to destination rod.
	This is basically a divide and conqour algorithm.
	-----------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
stack<int> arr[3];
int steps = 0;
void display()
{
	for(int j = 0; j < 3; ++j)
	{
		stack<int> q2;
		cout << "Tower " << j+1 << "-> ";
		int x,size = arr[j].size();
		if(size > -1)
		{
			vector<int> v;
		for(int i = 0; i < size; ++i)
		{
			x = arr[j].top();
			v.push_back(x);
			arr[j].pop();
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
			arr[j].push(x);
		}
		cout << "\n";
		}
	}
	cout << "\n";
}
void solve(int size, int source, int auxiliary, int destination)
{
	if(size > 0)
	{
		solve(size-1,source,destination,auxiliary);
		int x = arr[source].top();
		arr[source].pop();
		arr[destination].push(x);
		steps++;
		display();
		solve(size-1,auxiliary,source,destination);
	}
}
int main()
{
	int size;
	cout << "Enter the size of the tower: ";
	cin >> size;
	for(int i = size; i > 0; --i)
	{
		arr[0].push(i);
	}
	display();
	solve(size,0,1,2);
	cout << "Number of steps: " << steps << "\n";
}
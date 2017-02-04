/*
						Tower of Hanoi(Iterative)
----------------------------------idea------------------------------------
The basic idea is the same as that in the recursive version of the problem.
However, here the algorithm changes:-
1. Calculate the total number of moves required i.e. "pow(2, n)- 1" 
	here n is number of disks.
2. If number of disks (i.e. n) is even then interchange destination 
   pole and auxiliary pole.
3. for i = 1 to total number of moves:
     if i%3 == 1:
	legal movement of top disk between source pole and 
        destination pole
     if i%3 == 2:
	legal movement top disk between source pole and 
        auxiliary pole	
     if i%3 == 0:
        legal movement top disk between auxiliary pole 
        and destination pole 
-------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
stack<int> arr[3];
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
void move(stack<int> &a, stack<int> &b)
{
	int x = a.top();
	a.pop();
	b.push(x);
}
void move_between_pegs(int count, stack<int> &a, stack<int> &b)
{
	if(a.size() == 0)
	{
		move(b,a);
	}
	else if(b.size() == 0)
	{
		move(a,b);
	}
	else if(a.top() > b.top())
	{	
		move(b,a);
	}	
	else
	{
		move(a,b);
	}
}
int main()
{
	int n;
	cout << "Enter the number of disks: ";
	cin >> n;
	for(int i = n; i >= 1; --i)
	{
		arr[0].push(i);
	}
	display();
	int max = pow(2,n)-1, step, count = 0;
	if(n%2 == 0)
	{
		for(int i = 1; i <= max; ++i)
		{
			count++;
			step = (i%3);
			cout << "Step: " << i << "\n\n";
			switch(step)
			{
				case 1:
					move_between_pegs(count,arr[0],arr[1]);
					break;
				case 2:
					move_between_pegs(count,arr[0],arr[2]);
					break;
				case 0:
					move_between_pegs(count,arr[2],arr[1]);
			}
			display();
		}
	}
	else
	{
		for(int i = 1; i <= max; ++i)
		{
			count++;
			step = (i%3);
			cout << "Step: " << i << "\n\n";
			switch(step)
			{
				case 1:
					move_between_pegs(count,arr[0],arr[2]);
					break;
				case 2:
					move_between_pegs(count,arr[0],arr[1]);
					break;
				case 0:
					move_between_pegs(count,arr[2],arr[1]);
			}
			display();
		}
	}
}
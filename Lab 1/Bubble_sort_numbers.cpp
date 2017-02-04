/*
	c++ program for bubble sort.
*/
#include <bits/stdc++.h>
#include <ctime>
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 1e9 + 7
#define ull unsigned long long
#define iloop(a,b) for(ll i = a; i < b; ++i)
#define jloop(a,b) for(ll j = a; j < b; ++j)
using namespace std;
void bubble_sort(vector<int> vec, int size)
{
	iloop(0,size)
	{
		jloop(1,size-i)
		{
			if(vec[j-1] > vec[j])
			{
				int temp = vec[j-1];
				vec[j-1] = vec[j];
				vec[j] = temp; 
			}
		}
	}
}
int main()
{
	bool testing = true;
	/*std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	if(testing)
	{
		freopen("numbers.dat","rt",stdin);
	}
	vector<int> vec;
	int n;
	for(int i = 0; i < 800; ++i)
	{
		cin >> n;
		vec.pb(n);
	//	cout << n << "\n";
	}
	int start = clock();
	bubble_sort(vec, vec.size());
	int end = clock();
	cout << "time: " << (end - start)/(double)(CLOCKS_PER_SEC)*1000 << " milliseconds\n";
}

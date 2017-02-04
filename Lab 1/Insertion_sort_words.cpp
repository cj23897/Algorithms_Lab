/*
c++ program for insertion sort of words lexographically.
Put all the words in a words.dat file and save it in the 
same location as that of this program.
*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 1e9 + 7
#define ull unsigned long long
#define iloop(a,b) for(ll i = a; i < b; ++i)
#define jloop(a,b) for(ll j = a; j < b; ++j)
using namespace std;
void insertion_sort(vector<string> arr, int n)
{
	iloop(1,n)
	{
		int temp = i;
		while(temp > 0 && arr[temp] <= arr[temp-1])
		{
			string t = arr[temp];
			arr[temp] = arr[temp-1];
			arr[temp-1] = t;
			--temp;
		}
	}
}
void solve()
{
	vector<string> vec;
	int n = 800;
	string x;
	for(int i = 0; i < n; ++i)
	{
		cin >> x;
		//cout << n << "\n";
		vec.pb(x);
	}
	int start = clock();
	insertion_sort(vec,n);
	int end = clock();
	cout << "time: " << (end - start)/(double)(CLOCKS_PER_SEC)*1000 << " milliseconds\n";
}
int main()
{
	bool testing = true;
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	if(testing)
	{
		freopen("words.dat","rt",stdin);
	}
	solve();
}

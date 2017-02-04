/*
c++ program for selection sort of words lexograhically.
Put all the words in a words.dat file and save it in the 
same directory as that of this program.
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
void selection_sort(vector<string> vec, int n)
{
	int min;
	iloop(0,n-1)
	{
		min = i;
		jloop(i+1,n)
		{
			if(vec[j] < vec[min])
			{
				min = j;
			}
		}
		string temp = vec[i];
		vec[i] = vec[min];
		vec[min] = temp;
	}
}
void solve()
{
	vector<string> vec;
	int n = 800;
	string s;
	for(int i = 0; i < n; ++i)
	{
		cin >> s;
		vec.pb(s);
	}
	int start = clock();
	selection_sort(vec,n);
	int end = clock();
	cout << "time: " << (end - start)/(double)(CLOCKS_PER_SEC)*1000 << " milliseconds\n";
}
int main()
{
	bool testing = true;
	/*std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	if(testing)
	{
		freopen("words.dat","rt",stdin);
	}
	solve();
}

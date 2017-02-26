/*
	c++ program for hash table using Quadratic Probing
*/
#include <bits/stdc++.h> 
using namespace std;
//A large prime number
int n = 1201;
//Array of strings to store words
string s[1200];
//function to calculate hash values(key) of words.
int hash(string str)
{
	int ans = 0;
	for(int i = 0; i < str.length(); ++i)
	{
		ans += ((int)str[i])*(i+1);
	}
	//To keep the key within the array index
	return (ans%ans+3*ans+1)%n;
}
/*This function deals with the case when there is already a word at the key, so it uses 
Quadratic probing to calculate the next index to store the word. It only iterate over the
array one time. For eg. Suppose there is already a word at the key then we'll traverse
from key + 1 to key - 1 positions in a loop.
*/
void update(int key, string str)
{
	//temp keeps the index(key) where we can store the word
	int temp = key;
	temp = (key*key + 3*key + 1)%n;
	//length variable is used to traverse the array only once.
	int length = 1200;
	int i = 0;
	do
	{
		//If there is no word then insert the word there
		if(s[temp] == "")
		{
			s[temp] = str;
			break;
		}
		//else use quadratic probing to calculate the next index or next key.
		else
		{
			temp = (key + (i+1)*(i+1))%n;
			length -= temp;
		}
	}while(length > 0);
}
/*Function to search if the string is present in the hash table. If yes, then return the index
where it is stored.
*/
int search(string str)
{
	int key = hash(str);
	int temp = key;
	//Because if the word is present then we would get it in one iteration over the array.
	int length = 1200;
	int i = 0;
	do
	{
		//If the word at this index matches our query then return the index.
		if(s[temp] == str)
		{
			return temp;
		}
		//else use quadratic probing to calculate the next index to search.
		else
		{
			temp = (key + (i+1)*(i+1))%n;
			length -= temp;
		}
	}while(length > 0);
	//If the word is not present return -1
	return -1;
}
int main()
{
	freopen("words.dat","rt",stdin);
	//Initialise the array with empty strings.
	for(int i = 0; i < 1200; ++i)
	{
		s[i] = "";
	}
	string str;
	for(int i = 0; i < 1200; ++i)
	{
		cin >> str;
		//calculate the key of the word.
		int key = hash(str);
		//Insert the word in the hash table.
		if(s[key] == "")
		{
			s[key] = str;
		}
		else
		{
			update(key,str);
		}
	}
	//Enter the words to search in the hash table.
	int f = 1;
	cout << "Enter the numbers to search:\n";
	while(f != 0)
	{
		cin >> str;
		int ans = search(str);
		if(ans != -1)
		{
			cout << "Present at index " << ans << "\n";
		}
		else
		{
			cout << "word is not present\n";
		}
		cout << "\nWant to search again:(1/0)\n";
		cin >> f; 
	}
	int count = 0;
	for(int i = 0; i < 1200; ++i)
	{
		if(s[i] != "")
			++count;
	}
	cout << count << " words stored."<< "\n";
}
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

ifstream in ("in.txt");
ifstream dict ("dict.txt");
ofstream out ("out.txt");
//ofstream dbg ("dbg.txt");

// Starting word and forbidden words, will be read from in.txt
string first = "";
vector<string> forbid = {};

// spectrum(word)[i] = number of letters number i in word (0 <= i <= 32)
string spectrum(string word)
{
	bool is_russian = true;
	for (int i=0; 2*i<word.length(); i++)
	{
		if (word[2*i] != -48 and word[2*i] != -47)
		{
			is_russian = false;
			break;
		}
	}
	if (is_russian == false) return "";
	
	string res = string(33, 0);
	for (int i=0; 2*i+1<word.length(); i++)
	{
		const int Codes[33] = {-80, -79, -78, -77, -76, -75, -111, -74, -73, -72, -71, -70, -69, -68, -67, -66, -65, -128, -127, -126, -125, -124, -123, -122, -121, -120, -119, -118, -117, -116, -115, -114, -113};
		for (int j=0; i<33; j++)
		{
			if (word[2*i+1] == Codes[j])
			{
				res[j]++;
				break;
			}
		}
	}

	return res;
}

// given a spectrum, give all corresponding words
map<string, vector<string>> M;

// dfs output
vector<string> spstack (1);

// dfs on M: looking for any correct chain of spectrums
bool dfs(string u, int lvl, int maxlvl)
{
	if (lvl==maxlvl)
	{
		spstack.resize(maxlvl);
		return true;
	}
	for (int i=0; i<33; i++)
	{
		string v = u; v[i]++;
		if (M.count(v) == true and count(forbid.begin(), forbid.end(), v) == 0)
		{
			if (dfs(v, lvl+1, maxlvl) == true)
			{
				spstack[lvl] = v;
				return true;
			}
		}
		
	}
	return false;
}

// for debug purposes; not used
void cout_spec(string spec)
{
	for (char c : spec)
	{
		cout << (int)c << " ";
	}
}

int main()
{	
	int maxlvl;
	in >> maxlvl;
	
	in >> first;
	string tmp;
	while (in >> tmp and tmp != "0")
	{
		forbid.push_back(spectrum(tmp));
		assert(spectrum(tmp) != "");
	}
	
	string word;
	while (dict >> word)
	{
		string sp = spectrum(word);
		
		if (sp.length() > 0)
		{
			M[sp].push_back(word);
		}
	}
	
	spstack[0] = spectrum(first);
	
	if (dfs(spstack[0], 1, maxlvl) == true)
	{
		for (string spec : spstack)
		{
			for (string word : M[spec])
				out << word << " ";
			out << endl;
		}
		cout << "success";
	}
	else
	{
		cout << "fail";
	}
	
	
}
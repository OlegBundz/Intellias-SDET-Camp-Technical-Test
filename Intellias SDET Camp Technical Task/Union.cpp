#include"Union.h"


void Union::CreateSets(vector<vector<int>> const& arr)
{
	int k = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			root[k] = k;
			rank[k] = 0;
			k++;
		}
	}
}

int Union::FindRoot(int k)
{
	if (root[k] != k)
	{
		root[k] = FindRoot(root[k]);
	}
	return root[k];
}

void Union::Unify(int a, int b)
{
	int x = FindRoot(a);
	int y = FindRoot(b);
	if (x == y) return;
	if (rank[x] > rank[y])
	{
		root[y] = x;
	}
	else if (rank[x] < rank[y])
	{
		root[x] = y;
	}
	else {
		root[x] = y;
		rank[y]++;
	}
}

void Union::FindPath(vector<vector<int>> const& arr)
{
	int k = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size() - 1; j++)
		{
			if (arr[i][j] == arr[i][j + 1])
			{
				k = i * arr.size() + j;
				Unify(k, k + 1);
			}
		}
	}

	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] == arr[i + 1][j])
			{
				k = i * arr.size() + j;
				Unify(k, (i + 1) * arr.size() + j);
			}
		}
	}
}

void Union::BaseChek(vector<vector<int>> const& arr)
{
	if (arr.empty()) throw std::exception();
	if ((arr.size() < 2) || (arr.size() > 50))
		throw std::exception();
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].size() != arr.size())
			throw std::exception();
	}
}

bool Union::Connected(vector<vector<int>> const& arr)
{
	BaseChek(arr);
	if ((arr[0][0] == 0) || (arr[arr.size() - 1][arr.size() - 1] == 0))
		return false;
	CreateSets(arr);
	FindPath(arr);
	return ((FindRoot(0)) == (FindRoot((arr.size() * arr.size()) - 1)));
}

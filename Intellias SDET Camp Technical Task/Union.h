#pragma once
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Union {
	unordered_map<int, int> root;
	unordered_map<int, int> rank;

private:
	void CreateSets(vector<vector<int>> const&);
	int FindRoot(int);
	void Unify(int, int);
	void FindPath(vector<vector<int>> const&);
	void BaseChek(vector<vector<int>> const&);

public:
	bool Connected(vector<vector<int>> const& );  
};

#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_V = 100000;

stack<int> stack1, stack2;
unordered_set<int> hash1, hash2;
unordered_multiset<int> hstack1;
vector<int> s;
unordered_set<int> f;
vector<vector<int>> graph(MAX_V, vector<int>());

void dfs2(int &s1)
{
  stack2.push(s1);
  hash2.insert(s1);
  for (auto &t : graph[s1])
  {
    if (hstack1.find(t) != hstack1.end())
    {
      cout << "Not empty" << endl;
      cout << t;
      cout << " ";
      while (!stack2.empty())
      {
        cout << stack2.top();
        cout << " ";
        stack2.pop();
      }
      cout << endl;
      while (!stack1.empty())
      {
        cout << stack1.top();
        cout << " ";
        stack1.pop();
      }
      cout << endl;
      exit(0);
    }
    else if (hash2.find(t) == hash2.end())
    {
      dfs2(t);
    }
  }
  stack2.pop();
}

void dfs1(int &s1)
{
  stack1.push(s1);
  hstack1.insert(s1);
  hash1.insert(s1);
  for (auto &t : graph[s1])
  {
    if (hash1.find(t) == hash1.end())
    {
      dfs1(t);
    }
  }
  if (f.find(s1) != f.end())
  {
    dfs2(s1);
  }
  stack1.pop();
  hstack1.erase(s1);
}

int main()
{
  ifstream in("./input/double_dfs4.txt");
  cin.rdbuf(in.rdbuf());
  int e;
  cin >> e;
  for (int i = 0; i < e; i++)
  {
    int s, t;
    cin >> s >> t;
    graph[s].push_back(t);
  }
  int ns, nf;
  cin >> ns;
  int tm;
  for (int i = 0; i < ns; i++)
  {
    cin >> tm;
    s.push_back(tm);
  }
  cin >> nf;
  for (int i = 0; i < nf; i++)
  {
    cin >> tm;
    f.insert(tm);
  }

  for (auto &s1 : s)
  {
    dfs1(s1);
  }
  cout << "Empty" << endl;

  return 0;
}

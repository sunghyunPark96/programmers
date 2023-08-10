#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;
    map<int, string> m1;
    map<string, int> m2;
    for(int i=0;i<players.size();i++)
    {
        m1[i] = players[i];
        m2[players[i]] = i;
    }
    for(int i=0;i<callings.size();i++)
    {
        int current = m2[callings[i]];
        string change = m1[current - 1];
        m1[current - 1] = callings[i];
        m1[current] = change;
        m2[callings[i]] = current - 1;
        m2[change] = current;
    }
    for(auto c : m1) answer.push_back(c.second);
    return answer;
}

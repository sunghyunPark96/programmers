#include <bits/stdc++.h>

// Target에 keymap에 없는문자 + 있는문자 같이 있을 경우 예외 처리

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
	map<char, int> result_map;
	int score;

	for (auto keys : keymap) {
		for (int i = 0; i < keys.length(); i++) {
			if (result_map.find(keys[i]) != result_map.end()) {
				if (result_map[keys[i]] > i) {
					result_map[keys[i]] = i;
				}
			}
			else {
				result_map[keys[i]] = i;
			}
		}
	}
	for (auto target : targets) {
		score = 0;
		for (int i = 0; i < target.length();i++) {
			if (result_map.find(target[i]) != result_map.end()) {
				if (score != -1) {
					score = 1 + score + result_map[target[i]];
				}
			}
			else {
				score = -1;
				break;
			}
		}
		answer.push_back(score);
	}
    return answer;
}

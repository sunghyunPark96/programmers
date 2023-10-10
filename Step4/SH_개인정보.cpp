#include <bits/stdc++.h>
using namespace std;

int caculate_day (string today) {
    int today_count = (stoi(today.substr(0,4)) - 2000) * 28 * 12 + (stoi(today.substr(5,2))) * 28 + (stoi(today.substr(8,2)));
    return today_count;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int today_count = caculate_day(today);
    map<string, int> terms_map;
    
    for (auto i : terms) {
        int temp1 = stoi(i.substr(2)) * 28;
        string temp2 = i.substr(0,1);
        terms_map.insert(pair<string,int> (temp2,temp1));
    }
    
    for (int i= 0; i< privacies.size(); i++) {
        int temp1 = caculate_day(privacies[i].substr(0,10));
        string temp2 = privacies[i].substr(11,1);

        int limit_day = temp1 + terms_map[temp2];
        if (today_count >= limit_day ) answer.push_back(i+1);
    }
    
    return answer;
}



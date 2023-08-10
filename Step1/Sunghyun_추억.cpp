#include <bits/stdc++.h>

using namespace std;

// 자료구조 : map:log(n)으로 시간 복잡도 줄이기

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int> table;
    int score;
        
    for (int i=0; i<name.size();i++){
        table.insert(pair<string, int> (name[i],yearning[i]));
    }
    // table : (may,5), (kein,10), (kain,1), (radi,3)
    
    for (auto i:photo){
        // i = ["may", "kein", "kain", "radi"]
        score = 0;
        
        for (auto i2:i){
            // i2 = "may"
            if (table.find(i2) != table.end()){
                score = score + table[i2];
        
            }
        }
        answer.push_back(score);
        // ["may", "kein", "kain", "radi"] 점수 계산해서 answer에 추가
    }
    
    return answer;
}

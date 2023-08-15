#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;


vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map <string, int> match;
    
    for(int i=0; i<name.size(); i++){
        match[name[i]] = yearning[i]; //map이 배열보다 복잡도 낮음, 연산속도 감소 -> map은 로그n 스케일
    }
    
    for(int i=0; i<photo.size(); i++){
        int sum =0;
        for(int j=0; j<photo[i].size(); j++){
            sum += match[photo[i][j]];
        }
        answer.push_back(sum);
    }
    return answer;
}


/*
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int idx;
    
    for(int i=0; i<photo.size(); i++)
    {
        int sum = 0;
        for(int j=0; j<photo[i].size(); j++){
            idx = find(name.begin(), name.end(), photo[i][j])-name.begin(); //주의 find는 포인터 반환
            sum += yearning[idx];     //answer[i] += yearning[idx]; 아 벡터공간에서 공간할당이 안되어있구나
            
        }
        answer.push_back(sum);
    }
    return answer;
}
*/

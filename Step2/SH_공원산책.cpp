#include <bits/stdc++.h>

using namespace std;

// 이동 시 마지막 X위치가 아니라 가는 경로마다 X가 있는지 체크해줘야함

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int max_x = park[0].length()-1;
    int max_y = park.size()-1;
    bool flag2; 
    string direction;
    int move_point;
    string result;
    
    for (int i=0; i<park.size();i++){        
        if (park[i].find("S") != string :: npos){
            answer.push_back(i);        
            answer.push_back(park[i].find("S"));
        }
    }
    
    for (auto route : routes){
        direction = route[0];
        move_point = stoi(route.substr(1));
        
        flag2 = true;
        
        if (direction == "E"){
            if (answer[1] + move_point <= max_x){
                for (int i=1; i<move_point+1;i++){
                    result = park[answer[0]][answer[1] + i];
                    if (result == "X"){
                        flag2 = false;
                        break;
                    }
                }
                if (flag2 == true){
                    answer[1] = answer[1] + move_point;
                }
            }
        }
        
        if (direction == "W"){
            if (answer[1] - move_point >= 0){
                for (int i=1; i<move_point+1;i++){
                    result = park[answer[0]][answer[1] - i];
                    if (result == "X"){
                        flag2 = false;
                        break;
                    }
                }
                if (flag2 == true){
                    answer[1] = answer[1] - move_point;
                
                }
            }
        }
        
        if (direction == "S"){
            if (answer[0] + move_point <= max_y){
                for (int i=1; i<move_point+1;i++){
                    result = park[answer[0] + i][answer[1]];                    
                    if (result == "X"){
                        flag2 = false;
                        break;
                    }
                }  
                if (flag2 == true){
                    answer[0] = answer[0] + move_point;
                
                }
            }
        }
        
        if (direction == "N"){
            if (answer[0] - move_point >= 0){
                for (int i=1; i<move_point+1;i++){
                    result = park[answer[0] - i][answer[1]];
                    if (result == "X"){
                        flag2 = false;
                        break;
                    }
                }
                if (flag2 == true){
                    answer[0] = answer[0] - move_point;
                
                }
            }
        }
    }
    
    return answer;
}

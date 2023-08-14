#include <bits/stdc++.h>

using namespace std;
//*min_element(), *max_element() : vetor 최대 최소 구하기
//find() : str에서 만족하는 값의 "첫번 째" 인덱스만 반환

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int x_min = 0;
    int x_max = 0;
    int y_min = 0;
    int y_max = 0;
    
    vector<int> locations_x;
    vector<int> locations_y;
    
    for (int line_index=0; line_index < wallpaper.size();line_index++){
        if (wallpaper[line_index].find("#") != string :: npos){
            locations_y.push_back(line_index);
                        
            for (int index=0; index < wallpaper[line_index].length();index++){
                
                if (wallpaper[line_index].substr(index,1) == "#"){
                    locations_x.push_back(index);
                }
            }
        }
    }     
    
    x_min = *min_element(locations_x.begin(),locations_x.end());
    x_max = *max_element(locations_x.begin(),locations_x.end());
        
    y_min = *min_element(locations_y.begin(),locations_y.end());
    y_max = *max_element(locations_y.begin(),locations_y.end());
    
    answer.push_back(y_min);
    answer.push_back(x_min);
    answer.push_back(y_max+1); // 최대 좌표는 +1 해줘야됨
    answer.push_back(x_max+1); // 최대 좌표는 +1 해줘야됨
   
    return answer;
}

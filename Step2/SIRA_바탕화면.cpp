#include <string>
#include <vector>

using namespace std;

int x_min, y_min = 51; 
int x_max, y_max =-1; //전역변수 선언 

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    for(int i=0; i<wallpaper.size(); i++){ // [".#...", "..#..", "...#."] 
        for(int j=0; j<wallpaper[i].size(); j++){ // .#...
                    if (wallpaper[i][j]=='#'){//왜 ""는 안됨?
                        if(i<x_min) x_min = i; 
                        if(j<y_min) y_min = j;    
                        if(i+1>x_max) x_max = i+1; //주의 격자 모양, 얘까지 포함하려면 max는 +1씩
                        if(j+1>y_max) y_max = j+1;  //주의 대각선으로 이어진 경우 i,j = x_max, y_max이므로 업뎃 안됨/ 그래서 i+1,j+1과 비교
                    }
                    
        }
    }
    
    answer.push_back(x_min);
    answer.push_back(y_min);
    answer.push_back(x_max);
    answer.push_back(y_max);  
    return answer;
}

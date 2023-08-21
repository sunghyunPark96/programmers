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
                        if(i>x_max) x_max = i+1; //주의 격자 모양, 얘까지 포함하려면 max는 +1씩
                        if(j>y_max) y_max = j+1; 
                    }
                    
        }
    }
    
    answer.push_back(x_min);
    answer.push_back(y_min);
    answer.push_back(x_max);
    answer.push_back(y_max);  // 주의 !!! 이렇게 하면 안되는 이유 : 바깥쪽 for문을 마지막으로 돌면서 얘는 i=0으로 초기화 되버림
    return answer;
}

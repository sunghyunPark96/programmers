#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<vector<char>> parkMap(park.size()); //공원 구성을 위한 선언
    pair<int, int> nowPstn = { 0,0 };  //현재 위치를 위한 선언
    bool state;      //이동 후의 위치를 다시 현재 위치로 갱신하기 위한 선언

//공원 구성, 시작위치 확인
    for (int i = 0; i < park.size(); i++) {	
        for (int j = 0; j < park[i].length(); j++) {
            parkMap[i].push_back(park[i][j]);
            if (park[i][j] == 'S') nowPstn = make_pair(i, j);   //시작위치 확인 후 저장 뒤에서 지금 위치로 활용 예정  
        }
    }

//routes에 따라 이동
    for (auto str : routes) {
        string direct = str.substr(0, 1);	//방향 확인(문자열에서 첫번째 추출)
        int move = stoi(str.substr(2)); 	//이동할 거리 확인(문자열에서 추출 후 int로 변환)
        pair<int, int> temp = { nowPstn.first, nowPstn.second };	//이동후의 위치를 나타낼 변수에 현재위치 저장
        state = true;

        if (direct == "N") {
            if (temp.first - move < 0);	//위 방향이니 음의 값이면 공원 범위 초과
            else {
                for (int i = 0; i < move; i++) {	//해당 방향으로 거리만큼 이동
                    temp.first--;
                    if (parkMap[temp.first][nowPstn.second] == 'X') {	//장애물 만날 시 즉시 종료
                        state = false;
                        break;
                    }
                }
            }
        }
        else if (direct == “S”) {
            if (temp.first + move >= park.size());  // 아래 방향이니 벡터 park의 크기(행) 보다 크면 공원 범위 초과 
            else {
                for (int i = 0; i < move; i++) {
                    temp.first++;
                    if (parkMap[temp.first][nowPstn.second] == 'X') {
                        state = false;
                        break;
                    }
                }
            }
        }
        else if (direct == "W") {
            if (temp.second - move < 0);   //왼쪽 방향이니 음의 값이면 공원 범위 초과
            else {
                for (int i = 0; i < move; i++) {
                    temp.second--;
                    if (parkMap[nowPstn.first][temp.second] == 'X') {
                        state = false;
                        break;
                    }
                }
            }
        }
        else {
            if (temp.second + move >= park[0].length());  //오른쪽 방향이니 park의 문자열 길이 보다 길면 공원 범위 초과 
            else {
                for (int i = 0; i < move; i++) {
                    temp.second++;
                    if (parkMap[nowPstn.first][temp.second] == 'X') {
                        state = false;
                        break;
                    }
                }
            }
        }
  //명령 수행 후(이동 후)의 위치를 현재 위치로 갱신 
        if (state) {
            nowPstn = temp;
        }
    }
    answer.push_back(nowPstn.first);
    answer.push_back(nowPstn.second);

    return answer;
}

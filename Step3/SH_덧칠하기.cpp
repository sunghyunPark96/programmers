#include <bits/stdc++.h>

using namespace std;
// copy 사용한 이유 : section 원소를 중간에 지우면 i = 0 일 때 2가 지워 지면{2,3,6} -->  i = 1 일때 3이 아니라 6이 호출되어서 {3,6} 오류 발생
// copy 사용할 때 복사 시 미리 데이터 공간 할당 필수
// 범위형 for문 사용시 범위 전체 copy해서 사용하는게 아니라 범위는 똑같은 포인터로 가져오면서 i로 할당 할 때 복사됨
// vector.begin(), vector.end() 는 반복자 반환
// vector.front(), vector.back() 는 참조값 반환


int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int now;
    vector<int> vec_copy;
    
    //O(개선 갯수 : n)
    while(section.size() > 0){
        answer += 1;
        now = section[0];
                
        vec_copy.resize((int)(section.size()));
        //O(section : n)
        copy(section.begin(), section.end(), vec_copy.begin());
        
        //O(section : n)
        for (int i=0 ;i<vec_copy.size() ;i++){
            if (vec_copy[i] <= (now + m - 1)){
               section.erase(section.begin());
            } 
        }
    }
        
    return answer;
}

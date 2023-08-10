#include <bits/stdc++.h>

using namespace std;

// 자료구조 : map(이진탐색) 으로 시간 복잡도 줄이기
// map시간복잡도(log(call개수)), 선형탐색시간복잡도(call개수*players개수)
// auto : 앞에 있는 자료형 구조로 맞춰줌!!
// 변수 선언할 때 주소, 실제 데이터 할당 찾아보기
// insert : index 설정해주면 거기에 들어감

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string,int> table;
    
    //map 초기 설정
    //table : (mumu,0), (soe,1), (poe,2), (kai,3), (mine,4)
    
    for (int i=0; i<players.size();i++){
        table.insert(pair<string, int> (players[i],i));
    }
        
    for (auto call : callings) {
        // call : kai 
        // players : ["mumu", "soe", "poe", "kai", "mine"]
        // table : (mumu,0), (soe,1), (poe,2), (kai,3), (mine,4)
        // table[call] : kai의 등수(3)
        
        players[table[call]] = players[table[call]-1];
        // 명령 : players[3] = players[2]
        // players : ["mumu", "soe", "poe", "poe", "mine"]

        players[table[call]-1] = call;
        // 명령 : players[2] = str kai
        // players : ["mumu", "soe", "kai", "poe", "mine"]
        
        table[players[table[call]]] = table[players[table[call]]] + 1;
        // 명령 : table[poe] = table[poe] + 1
        // table : (mumu,0), (soe,1), (poe,3), (kai,3), (mine,4)
        
        table[call] = table[call] - 1;
        // 명령 : table[kai] = table[kai] - 1
        // table : (mumu,0), (soe,1), (poe,3), (kai,2), (mine,4)
    }
    
    return players;
}

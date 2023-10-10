#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "No";               //일단 No라고 가정
    int cur1=0;
    int cur2=0;
    int len_tar=size(goal);        
    int cur_tar=0;
    while(cur_tar < len_tar)
    {
        if(goal[cur_tar]==cards1[cur1]) 
        { 
            cur_tar++;                  //커서이동
            cur1++;
        }
        else if(goal[cur_tar]==cards2[cur2])
        { 
            cur_tar++;                  //커서이동
            cur2++;                    
        else
        {
            answer="No";
            break;                 
        }
    }
    
    if (cur_tar == len_tar){
        answer = "Yes";
    }
    return answer;
}

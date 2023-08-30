/* JUNA_덧칠하기 */

#include <bits/stdc++.h>
using namespace std;

int solution(int n, int m, vector<int> section)
{
    int ans=1;                      //횟수
    int ss=section.size();          //배열크기
    
    for(int i=0;i<ss-1;i++)
    {
        if(section[i]+m>section[ss-1])    //칠했을 때 마지막 원소보다 크거나 같을 때까지
            break;
            ans++;                
    }
    return ans;
}

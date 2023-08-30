#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
   int paint = 0;
    for(int a : section){
        if(paint < a){
            paint = a + m - 1;
            answer++;
        }
    }
    return answer;
}

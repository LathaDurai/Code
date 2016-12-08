#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
   public:
   int maximumDifference;

// Add your code here
    Difference(vector<int> a): elements(a){}
    void computeDifference() {
       int diff = 0;
       maximumDifference = elements[0] - elements[1];
       for(int i = 0; i< elements.size(); i++) {
         for (int j = 0; j<elements.size(); j++) {
            diff = elements[i] - elements[j];
            if(diff>maximumDifference) {
               maximumDifference = diff;
            }
         }
       }
    }
};
int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
  
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}

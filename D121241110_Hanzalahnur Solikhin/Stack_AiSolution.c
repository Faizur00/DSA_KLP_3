#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    string S = "";                   
    stack<string> history;        

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) { 
            string W;
            cin >> W;
            history.push(S); 
            S += W;        
        } 
        else if (op == 2) { 
            int k;
            cin >> k;
            history.push(S); 
            S.erase(S.size() - k); 
        } 
        else if (op == 3) { 
            int k;
            cin >> k;
            cout << S[k - 1] << '\n'; 
        } 
        else if (op == 4) { 
            if (!history.empty()) {
                S = history.top();
                history.pop();     
            }
        }
    }
    
    return 0;
}

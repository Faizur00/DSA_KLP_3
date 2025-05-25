#include <iostream>
#include <stack>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    string current = "";              // Menyimpan teks saat ini
    stack<string> history;           // Menyimpan riwayat untuk undo

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) {
            string add;
            cin >> add;
            history.push(current);   // Simpan keadaan sebelum perubahan
            current += add;          // Tambahkan teks
        } 
        else if (op == 2) {
            int k;
            cin >> k;
            history.push(current);   // Simpan keadaan sebelum perubahan
            current.erase(current.size() - k); // Hapus k karakter dari belakang
        } 
        else if (op == 3) {
            int k;
            cin >> k;
            if (k >= 1 && k <= current.size()) {
                cout << current[k - 1] << '\n'; // Cetak karakter ke-k
            }
        } 
        else if (op == 4) {
            if (!history.empty()) {
                current = history.top(); // Undo: kembalikan string sebelumnya
                history.pop();
            }
        }
    }

    return 0;
}

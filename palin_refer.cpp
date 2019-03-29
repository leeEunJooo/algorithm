
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


int isPalin(string a) {
    string b = a; 
    reverse(b.begin(), b.end());

    if (a == b)
        return 0;
    else
        return 1;
}

int isPseudo(string a) {
    for (int i = 0; i < a.size(); i++) {
        string b = a;
        b.erase(i, 1);

        if (isPalin(b) == 0)
            return 0;
    }
    return 1;
}

int main() {
    int len = 0;
    vector <string> lists;
    vector <int> results;

    ifstream inp("palin.inp");
    string tmp;
    inp >> len;

    for (int i = 0; i < len; i++) {
        inp >> tmp;
        lists.push_back(tmp);
    }

    inp.close();

    for (int i = 0; i < len; i++) {
        if (isPalin(lists[i]) == 1)
            if (isPseudo(lists[i]) == 1)
                results.push_back(3);
            else
                results.push_back(2);
        else
            results.push_back(1);
    }

    ofstream out("palin.out");
    for (int i = 0; i < results.size(); i++) {
        out << results[i] << endl;
    }
    out.close();

    return 0;
}
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <algorithm>
//using namespace std;
//bool is_pseudo(string, string, int);
//
////reverse(string.begin(), string.end());
//int is_palin(string s) {
//    int len = s.length();
//    string r = s;
//    reverse(r.begin(), r.end());
//
//    if(s == r) return 1;
//
//    for(int i = 0; i < len/2; ++i) {
//        if(s[i] != r[i] && is_pseudo(s, r, i)) return 2;
//    }
//
//    return 3;
//}
//
//bool is_pseudo(string s1, string s2, int i) {
//    s1.erase(i, 1);
//    string r1 = s1;
//    reverse(r1.begin(), r1.end());
//
//    s2.erase(i, 1);
//    string r2 = s2;
//    reverse(r2.begin(), r2.end());
//
//    if(s1 == r1 || s2 == r2) return true;
//    else return false;
//}
//
//int main() {
//    int N;
//    string s;
//    ifstream inp("palin.inp");
//    ofstream out("palin.out");
//
//    inp >> N;
//
//    for(int i = 0; i < N; ++i) {
//        inp >> s;
//        out << is_palin(s) << endl;
//    }
//
//    inp.close();
//    out.close();
//} 


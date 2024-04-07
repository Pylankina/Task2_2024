#include "Parcer.h"
using namespace std;

Parcer::Parcer(ifstream &fin) {
    setlocale(LC_ALL, "eng");
    string s;
    fin >> s;
    n=stoi(s);
    fin >> s;
    K=stoi(s);
    int i=0;
    while (!fin.eof()) {
        fin >> s;
        p.push_back(stoi(s));
        fin >> s;
        w.push_back(stoi(s));
        i++;
    }
}
  

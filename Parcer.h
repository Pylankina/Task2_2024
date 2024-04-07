#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>

using namespace std;

class Parcer{
protected:
    int K, n;
    vector<int> p;
    vector<int> w;
public:
    Parcer (ifstream &fin);
};

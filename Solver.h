#include "Parcer.h"

using namespace std;

class Solver:public Parcer{
protected:
    vector<vector<bool>> poplution;
    int f_popl[10];
public:
    Solver(ifstream &fin);
    int func(vector<bool> result);
    void changing(vector<bool> p1, vector<bool> p2, vector <bool> &ch1,  vector <bool> &ch2);
    void creatting(vector<vector<bool>> &poplution, int *f_popl);
    void motation(vector<bool> &ch1, int mu);
    void sortting(vector<vector<bool>> &popl);
    void writting(vector<vector<bool>> popl);
};

#include "Solver.h"

int main(){
    ifstream fin;
    fin.open("ks_4_0");
    Solver data_file(fin);
    fin.close();
    return 0;
}

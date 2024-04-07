#include <algorithm>
#include "Solver.h"

using namespace std;

int Solver:: func(vector<bool> result){
    int f=0,i=0;
    while (i!=n){
        f=f+p[i]*result[i]; //функция приспособленности
        i++;
    }
    if (f<K){
        return f;
    }
    else return 0;
};

void Solver:: changing(vector<bool> p1, vector<bool> p2, vector <bool> &ch1, vector <bool> &ch2){ //скрещиваем особей
    int h=rand()%(p1.size());//генерируем точку разрыва
    int k=0;
    for (k=0; k<h; k++){
        ch1.push_back(p1[k]);
    }
    while(k<p2.size()){
        ch1.push_back(p2[k]);
        k++;
    }
    k=0;
    for (k=0; k<h; k++){
        ch2.push_back(p2[k]);
    }
    while(k<p1.size()){
        ch2.push_back(p1[k]);
        k++;
    }
    return;
}

void Solver:: sortting(vector<vector<bool>> &popl){
    for (int i=0; i<(popl.size()-1); i++){
        if (func(popl[i])<(func(popl[i+1]))){
            vector <bool> b=popl[i+1];
            popl[i]=popl[i+1];
            popl[i+1]=b;
        }
    }
    return;
}

void Solver:: creatting(vector<vector<bool>> &poplution, int *f_popl){
    int c;
    int i, j=0;
    while (j<10){ //генерируем популяцию
        vector <bool> r;
        i=0;
        while (i<n){
            c=rand()%100;
            if (c < 50)
                r.push_back(true);
            else
                r.push_back(false);
            i++;
        }
        f_popl[j]=func(r);//вычисляем для каждого его функцию приспособленности
        poplution.push_back(r); //добавляем в популяцию
        j++;
    }
    return;
}

void Solver:: motation(vector<bool> &ch1, int mu){ //функция мутации
    int m=rand()%(100);
    bool flag=0;
    if (m<mu)
        flag=1;
    if(flag==1){
        int pos1, pos2;
        pos1=rand()%(ch1.size());
        int y=rand()%(ch1.size());
        while (y==pos1)
            y=rand()%(ch1.size());
        pos2=y;
        swap(ch1[pos1], ch1[pos2]);
    }
    return;
}

void Solver:: writting(vector<vector<bool>> popl){
    ofstream fou;
    fou.open("result.txt");
    if (fou.is_open()){
        for (int j=0; j<n; j++)
            fou<<popl[0][j]<<"  ";
    }
    fou.close();
}

Solver::Solver(ifstream &fin):Parcer(fin){
    creatting(poplution, f_popl);//создаем популяцию
    int parent1, parent2,i=0;
    while (i<10){//сменяем поколения
        parent1=rand()%10;
        parent2=rand()%10;
        while (parent2==parent1) //берем любых два родителя для размножения
            parent2=rand()%10;
        vector <bool> ch1, ch2;
        changing(poplution[parent1], poplution[parent2], ch1, ch2);//слияние
        motation(ch1, 5);//мутация
        motation(ch2, 5);//мутация
        poplution.push_back(ch1);//добавили потомков в популяцию
        poplution.push_back(ch2);
        sortting(poplution);
        poplution.pop_back();
        poplution.pop_back();//удаляем наименее приспособленных особей
        i++;
    }
    writting(poplution);
};

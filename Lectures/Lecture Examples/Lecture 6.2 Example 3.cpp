#include<iostream>
#include<vector>

using namespace std;



int main(int argc, char** argv){
    vector<int> v;
    v = {1, 2, 3};
    cout << "v[0]: " << v[0] << endl;
    vector<int>::iterator i = v.begin();
    for (; i < v.end(); i++){
        cout << *i << ' ';
    }
    cout << endl;
} //try to guess the output

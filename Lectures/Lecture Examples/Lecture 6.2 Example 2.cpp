#include<iostream>
#include<vector>

using namespace std;



int main(int argc, char** argv){
    vector<int> v;
    v = {1, 2, 3};
    for (int n : v){
        cout << "Number from v: " << n << endl;
    }
    cout << "Size of v: " << v.size() << endl;
} //try to guess the output

#include<iostream>
#include<vector>

using namespace std;



int main(int argc, char** argv){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    while(!v.empty()){
        cout << v.back() << ' ';
        v.pop_back();
    }

    cout << endl << "Size: " << v.size() << endl;
} //try to guess the output

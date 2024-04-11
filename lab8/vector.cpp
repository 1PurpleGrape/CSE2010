#include <iostream>
#include <vector>
using namespace std;

void printMemVec(vector <int> v){
    printf("Vector - Each int is worth %lu bytes\n", sizeof(v[0]));
    for(int i=0; i < v.size(); i++){
        printf("Value :%i at Memory Location:%p \n", v[i], &v + i);
    }
}

void incVecBy10(vector <int> & v){
    for(int i =0; i < v.size(); i++){
        v[i] +=10;
    }
}

int main() {
    const int SIZE = 5;
    vector <int> vec(SIZE);
    for(int i = 0; i < SIZE; i++){
        vec[i] = 100 + i;
    }

    printf("Before Increment -----------");
    // call printMemVec( ... ) on vec
    printMemVec(vec);
    // call incBy10( ... ) on vec
    incVecBy10(vec);

    printf("After Increment -----------");
    // call printMemVec( ... ) on vec again to view the changes
    printMemVec(vec);
    //remove last element of vec
    vec.pop_back();

    printf("After Pop -----------");
    // call printMemVec( ... ) on vec again to view the changes
    printMemVec(vec);
    // append 101 and 102 at the end of vec
    vec.push_back(101);
    vec.push_back(102);

    printf("After Push -----------");
    //call printMemVec( ... ) on vec again to view changes
    printMemVec(vec);
    return 0;
}



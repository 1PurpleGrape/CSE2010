#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;
#include <iostream>
#include <chrono>



#include <string>



/**
* @brief returns the first index of elem if it exists, otherwise returns -1
* iterativeSearch starts at the first index and iterates sequentially to the next until it either
* finds the element or until it reaches the the end (i.e. element does not exist)
*
* @param v : vector of elements
* @param elem : integer to look for
* @return int
*/
template<typename T>
int iterativeSearch(const vector<T>& v, const T& elem) {
    for(int i= 0; i< v.size(); i++){
        if(v[i]==elem){
            return i;
        }       
    }
    return -1;
}

/**
*@brief returns the index of elem, if it exists in v. Otherwise it returns -1.
*
* binarySearch is recursive (i.e. function calls itself).
* It utilizes the fact that v is increasing order (e.g. values go up and
* duplicates are not allowed).
* It calculates the mid from the start and end index. It compares v[mid] (i.e. value
* at mid) with elem and decides whether to search the left half (lower values)
* or right half (upper values).
*
* @param start : leftmost index (starting value is 0)
* @param end :rightmost index (starting value is v.size())
* @param elem : integer to look for
* @return int
*/
template<typename T>
int binarySearch(vector<T>& v, int start, int end, const T& elem){
    if(start > end){
        return -1;
    }
    int mid = (start + end) / 2;
    //cout<< v[mid]<< endl;
    //cout<<"thingy"<< elem<<endl;
    if(v[mid] > elem){
        return binarySearch(v, start, mid - 1, elem);
    }
    else if(v[mid] < elem){
        return binarySearch(v, mid + 1, end, elem);
    }
    else{
        return mid;
    }
}

/**
*@brief updates v to contain the values from filename (leave as is)
*It is expected that the files contain values ranging from one to
*one hundred million in ascending order (no duplicates).
*@param filename : string
*@param v : vector
*/
template<typename T>
void vecGen(const string& filename, vector<T>& v) {
    ifstream file(filename);
    T num;
    v.clear();
    while (file.is_open() && file >> num) {
        v.push_back(num);
    }
    file.close();
}



int main (){
                             // 0     1    2     3      4     5    6     7
    vector <string> words = {"abc","efg","hij","klm","nop","qrs","tuv","wxyz"};
    string thingy = "abc";
    int index_if_found = binarySearch(words, 0, words.size() - 1, thingy);
    cout<< index_if_found;

    thingy = "efg";
    index_if_found = binarySearch(words, 0, words.size() - 1, thingy);
    cout<< index_if_found;

    thingy = "hij";
    index_if_found = binarySearch(words, 0, words.size() - 1, thingy);
    cout<< index_if_found;

    thingy = "klm";
    index_if_found = binarySearch(words, 0, words.size() - 1, thingy);
    cout<< index_if_found;

    thingy = "nop";
    index_if_found = binarySearch(words, 0, words.size() - 1, thingy);
    cout<< index_if_found;


    thingy = "qrs";
    index_if_found = binarySearch(words, 0, words.size() - 1, thingy);
    cout<< index_if_found;

    thingy = "tuv";
    index_if_found = binarySearch(words, 0, words.size() - 1, thingy);
    cout<< index_if_found;

    thingy = "wxyz";
    index_if_found = binarySearch(words, 0, words.size() - 1, thingy);
    cout<< index_if_found;
    


    vector <int> ints = {1,2,3,4,5,6,7,8,9};
    int num = 7;
    index_if_found = binarySearch(ints, 0, words.size() - 1, num);
    cout<< index_if_found;

    vector <double> dubs = {.1,.2,.3,.4,.5,.6,.7,.8,.9};
    double dub = .2;
    index_if_found = binarySearch(dubs, 0, words.size() - 1, dub);
    cout<< index_if_found;
    return 99999;




    /*
    vector<int> v;
    vecGen("10000_numbers.csv", v);
    // test elements to search for
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    // reads through all 10 of the test_elem values and calls iterative search
    // and records how long each search took (leave as is)
    for(int i = 0; i < elem_to_find.size(); i++){
        // gets the elem to search for
        int elem = elem_to_find[i];
        // stopwatches the time
        //clock_t start = clock();
        auto start = chrono::high_resolution_clock::now();
        // call binarySearch with appropriate parameters
        int index_if_found = binarySearch(v ,0,v.size(),elem);
        //clock_t end = clock();
        auto end = chrono::high_resolution_clock::now();

        // calculates the total time it took in seconds
        //double elapsed_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);
        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
        //prints the index and how long it took to find it
        cout << index_if_found <<" Time taken by binarySearch " << duration.count() << " microseconds" << endl;
        //cout << index_if_found << ": " << elapsed_time_in_sec << endl;
    }
    vector<double> d;
    vecGen("1000_double.csv", d);
    vector<double> double_to_find;
    vecGen ("double_to_find.csv", double_to_find);
    for(int i = 0; i < double_to_find.size(); i++){
        // gets the elem to search for
        double target = double_to_find[i];
        // stopwatches the time
        //clock_t start = clock();
        auto start = chrono::high_resolution_clock::now();
        // call binarySearch with appropriate parameters
        int index_if_found = binarySearch(d ,0,d.size(),target);
        //clock_t end = clock();
        auto end = chrono::high_resolution_clock::now();

        // calculates the total time it took in seconds
       // double elapsed_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);
        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

        //prints the index and how long it took to find it
        //cout << index_if_found << ": " << elapsed_time_in_sec << endl;
        cout << index_if_found << " Time taken by binarySearch " << duration.count() << " microseconds" << endl;
    }
    */
    

}
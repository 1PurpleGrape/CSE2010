#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>
using namespace std;


/**
* @brief returns the first index of elem if it exists, otherwise returns -1
* iterativeSearch starts at the first index and iterates sequentially to the next until it either
* finds the element or until it reaches the the end (i.e. element does not exist)
*
* @param v : vector of elements
* @param elem : integer to look for
* @return int
*/
int iterativeSearch(vector<int>v, int elem) {
    // use a for loop where the index, i goes from 0 to the size of v
    for(int i= 0; i< v.size(); i++){
        if(v[i]==elem){
            return i;
        }
        //cout << "hi";
        
    }
    return -1;
    // inside the for loop, use an if statement to check whether the element at i (e.g. v[i]) equals elem
    // inside the if statement return i

    // outside of the for loop return -1
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
int binarySearch(vector<int> & v, int start, int end, int elem){
    //write an if statement that checks the terminating case
    //inside the if statement return -1
    //cout<<"hi";
    if(start>end){
        //cout<<"bad";
        return -1;
    }
    int mid = (start+end)/2;
    if(v[mid] > elem){
        //cout<<"small";
        end= mid-1;
    }
    if(v[mid]<elem){
        start = mid+1;
        //cout<<"big";
    }
    if(v[mid]==elem){
        return mid;
    }
    return binarySearch(v,start, end,elem);
    // instantiate the midpoint

    // Use if/else statements to do the following:
    // 1) update end (search left half)

    // 2) update start (search right half)

    // 3) return mid (found the elem)

    // return a recursive call to binarySearch( ... )
}

/**
*@brief updates v to contain the values from filename (leave as is)
*It is expected that the files contain values ranging from one to
*one hundred million in ascending order (no duplicates).
*@param filename : string
*@param v : vector
*/
void vecGen(string filename, vector<int> & v) {
    ifstream file(filename);
    int num;
    v.clear();
    while (file.is_open() && file >> num) {
        v.push_back(num);
    }
    file.close();
}

int main( ){
    // populate v with 10000 sorted numbers (leave as is)
    vector<int> v;
    vecGen("10000_numbers.csv", v);
    // test elements to search for (leave as is)
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);
    // reads through all 10 of the test_elem values and calls iterative search
    // and records how long each search took (leave as is)
    /*
    for(int i = 0; i <v.size(); i++){
        cout<< v[i];
    }
    */
    



    for(int i = 0; i < elem_to_find.size(); i++) {
        // gets the elem to search for
        int elem = elem_to_find[i];
        //cout<< elem;
        // stopwatches the time
        //clock_t start = clock();         // start time
        auto start = chrono::high_resolution_clock::now();
        int index_if_found = iterativeSearch(v, elem); // call search
        //clock_t end = clock();         // end time
        auto end = chrono::high_resolution_clock::now();
        // calculates the total time it took in seconds
        //double elapsed_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);
        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
        //prints the index and how long it took to find it
        //cout << index_if_found << ": " << elapsed_time_in_sec << endl;
        cout << index_if_found << " Time taken by iterativeSearch " << duration.count() << " microseconds" << endl;


    }
    // repeat the for loop above so that it records the time
    // it takes for binarySearch to do the same operation
    //cout << "hi";
    for(int i = 0; i < elem_to_find.size(); i++){
        int elem = elem_to_find[i];
        //cout<< elem;
        //clock_t start = clock();
        auto start = chrono::high_resolution_clock::now();
        //cout<< v.size();
        int index_if_found =binarySearch(v, 0, v.size(), elem);
        auto end = chrono::high_resolution_clock::now();
        //clock_t end = clock();
        //double elapsed_time_in_sec = (double(end-start)/CLOCKS_PER_SEC);
        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << index_if_found << " Time taken by binarySearch " << duration.count() << " microseconds" << endl;
        //cout << index_if_found <<":"<< elapsed_time_in_sec << endl;
    }
}
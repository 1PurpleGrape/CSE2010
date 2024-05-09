#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;
#include <iostream>
#include <chrono>


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
int binarySearch(vector<int> & v, int start, int end, int elem){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(v[mid] > elem){
        end= mid-1;
    }
    if(v[mid]<elem){
        start = mid+1;
    }
    if(v[mid]==elem){
        return mid;
    }
    return binarySearch(v,start, end,elem);
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

void writeTimes(string filename, const vector<double> times, const vector<int> n){
    ofstream myFile(filename) ;

    myFile << "Number of Elements (n)\t Time (sec) " << endl;
    for(int i = 0; i < times.size(); i++){
        myFile << n[i] << "\t" << times[i] << "\n";
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;
}

double average(const vector<double> a){
    double total=0;
    for(int i =0; i<a.size(); i++){
        total+=a[i];
    }
    return total/a.size();

}


int main (){
    // test elements to search for
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);
    // size (n) of all tests
    vector<int> file_sizes;
    vecGen("sizes.csv", file_sizes);

    //n list of numbers
    vector<int>v;

    //results of times
    vector<double> times;

    //results of times
    vector<double> avg;

    // create a for loop to iterate through the file sizes
    for(int i= 0; i < file_sizes.size(); i++) {
    // get the name/size of the file and assign it to string called filename
    string filename = to_string(file_sizes[i]) + "_numbers.csv";
    //call vecGen on filename and v
    vecGen(filename, v);

    // print filename (this will be good for debugging)
    cout<<"File used: "<<filename<<endl;

    // call times.clear() // this ensures that we reset times everytime we read a new file
    times.clear();
    // create another for loop to iterate through all the elements from elem_to_find.
    for(int j =0;j<elem_to_find.size();j++){
        clock_t start_time = clock();
        iterativeSearch(v,elem_to_find[j]);
        clock_t end_time = clock();
        double elapsed_time_in_sec = (double(end_time-start_time)/CLOCKS_PER_SEC);
        times.push_back(elapsed_time_in_sec);

    }
    // the code here should be nearly identical to the code from the previous lab
    
    avg.push_back(average(times));
    }
    writeTimes("iterativeSearch_times.csv",avg, file_sizes);
    avg.clear();

    //binary search thing----------------------------------------------------------------------------------

    for(int i= 0; i < file_sizes.size(); i++) {
    // get the name/size of the file and assign it to string called filename
    string filename = to_string(file_sizes[i]) + "_numbers.csv";
    //call vecGen on filename and v
    vecGen(filename, v);

    // print filename (this will be good for debugging)
    cout<<"File used: "<<filename<<endl;

    // call times.clear() // this ensures that we reset times everytime we read a new file
    times.clear();
    // create another for loop to iterate through all the elements from elem_to_find.
    for(int j =0;j<elem_to_find.size();j++){
        //clock_t start_time = clock();
        auto start = chrono::high_resolution_clock::now();
        binarySearch(v,0,v.size(),elem_to_find[j]);
        //clock_t end_time = clock();
        auto end = chrono::high_resolution_clock::now();
        //double elapsed_time_in_sec = (double(end_time-start_time)/CLOCKS_PER_SEC);
        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
        times.push_back(duration.count());

    }
    // the code here should be nearly identical to the code from the previous lab
    
    avg.push_back(average(times));
    }
    writeTimes("binarySearch_times.csv",avg, file_sizes);

}
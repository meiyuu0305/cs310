#include <iostream>
#include <vector>

using namespace std;

/**
 * linearSearch function searches for search value by going through an array sequentially 
 * @param array is the location of the array itself. Does not create a new copy and does not change the original array
 * @param searchValue is the numeric value wants to find in an array 
 * @return a vector that has up to two indexes, if not, return a sentinal value
 */
vector<int> linearSearch(const vector<int>& array, int searchValue) {
    size_t size_arr = array.size();
    vector<int> result;
    for (int count = 0; count < size_arr; count++)
    {
        if(array.at(count) == searchValue && result.size() < 2) {result.push_back(count);}
        if(result.size()== 2) {return result;}
    }
    result.clear();
    result.push_back(-1);
    return result;
}
/**
 * Main function 
 * @return a number(0) when program successfully ran 
 */

int main() {
    int array_num[] = {10, 50, 16, 1, 9, 15, 16, 20, 16, 2, 5};
    vector<int> array(begin(array_num), end(array_num));
    int searchValue = 16;
    vector<int> searchResult = linearSearch(array, searchValue);
    for (int x : searchResult) {cout << x << " ";}
    return 0;
}

#include <iostream>
#include <vector>
#define NOT_FOUND 1
using namespace std; 

/**
   the linear search algorithm
   @param array an unsorted vector of values
   @param value the value to search for
   @return the position of value if found, or the size of the vector
*/
vector<int> linear_search(const vector<int>& array, int search_value, int&comp);

/**
* Returns a random number within the range low and high
*/
unsigned get_rand_in_range(unsigned low, unsigned high);

/**
* The main function
*/

int main()
{ 
  srand(time(0)); // in order to generate random numbers
  
  const int SIMUL_SIZE = 100000;
  const int VECTOR_SIZE = 1000;
  vector<int> test_values;
  double sumOfComparison = 0;
  int hits= 0;
  int miss = 0;
  int min;
  
  for(int i=0;i<SIMUL_SIZE; i++)
  { 
    // clearing the vector, so, we can start with an empty vector
    test_values.clear();
    
    // generating 1000 random values and storing them to the vector
    for(int k=0;k<VECTOR_SIZE;k++)
    {
      // random value in range 0 to 15000
      int value = get_rand_in_range(0, 15000);
      test_values.push_back(value); 
    }
    
    sort(test_values.begin(), test_values.end());
    
    // generating a random value to search in the vector
   // random value in range 0 to 15000
    int searchValue = get_rand_in_range(0, 15000);
    int comp = 0;
    // calling the function to search for the searchValue
    vector<int> results = linear_search(test_values, searchValue, comp); 
    if (i == 0 || comp <= min)
    {
      min = comp;
    }
    
    // determining whether we have found this element in the vector
    // not found runs will be counted to misses
    if(results[0] == -1){
      miss ++;
    }
    // found runs will be counted to hits
    else
    {  //cout<<"\nFound at "<<results<<". Number of comparisons "<< comp<<endl;
      hits ++;
    }
    
    // adding the number of comparisons to the sum
    sumOfComparison = sumOfComparison + comp;
  }
  
  // preparing the report to show the average comparison size
  cout <<"\nHits: " << hits << endl;
  cout<<"\nMiss: " << miss << endl;
  cout<<"\nMin steps: "<< min << endl;
  cout<<"\nAverage number of comparisons: " <<sumOfComparison/SIMUL_SIZE<<endl;


  return 0; // end of the main function
}



/*  search the element value inside the vector array
*   inside the comp variable we store the number of comparisons needed
*/

vector<int> linear_search(const vector<int>& array, int search_value, int & comp)
{
  size_t size = array.size();
  int found = 0;
  vector<int> result;
  for(size_t index =0; index<size;index++)
  { 
    comp ++ ; // counting the number of comparisons for the search
    if(array[index] == search_value && found < 2)
    {   
      result.push_back(index);
      found++;
    }
    
    if(result.size() == 2) {
      // end of the linear search function because found elements
      // Returning the position of the search value
      return result; 
      }
  }
    result.clear();
    result.push_back(-1);
    return result;
  // end of the linear serach function.
  // Return a sentinal number -1 
}


/**
* Returns a random number within the range low and high
*/
unsigned get_rand_in_range(unsigned low, unsigned high)
{
  int random_number=0;
  // generate the random number
  random_number = low + rand() % (high - low + 1);
  return random_number;
}




#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
  vector<int> a={144,3,6,4};
  cout << accumulate(a.begin(),a.end(),0) << endl;

  cout << accumulate(a.begin(),a.end(),2*a[0],minus<int>()) << endl;  

  cout << accumulate(a.begin(),a.end(),1,multiplies<int>()) << endl;

  cout << accumulate(a.begin(),a.end(),a[0]*a[0],divides<int>()) << endl; 
  
  return 0;
}

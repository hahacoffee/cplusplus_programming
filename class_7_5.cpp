#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
  vector<int> a{3,4,7,3};
  vector<int> b;

  adjacent_difference(a.begin(),a.end(),back_inserter(b));
  for(auto x:b)cout << x << " ";
  cout << endl;

  adjacent_difference(a.begin(),a.end(),ostream_iterator<int>(cout," "));
  cout << endl;

  return 0;
}

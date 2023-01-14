#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
  vector<int> a = {2,3,7,4,5,8,1};
  list<int> b = {9,3,1,7,5,6};
  sort(a.begin(),a.end());
  b.sort();

  cout << "A : ";
  for(auto x : a) cout << x << " ";
  cout << endl;
  cout << "B : ";
  copy( b.begin() , b.end() , ostream_iterator<int>(cout," ") );
  cout << endl;

  vector<int> c;
  set_difference(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));

  copy( c.begin() , c.end() , ostream_iterator<int>(cout," ") );
  cout << endl;

  vector<int> d;
  set_symmetric_difference(a.begin(),a.end(),b.begin(),b.end(),back_inserter(d));

  copy( d.begin() , d.end() , ostream_iterator<int>(cout," ") );
  cout << endl;
  
  return 0;
}

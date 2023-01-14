#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct odd{
  bool operator()(int n) const {
    return n%2==1;
  }
};

struct large_than{
  int a;
  large_than(int b):a(b){}
  bool operator()(int n) const {
    return n > a;
  }
};

int main(){
  vector<int> a = {12,3,5,7,1,36};
  cout << count(a.begin(),a.end(),5) << endl;

  int x;
  while(1){
    cin >> x;
    cout << count_if(a.begin(),a.end(),large_than(x)) << endl;
  }
  return 0;
}

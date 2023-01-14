#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iterator>

using namespace std;

int randint(int a,int b){
  return rand()%(b-a+1)+a;
}

int main(){
  srand( static_cast<unsigned>(time(NULL)));

  const int N = 11;
  int i,j,n,k;
  
  vector< set<int> > lottery(N);

  set<int> foo;
  vector<int> bar;

  for(i=0;i<N;++i){
    foo.clear();
    while(foo.size()<6){
      foo.insert(randint(1,49));
    }
    lottery[i]=foo;
  }

  for(int i=0;i<N;++i){
    cout << setw(2) << i << " : ";
    for(auto x : lottery[i]){
      cout << setw(2) << x << " "; 
    }
    cout << endl;
  }

  if(i>0){
    bar.clear();
    set_intersection(lottery[0].begin(),
		     lottery[0].end(),
		     lottery[i].begin(),
		     lottery[i].end(),
		     back_inserter(bar));
    cout << " : ["
	 << bar.size() << "] ";
    for(auto x : bar) cout << setw(2) << x << " ";
  }
  cout << endl;
  return 0;
}

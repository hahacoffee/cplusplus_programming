#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

template<class T>
struct randint{
  T operator()(const T& a,const T&b)const{

    return rand()%(b-a)+a;

  }
};

template<class T,class U>
void cout_container(const T& nums,const U& sign){
  typename T::const_iterator iter;
  for(iter=nums.begin();iter!=nums.end();++iter){
    cout << *iter ;
    if(iter!=nums.end()-1){ cout << sign;}
  }
  
  cout << endl;
}

template<class Compare_sum,class Compare_num>
struct large_digit_sum{
  bool operator()(const int&a,const int&b){
     
	if((a/10+a%10)==(b/10+b%10)){
	  return Compare_num()(a,b);
        }
	else{
	  return Compare_sum()(a/10+a%10,b/10+b%10);
	}  
  }
};

int  main() {

    srand( static_cast<unsigned>(time(NULL)) ) ;

    char  data[] = "hw2.dat" ;

    ofstream  outfile(data) ;

    int i , j , n , maxline ;

    maxline = randint<int>()(10,30) ;

    for ( i = 0 ; i < maxline ; ++i ) {

      n = randint<int>()(3,7) ;
        for ( j = 0 ; j < n ; ++j ) {

	  outfile << randint<int>()(5,99) << " " ;
        }
        outfile << endl ;
    }
    outfile.close() ;

    ifstream  infile(data) ;
    istringstream  istr ;
    string    line ;
    vector<int>  nums ;
    int  no ;

    i = 1 ;

    while ( getline(infile,line) ) {
        istr.str(line) ;

        while ( istr >> no ) nums.push_back(no) ;
        istr.clear() ;

        cout << "[" << i++ << "]" << endl ;

 
        cout_container( nums , " , " ) ;

 
        sort( nums.begin() , nums.end() , large_digit_sum<greater <int>,greater <int>>() ) ;

        cout_container( nums , " --> " ) ;

        cout << endl ;
        nums.clear() ;

    }

}


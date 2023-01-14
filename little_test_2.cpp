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
  T operator()(const T& a,const T& b)  {return rand()%(b-a)+a+1;}
};

template<class T>
struct randint1{
  T no,no2;
  randint1():no(rand()%10), no2(0){};
  T operator()()  {if(no!=0){ return no;}
                   if(no==0){ return no2;}}
};

template<class T>
struct randint2{  
  T operator()(const T& a,const T& b)  {return rand()%10;}
};

template<class T>
struct randchar{  
  T operator()()  { return 'A'+rand()%26;}
};

template<class T>
void cout_container(const T& item){
  /*  typename T::INT iter;
  typename T::CHAR iter2;
  iter2=item.engligh[0];
  for(iter=item.number.begin();iter!=item.end();iter=iter+2){
    cout << *iter2;
    cout << '-';
    cout << *iter << *iter+1;
    ++iter2;
    }*/
  cout << item.english[0];
 cout << '-';
  cout << item.number[0];
  //  cout << item.number[1];  
  cout << endl;
}


template<class INT,class CHAR>
struct four{
  INT num;
  four():num(4){};
  vector<INT> number;
  vector<CHAR> english;
  vector<CHAR> other;
};

int main(){
  srand( static_cast<unsigned>(time(NULL)) ) ;

  char  data[] = "little_test_2.dat" ;

  ofstream outfile(data
		   );
  int i,j,maxcolumn,maxrow;

  maxrow = randint<int>()(5,10);
  for(i=0;i<maxrow;++i){
    maxcolumn=randint<int>()(3,10);
    for(j=0;j<maxcolumn;++j){
      outfile << randchar<char>()() << '-'<< randint1<int>()()  << randint2<int>()(1,99) << " ";
    }
    outfile << endl;
  }
  outfile.close();

    ifstream  infile(data) ;
    istringstream  istr ;
    string    line ;
    four<int,char>  item ;
    char no1 ;
    int  no2 ;
    int f;

    while ( getline(infile,line) ) {
        istr.str(line) ;
	

	istr >> no1;
	item.english.push_back(no1);
	istr >> no1;
item.other.push_back(no1);
	istr >> no2;
	item.number.push_back(no2);
	//	istr >> no2;
	//	item.number.push_back(no2);
	
	istr.clear();
 
        cout_container(item) ;


    }
  
  return 0;
}




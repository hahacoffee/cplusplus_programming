#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class randomitem{
private:
  char alphabet;
  char sign;
  int number;
  char space;
public:
  randomitem():space(' '){}
  char get_alphabet() const {return alphabet;}
  char get_sign() const {return sign;}
  int get_number() const {return number;}
  char get_space() const {return space;}
  friend ostream& operator<< (ostream& out, const randomitem& foo);
  friend istream& operator>> (istream& in, const randomitem& foo1);
};

ostream& operator<< (ostream& out, const randomitem& foo){
  return out << foo.alphabet << foo.sign << foo.number << foo.space; 
}

istream& operator>> (istream& in, const randomitem& foo1){
  return in >> foo1.alphabet >> foo1.sign >> foo1.number >> foo1.space;
}

template<class T>
struct randint{  
  T operator()(const T& a,const T& b)  {return rand()%(b-a)+a+1;}
};

template<class T>
struct randint1{  
  T operator()()  {return rand()%3;}
};

template<class T>
struct randint2{  
  T operator()(const T& a,const T& b)  {return rand()%9+1;}
};

template<class T>
struct randchar{  
  T operator()()  { return 'A'+rand()%26;}
};


int main(){
  srand(static_cast<unsigned>(time(NULL)));

  char data[]="wm2.dat";
  ofstream outfile(data);
  int i,j,maxcolumn,maxrow;

  maxrow = randint<int>()(3,10);
  for(i=0;i<maxrow;++i){
    maxcolumn=randint<int>()(3,10);
    for(j=0;j<maxcolumn;++j){
      outfile << randchar<char>()() << '-'<< randint1<int>()()  << randint2<int>()(1,20) << " ";
    }
    outfile << endl;
  }
  outfile.close();

  //input

  ifstream infile(data);
  istringstream istr;
  string line;
  vector<randomitem> items;
  randomitem no;
  while(getline(infile,line)){
    istr.str(line);
    while(istr >> no){items.pushback(no)}
      istr.clear();
      sort(item.begin(),item.end(),to_compare())
	//	cout_container(item);
	cout << endl;
      item.clear();
  }
  
  return 0;
}

template<class Compare_number,class Compare_alphabet>
struct to_compare{
  bool operator()(const randomitem& a,const randomitem& b){
    if(a.number!=b.number){return Compare_number()(a.get_number(),b.get_number());}
    else{return Compare_alphabet()(a.get_alphabet(),b.getalphabet);}
  }
};

/*template<class >
void cout_container(){

}*/

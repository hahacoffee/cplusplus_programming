// 黃俊維
// 105303011
// 機械3A

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <queue>

using namespace std;

class Word{
private:
  int uno;
  int sno;
public:
  Word(){}
  Word(int num1,int num2):uno(num1),sno(num2){}
  int sn() const {return sno;}
  int un() const {return uno;}
  friend struct Rule;
};

struct Rule{
  bool operator()(const Word& a,const Word& b) const {
    return (a.sno == b.sno ? b.uno < a.uno : b.sno < a.sno);
  }
};

int main(){
  setlocale(LC_ALL,"zh_TW.UTF-8");
  wifstream infile("strokes.dat");
  wstring ustr;
  priority_queue<Word,vector<Word>, Rule > so;
  while(getline(infile,ustr)){
    int no1,no2;
    wistringstream istr(ustr.substr(2));
    istr >> hex >> no1 >> no2;
    istr.clear();
    so.push(Word(no1,no2));
    ustr.clear();
  }
  int loop;
  int count;
  Word foo1,foo2;

  count=0;
  while(!so.empty()){
  
    for(loop=0;loop<10;++loop){
      foo1=so.top();
      int number;
      number=foo1.sn();
      if(number!=count && loop!=0){wcout << endl << endl << dec << number << L" 劃：" << endl; count=number;}
      if(number!=count && loop==0){wcout << endl << dec << number << L" 劃：" << endl; count=number;}
      wcout << static_cast<wchar_t>(foo1.un()) << L" [" << hex << foo1.un() << L"] " << L" ";
      so.pop();
      if(so.empty()){loop=9;}
    }
    wcout << endl;
  }

  return 0;
}

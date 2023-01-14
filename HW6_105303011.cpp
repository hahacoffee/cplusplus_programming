#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <iomanip>
#include <queue>
#include <stdio.h>

using namespace std;

int str2int(const string& foo){
  istringstream istr(foo);
  int n;
  istr >> hex >> n;
  return n;
}

map<wchar_t,int> wchs;
wchar_t sam;

struct Equal{
  bool operator()(const wchar_t& a,const wchar_t& b) const {
    return wchs[a]==wchs[b];
  }
};

struct Word{
  wstring wor;
  int s;
  Word(const wstring& a,int b):wor(a),s(b){}
};

bool operator>(const Word& a,const Word& b){
  return a.s<b.s;
}

wostream& operator<<(wostream& out, const Word& foo){
  return out << foo.wor;
}

int main(){

  setlocale(LC_ALL,"zh_TW.UTF-8");
  ifstream sinfile("strokes.dat");
  string line,str;
  int n;
  istringstream istr;
  wchar_t wch;
  
  while(getline(sinfile,line)){
    istr.str(line);
    istr >> str >> n;
    wch = static_cast<wchar_t>(str2int(str.substr(2)));
    wchs[wch]=n;
    istr.clear();    
  }

  wifstream pinfile("old_poem19_16.dat");
  pinfile.imbue(locale("zh_TW.UTF-8"));
  wstring wline,wpoem;
  vector<wchar_t> wpoems;
  wstringstream istr2;
  vector<wchar_t>::iterator iter,iter2;
  priority_queue< Word, vector<Word> , greater<Word> > sor;
  
  while(getline(pinfile,wpoem)){
    
    for(int i=0;i<4;++i){
      istr2.str(wpoem.substr(i*6));
      while(istr2 >> wline){
	for(int i=0;i<5;++i){
	  wpoems.push_back(wline[i]);
	}
      }
      istr2.clear();
    }
  }
  wchar_t sam2,ch1,lsam1,lsam2,special;
  int count=0;
  int special_num;

  sam=*(wpoems.begin());
  ch1=*(wpoems.end());
  while(sam!=*(wpoems.end())){
    sam=*(adjacent_find(wpoems.begin(),wpoems.end(),Equal()));
    
    while(ch1!=sam){
      ch1=*(wpoems.begin());
      wpoems.erase(wpoems.begin());
    }

    sam2=*(wpoems.begin());

    if(sam!=sam2 || count==0){

      if(lsam2==sam){
	special=sam2;
	special_num=wchs[sam2];
      }
      else{
        wchar_t x[1];
	for(int i=0;i<3;++i){
	  if(i==0){x[0]=sam;}
	  if(i==1){x[1]=static_cast<wchar_t>(' ');}
	  if(i==2){x[2]=sam2;}
	}
	wstring ss=x;

	sor.push(Word(ss,wchs[sam]));
      }
      
    }
    lsam1=sam;
    lsam2=sam2;
    count=count+1;
  }
  
  int num;
  int num1=0;
  int count2=0;
  
  while(sor.empty()!=1){
    num=(sor.top()).s;
    if(num>9 && count2!=0){wcout << endl << num << L" : ";}
    else if(num>9 && count2==0){wcout << num << L" : ";}
    else{wcout << endl << L" " << num << L" : "; }
    wcout << (sor.top()).wor ;
    if(num==special_num){wcout << L" " << special;}
    sor.pop();
    count2=count2+1;
  }
  wcout << endl;
  return 0;
}

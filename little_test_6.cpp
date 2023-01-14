#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  setlocale(LC_ALL,"zh_TW.UTF-8");
  wifstream infile("poem_wang.dat");
  infile.imbue(locale("zh_TW.UTF-8"));
  wstring line,str;
  wistringstream istr;
  wostringstream ostr;
  vector<wchar_t> pline;
  vector<wchar_t>::iterator iter;
  vector<wchar_t>::iterator iter2;
  vector<wchar_t>::iterator iter3;
  vector<wchar_t> oline;
  wchar_t temp;
  int i;
  int num;
  num=-1;
  while(getline(infile,line)){
    istr.str(line);
    istr >> str;
    i=0;
    
    while(1){     
      temp=str[i];
      if(temp==L'\0'){break;}
      pline.push_back(temp);
      i=i+1;     
    }

    iter2=unique(pline.begin(),pline.end());

    for(iter=pline.begin();iter!=iter2;++iter){
      if(num==-1){oline.push_back(*iter);num=num+1;}
      if(num!=-1 && *iter!=oline[num]){
      oline.push_back(*iter);
      num=num+1;
      }
    }
    pline.clear();
    istr.clear();
  }

  int h=5;
  int no;
  for(int row=0;row<5;++row){
    for(int col=0;col<8;++col){
      no=35-col*h+row;
      wcout << oline[no];
    }
    wcout << endl;
  }
  wcout << endl;
  return 0;
}

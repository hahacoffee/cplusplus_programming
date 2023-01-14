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
  vector<wchar_t> pline;
  vector<wchar_t>::iterator iter;
  wchar_t temp;
  int i;
  
  while(getline(infile,line)){
    istr.str(line);
    istr >> str;
    i=0;
    
    while(1){     
      temp=str[i];
      if(temp==L'。'){break;}
      pline.push_back(temp);
      i=i+1;     
    }

    unique(pline.begin(),pline.end());

    for(iter=pline.begin();iter!=pline.begin()+11;++iter){
      wcout << *iter;
    }
    wcout << L'。' << endl;
    pline.clear();
    istr.clear();
  }
  return 0;
}

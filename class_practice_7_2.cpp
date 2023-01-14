#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

int main(){

  setlocale(LC_ALL,"zh_TW.UTF-8");
  wifstream infile("class.dat");
  wstring line,str,course;
  int k,n,i,j;
  infile.imbue(locale("zh_TW.UTF-8"));

  map< wstring,set< wstring > > cc;
  wstring cnum=L" 一二三四五";
  wistringstream istr;
  wostringstream ostr;
  
  i=1;
  while(getline(infile,line)){
    if(i>2 and i!=7){
      istr >> n >> str;
      k=1;
      while(istr >> course){
	if(course!=L"--"){
	  ostr << cnum[k] << L":" << n; 
	  cc[course].insert(ostr.str());
	  ostr.str(L"");
	}

	k+=1;
      }
      istr.clear();
    }
    i=i+1;
  }

  for(auto x:cc){
    wcout << x.first << " : ";
    for(auto y:x.second){
      wcout << y << " ";
    }
    wcout << endl;
  }
  
  return 0;
}

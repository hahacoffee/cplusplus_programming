#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int str2int(const string& foo){
  istringstream istr(foo);
  int n;
  istr >> hex >> n;
  return n;
}

map<wchar_t,int> wchs;

struct by_small_strokes{
  bool operator() (const wstring& a,const wstring& b) const {
    for(int i = 0;i<a.size();++i){
      if(wchs[a[i]]!=wchs[b[i]]){
	return wchs[a[i]] < wchs[b[i]];
      }
    }
    return false;
  }
};

int main(){
  setlocale(LC_ALL,"zh_TW.UTF-8");
  ifstream sinfile("strokes.dat");
  string line,str;
  istringstream istr,istr2;
  int i,j,k,n,s;
  wchar_t wch;
  while(getline(sinfile,line)){
    istr.str(line);
    istr >> str >> n;
    wch = static_cast<wchar_t> (str2int(str.substr(2)));
    wchs[wch]=n;
    istr.clear();
    
  }

  wifstream sfile("idioms.dat");
  sfile.imbue(locale("zh_TW.UTF-8"));
  wstring wline,wstr,widiom;
  map< int,set<wstring,by_small_strokes > > s2i;

  while(getline(sfile,widiom)){
    s=0;
    for(auto x : widiom) s += wchs[x];
    s2i[s].insert(widiom);
  }
      
  for(auto x : s2i){
    wcout << x.first << " : ";
    for(auto y : x.second){
      wcout << y << " ";
    }
    wcout << endl;
  }
    
  
  return 0;
}

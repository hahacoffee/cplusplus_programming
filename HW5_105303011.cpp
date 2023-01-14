// 黃俊維
// 105303011
// 機械3A

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

int main(){
  
  char data[]="idioms.dat";    
  setlocale(LC_ALL,"zh_TW.UTF-8");
  wifstream infile(data);
  infile.imbue(locale("zh_TW.UTF-8"));    
  wistringstream istr,istr2,istr3;
  wstring line;
  vector<wstring> idioms;
  vector<wchar_t> idioms2;
  wstring idiom;
  int count;
  vector<wstring> n1,n2,n3;
  vector<wstring>::iterator iter,iter2,iter3;
  int k,j,l,m;
    
  while( getline(infile,line) ){
    istr.str(line);
    while( istr >> idiom ){
      idioms.push_back(idiom);
    }	
    istr.clear();
  }
  infile.close();
  wifstream infile2(data);
  infile2.imbue(locale("zh_TW.UTF-8"));    
  while( getline(infile2,line) ){
    istr.str(line);
    while( istr >> idiom ){     
      for(k=0;k<idioms.size();++k){
	count=0;	
	for(j=0;j<4;++j){	      
	  istr2.str(idioms[k]);
	  wstring temp;
	  int pointer;
	  istr2 >> temp;
	  for(l=0;l<4;++l){
	    pointer=0;
	    if(idioms2.empty()!=0){
	      for(m=0;m<idioms2.size();++m){
		if(idiom[j]==idioms2[m]){pointer=1;}
	      }
	    }
	    if(idiom[j]==temp[l] && pointer==0){
	      count=count+1;
	      idioms2.push_back(temp[l]);
	    }		
	  }
	  istr2.clear();
	}
	if(count==1){n1.push_back(idioms[k]);}
	if(count==2){n2.push_back(idioms[k]);}
	if(count==3){n3.push_back(idioms[k]);}
      }
      idioms2.clear();
      wcout << idiom << endl;      
      if(n1.empty()!=1 || n2.empty()!=1 || n3.empty()!=1){
	if(n3.empty()!=1){
	  wcout << "> 3 :";	  
	  for(iter3=n3.begin();iter3!=n3.end();++iter3){wcout << " " << *iter3;}
	  wcout << endl;
	  n3.clear();
	}
	if(n2.empty()!=1){
	  wcout << "> 2 :";	  
	  for(iter2=n2.begin();iter2!=n2.end();++iter2){wcout << " " << *iter2;}
	  wcout << endl;
	  n2.clear();
	}
	if(n1.empty()!=1){
	  wcout << "> 1 :";
	  for(iter=n1.begin();iter!=n1.end();++iter){wcout << " " << *iter;}
	  wcout << endl;
	  n1.clear();
	}	
      }
      wcout << endl;
    }
    istr.clear();
  }
}

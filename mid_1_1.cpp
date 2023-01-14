#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class Poem{
private:
  wstring poemsentence;
  int word;
  int sentence;
public:
  Poem(wstring& a,int b,int c){
    poemsentence=a;
    word=b;
    sentence=c;
  }
  wstring getline(int r) const {
    wstring row;   
    if(r<word){
      for(int n=0;n<sentence;++n){
	row=row+poemsentence[(word*sentence-word)-n*word+r];
      }
    }
    else{
      for(int n=0;n<sentence;++n){
	row=row+L" ";
      }
    }
    return row;
  }
};

class Show_Poem{
private:
  vector<Poem> poems;
public:
  Show_Poem(string filename){
    wifstream infile(filename);
    infile.imbue(locale("zh_TW.UTF-8"));
    wstring line;
    int wor,sen;
    while(getline(infile,line)){
      if(line.size()%5==0){
	wor=5;
	sen=line.size()/5;
      }
      if(line.size()%7==0){
	wor=7;
	sen=line.size()/7;
      }
      poems.push_back(Poem(line,wor,sen));
    }
  }
  
  void shuffle(){
    int i,j;
    for(i=poems.size()-1;i>0;--i){
      j=rand()%(i+1);
      if(i!=j){
	swap(poems[i],poems[j]);
      }
    }
  }  
  friend wostream& operator<<(wostream& out,const Show_Poem& foo){
    
    for(int row=0;row<7;++row){
      for(int num=0;num<foo.poems.size();++num){
	out << foo.poems[num].getline(row) << L" ";
      }
      out << endl;
    }
    return out;
    
  }
};
int main(){
  srand(static_cast<unsigned>(time(NULL)));
  setlocale(LC_ALL,"zh_TW.UTF-8");
  Show_Poem poems("poem.dat");
  poems.shuffle();
  wcout << poems << endl;
  return 0;
}

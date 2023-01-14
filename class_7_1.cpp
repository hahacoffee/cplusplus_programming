#include <iostream>

using namespace std;

int main(){
  setlocale(LC_ALL,"zh_TW.UTF-8");
  wstring foo=L"空空空山山不見見人，但聞聞人人語響響。";

  auto iter=unique(foo.begin(),foo.end(),my_rule());

  for(anto iter2=foo.begin();iter2!=iter;++iter2){
    wcout << iter2;
  }
  wcout << endl;
  return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

class Color{
private:
  string cname;
  int r,g,b;  
public:
  Color(){};
  Color(string s,int r2,int g2,int b2):cname(s),r(r2),g(g2),b(b2){}

  string colorname() const {return cname;}
  double distance(const Color& c2) const {
    return sqrt(2*pow(c2.r-r,2)+4*pow(c2.g-g,2)+3*pow(c2.b-b,2)+((c2.r+r)/2)*((pow(c2.r-r,2)-pow(c2.b-b,2))/256));    
  }

  friend ostream& operator<<(ostream& out,const Color& foo){
    return out << hex << setfill('0')
	       << setw(2) << foo.r << setw(2) << foo.g << setw(2) << foo.b
	       << " " << foo.cname << dec << setfill(' ');
  }
  friend struct By_Small_Color_Distance;
};

struct By_Small_Color_Distance{
  Color c;
  By_Small_Color_Distance(const Color& color):c(color){}
  bool operator()( const Color& c1,const Color& c2) const  {
    return c.distance(c1) < c.distance(c2);
  }
};

int str_to_int(const string& str){
  istringstream istr;
  istr.str(str);
  int num;
  istr >> num;
  return num;
}

int main(){
  char data[] = "rgb.dat";
  ifstream infile(data);
  istringstream istr;
  string line,color,red,green,blue;
  vector<string> c;
  vector<int> r,g,b;
  int i,j,k,l;
  int rr,gg,bb;
  string choose;
  int rr2,gg2,bb2;
  string cc2;
  i=0;
  j=0;
  k=0;
  l=0;
  cout << ">>";
  cin >> choose;
  
  while(getline(infile,line)){
    istr.str(line);
    while(istr >> color >> red >> green >> blue){
      c.push_back(color);
      rr=str_to_int(red);
      gg=str_to_int(green);
      bb=str_to_int(blue);
      if(choose==color){cc2=color;rr2=rr;gg2=gg;bb2=bb;}
      r.push_back(rr);
      g.push_back(gg);
      b.push_back(bb);
    }
    istr.clear();

    i=i+1;
  }
  Color datacolor[i];
  Color comp;
  for(j=0;j<i;++j){
    datacolor[j]=Color(c[j],r[j],g[j],b[j]);
    if(c[j]==cc2 && r[j]==rr2 && g[j]==gg2 && b[j]==bb2){comp=datacolor[j];}
  }
  By_Small_Color_Distance By_Small_Color_Distance(comp);

  sort(datacolor,datacolor+i,By_Small_Color_Distance);
  
  for(k=1;k<11;++k){
    cout << setw(2) << setfill(' ') << k << ":" << setw(8) << setfill(' ') << setprecision(4) << comp.distance(datacolor[k]) << " " << datacolor[k] << endl;
  }
  return 0;
}

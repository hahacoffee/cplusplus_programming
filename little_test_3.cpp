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
  /* int colorsort(const string& str) const  {
    istringstream istr;
    istr.str(str);
    int a;
    istr >> a;
    return a;      
    }*/
  string colorname() const {return cname;}
  double distance(const Color& c2) const {
    return sqrt(2*pow(c2.r-r,2)+4*pow(c2.g-g,2)+3*pow(c2.b-b,2)+((c2.r+r)/2)*((pow(c2.r-r,2)-pow(c2.b-b,2))/256));    
  }

  friend ostream& operator<<(ostream& out,const Color& foo){
    return out << hex << setfill('0')
	       << setw(2) << foo.r << setw(2) << foo.g << setw(2) << foo.b
	       << " " << foo.cname << dec << setfill(' ');
  }
  friend struct By_name;
};

struct By_name{
  
  bool operator()( const Color& c1,const Color& c2) const  {
    // return c.colorsort(c1.cname) < c.colorsort(c2.cname);
    return c1.colorname()>c2.colorname();
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
  int i,j,k,l,m,n;
  int rr,gg,bb;
  int dis;
  int rr2,gg2,bb2;
  string cc2;
  int pointer;
  pointer=0;
  i=0;j=0;k=0;l=0;m=0;n=0;
  cout << ">>";
  cin >> dis;
  cout << ">>no of color in distance in " << dis << ":" << endl; 
  
  while(getline(infile,line)){
    istr.str(line);
    while(istr >> color >> red >> green >> blue){
      c.push_back(color);
      rr=str_to_int(red);
      gg=str_to_int(green);
      bb=str_to_int(blue);
      r.push_back(rr);
      g.push_back(gg);
      b.push_back(bb);
    }
    istr.clear();

    i=i+1;
  }
  Color datacolor[i];
  Color comp[i];
  vector<Color> show;
  int count;
  vector<int> number;
  count=0;
  for(j=0;j<i;++j){
    datacolor[j]=Color(c[j],r[j],g[j],b[j]);
    comp[j]=datacolor[j];
    //    By_Small_Color_Distance By_Small_Color_Distance(comp);
  }

  
  sort(datacolor,datacolor+i,By_name());
   for(j=0;j<i;++j){ 
    for(m=0;m<i;++m){
      if(dis>comp[j].distance(datacolor[m]) && comp[j].distance(datacolor[m])>0){count=count+1;}
    }
    number.push_back(count);
    if(count>0) cout << datacolor[j].colorname() << " : " << count << endl;
    count=0;
  }


  
  return 0;
}


#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<math.h>

using namespace std;

struct By_Name ;
class Color{
private :
  string cname ;
  int r , g , b ;
public :
  Color(){}

  Color( string s , int r2 , int g2 , int b2 ) : cname(s) , r(r2) , g(g2) ,
b(b2){}

  string colorname() const{return cname ;}

  double distance( const Color& c2 ) const{
    double dr,dg,db,mr;
    dr = r-c2.r;
    dg = g-c2.g;
    db = b-c2.b;
    mr = (r+c2.r)/2;

    double dis = 2*dr*dr + 4*dg*dg + 3*db*db + mr*( dr*dr - db*db )/256;

    return sqrt(dis);
  }

  friend ostream& operator<<( ostream& out , const Color& foo ){
    return out << hex << setfill('0') << setw(2)
           << foo.r << setw(2) << foo.g
           << setw(2) << foo.b<< " " << foo.cname
           << dec << setfill(' ') ;
  }

  friend struct By_Name;
};

//sort by name
struct By_Name{
  bool operator() ( const Color& c1 , const Color& c2 ) const{
    return  c1.cname < c2.cname;
  }
};

int main(){
  string data = "rgb.dat";
  ifstream infile( data.c_str() );
  istringstream istr;

  string line;
  string cname;
  int r,g,b;

  vector<Color> vc;

  // input data
  while( getline(infile , line ) ){
    istr.str( line );
    istr >> cname >> r >> g >> b;
    vc.push_back( Color(cname,r,g,b) );
    istr.clear();
  }

  // input distance
  double dis;
  cout << "> ";
  cin >> dis;

  cout << ">> no of color distance in " << dis << " :" << endl;

  // sort by name
  sort( vc.begin(),vc.end(),By_Name() );

  // calculate near color
  for(int i=0;i<vc.size();++i){
    int cc = -1; // delete the samee color(distance=0)

    for(int j=0;j<vc.size();++j){
      if( vc[i].distance( vc[j] ) < dis ){
    cc ++;
      }
    }

    if( cc != 0 ){
      cout << vc[i].colorname() << " : " << cc << endl;
    }
  }

}

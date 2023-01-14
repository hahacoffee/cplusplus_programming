// 黃俊維
// 105303011
// 機械3A
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
int rand_int(int a,int b){
  return rand()%(b-a+1)+a;
}
int main(){
  srand(static_cast<unsigned>(time(NULL)));
  int i,j,k,l,m,n;
  int ml,pl,ol,cl,il,al,sl;
  vector<int> check;
  ml=10;pl=9;ol=10;cl=9;il=4;al=1;sl=2;
  int sw,sn,sh,swi,opo,limit,limit2;
  int sw1,sw2,sw3,sw4;
  int bk1,bk2,bk3,bk4;
  int r1,r2,r3,r4;
  int spacial,count,choose,temp;
  int mc,pc,oc,cc,ic,ac,sc;
  mc=1;pc=1;oc=1;cc=1;ic=1;ac=1;sc=1;spacial=0;count=0;limit2=0;swi=0;opo=0;
  sw1=rand_int(0,6);sw2=rand_int(0,6);sw3=rand_int(0,6);sw4=rand_int(0,6);
  for(n=0;n<4;++n){
    if(n==0) temp=sw1; if(n==1) temp=sw2; if(n==2) temp=sw3; if(n==3) temp=sw4;
    switch(temp){
    case 0:
      mc=mc+1;
      break;
    case 1:
      pc=pc+1;
      break;
    case 2:
      oc=oc+1;
      break;
    case 3:
      cc=cc+1;
      break;
    case 4:
      ic=ic+1;
      break;
    case 5:
      ac=ac+1;
      break;
    case 6:
      sc=sc+1;
      break;
    }
  }
  cout << "各系比賽名單:" << endl;
  for(sw=0;sw<7;++sw){  
    if(sw==0) {limit=ml;cout << "ma(07/10) : ";} if(sw==1) {limit=pl;cout << "py(08/09) : ";} if(sw==2) {limit=ol;cout << "op(11/10) : ";}
    if(sw==3) {limit=cl;cout << "ch(09/09) : ";} if(sw==4) {limit=il;cout << "ip(07/04) : ";} if(sw==5) {limit=al;cout << "as(01/01) : ";}
    if(sw==6) {limit=sl;cout << "st(02/02) : ";}
    if(sw==sw1) {limit=limit+1;limit2=limit2+1;} if(sw==sw2) {limit=limit+1;limit2=limit2+1;}
    if(sw==sw3) {limit=limit+1;limit2=limit2+1;} if(sw==sw4) {limit=limit+1;limit2=limit2+1;}  
  for(l=0;l<limit;++l){
      j=0;
      sn=rand_int(1,(limit*10));
      check.push_back(0);
      for(k=0;k<check.size();++k){
	if(sn==check[k]){
	  j=j+1;
	}
      }
      if(j==0){
	check.push_back(sn);
	if(l==(limit-limit2)) spacial=1;
	if(spacial==1 && swi==0) {cout << "[ ";swi=1;}	
	if(sw==0 && mc>0) {cout << "ma_" << setw(3) << setfill('0') << sn << " "; if(spacial==1){mc=mc-1;opo=opo+1;if(mc==1){swi=0;}}}
	if(sw==1 && pc>0) {cout << "py_" << setw(3) << setfill('0') << sn << " "; if(spacial==1){pc=pc-1;opo=opo+1;if(pc==1){swi=0;}}}
	if(sw==2 && oc>0) {cout << "op_" << setw(3) << setfill('0') << sn << " "; if(spacial==1){oc=oc-1;opo=opo+1;if(oc==1){swi=0;}}}
	if(sw==3 && cc>0) {cout << "ch_" << setw(3) << setfill('0') << sn << " "; if(spacial==1){cc=cc-1;opo=opo+1;if(cc==1){swi=0;}}}
	if(sw==4 && ic>0) {cout << "ip_" << setw(3) << setfill('0') << sn << " "; if(spacial==1){ic=ic-1;opo=opo+1;if(ic==1){swi=0;}}}
	if(sw==5 && ac>0) {cout << "as_" << setw(3) << setfill('0') << sn << " "; if(spacial==1){ac=ac-1;opo=opo+1;if(ac==1){swi=0;}}}
	if(sw==6 && sc>0) {cout << "st_" << setw(3) << setfill('0') << sn << " "; if(spacial==1){sc=sc-1;opo=opo+1;if(sc==1){swi=0;}}}	
	if(spacial==1 && opo>0 && count==0) {r1=sw;bk1=sn;count=count+1;opo=opo-1;}
	if(spacial==1 && opo>0 && count==1) {r2=sw;bk2=sn;count=count+1;opo=opo-1;}
	if(spacial==1 && opo>0 && count==2) {r3=sw;bk3=sn;count=count+1;opo=opo-1;}
	if(spacial==1 && opo>0 && count==3) {r4=sw;bk4=sn;count=count+1;opo=opo-1;}	
	if(spacial==1 && swi==0) {cout << "]";spacial=0;limit2=0;}
	l=l+1;
      }
      l=l-1;
  }
  check.clear();
  cout << endl;
  }
  cout << endl;
  cout << "候補順序:"<< endl;
  for(m=0;m<4;++m){
    if(m==0){cout << "1 : ";choose=r1;sh=bk1;} if(m==1){cout << "2 : ";choose=r2;sh=bk2;}
    if(m==2){cout << "3 : ";choose=r3;sh=bk3;} if(m==3){cout << "4 : ";choose=r4;sh=bk4;}
    switch(choose){
    case 0:
      cout << "ma_" << setw(3) << setfill('0') << sh << endl;
      break;
    case 1:
      cout << "py_" << setw(3) << setfill('0') << sh << endl;
      break;
    case 2:
      cout << "op_" << setw(3) << setfill('0') << sh << endl;
      break;
    case 3:
      cout << "ch_" << setw(3) << setfill('0') << sh << endl;
      break;
    case 4:
      cout << "ip_" << setw(3) << setfill('0') << sh << endl;
      break;
    case 5:
      cout << "as_" << setw(3) << setfill('0') << sh << endl;
      break;
    case 6:
      cout << "st_" << setw(3) << setfill('0') << sh << endl;
      break;
    }
  }
  return 0;
}


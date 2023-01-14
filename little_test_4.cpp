#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

class Card{
private:
  int card_number;
  char color;
public:
  Card(){}
  Card(const int& a,const char& b):card_number(a),color(b){}
  int gn() const {return card_number;}
  char gc() const {return color;}
  friend bool operator>(const Card& a,const Card& b){
    return (b.color == a.color ? b.card_number < a.card_number : b.color < a.color);
  }
  friend bool operator<(const Card& a,const Card& b){
    return (b.color == a.color ? b.card_number > a.card_number : b.color > a.color);
  }
  friend ostream& operator<<(ostream& out,const Card& foo){
    if(foo.gn()==11){return out << foo.gc() << setw(3) << setfill(' ') << "J";}
    else if(foo.gn()==12){return out << foo.gc() << setw(3) << setfill(' ') << "Q";}
    else if(foo.gn()==13){return out << foo.gc() << setw(3) << setfill(' ') << "K";}
    else if(foo.gn()==14){return out << foo.gc() << setw(3) << setfill(' ')  << "A";}
    else{return out << foo.gc() << setw(3) << setfill(' ') << foo.gn();}   
  }
};

int rand_int(int a, int b){
  return rand()%(b-a+1)+a;
}



int main(){
  srand(static_cast<unsigned>(time(NULL)));
  int players = 4;
  int cardno = 5;
  vector < priority_queue< Card,vector<Card>,greater<Card> > > cards(players);
  vector<Card> poker;
  int c,n;
  for(c=0;c<4;++c){
    switch(c){
    case 0:
      for(n=2;n<=14;++n){
	poker.push_back(Card(n,'C'));
      }
      break;
    case 1:
      for(n=2;n<=14;++n){
	poker.push_back(Card(n,'D'));
      }
      break;
    case 2:
      for(n=2;n<=14;++n){
	poker.push_back(Card(n,'H'));
      }
      break;
    case 3:
      for(n=2;n<=14;++n){
	poker.push_back(Card(n,'S'));
      }
      break;
    }
  }
  
  int number,target;
  for(number=51;number>0;--number){
    target=rand_int(1,number);
    if(target!=number) swap(poker[target],poker[number]);
  }
  
  int play,num,count;
  count=0;
  for(play=0;play<4;++play){
    for(num=0;num<cardno;++num){
      cards[play].push(poker[count]);
      count=count+1;
    }
  }
  

  int no;
  no=1;

  priority_queue< Card,vector<Card>,less<Card> > turn;
  
  for(num=0;num<cardno;++num){
    cout << no << " : "; 
    for(play=0;play<4;++play){
      cout.setf(ios::adjustfield,ios::left);
      cout << cards[play].top();
      turn.push(cards[play].top());
      cards[play].pop();
    }
    cout << "  -->  ";
    for(play=0;play<4;++play){
      cout.setf(ios::adjustfield,ios::left);
      cout << turn.top();
      turn.pop();
    }
    cout << endl;
    no=no+1;
  }
  return 0;
}

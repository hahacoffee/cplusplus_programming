// 黃俊維
// 105303011
// 機械3A

#include <iostream>
#include <functional>
#include <cassert>
#include <initializer_list>

using namespace std;

template<typename T>
struct Node{
  T data;
  Node<T>* fptr;
  Node<T>* bptr;

  Node():fptr(NULL),bptr(NULL){}
  Node(const T& no):data(no),fptr(NULL),bptr(NULL){}  
};

template<typename T>
ostream& operator<<(ostream& out,const Node<T>& foo){
  return out << foo.data;
}

template<typename T>
ostream& operator<<(ostream& out,const Node<T>* foo){
  return out << foo->data;
}

template<typename T>
Node<T>* make_node(const T& no=0){
  Node<T>* ptr = new Node<T>(no);
  ptr->fptr = ptr->bptr = NULL;
  return ptr;
}

template<typename T>
class List{

private:

  Node<T>* head;
  Node<T>* tail;
  int osize;
  Node<T>* nptr;

public:

  List():head(NULL),tail(NULL),osize(0),nptr(NULL){}

  List(const T* from,const T* to):head(NULL),tail(NULL),osize(0),nptr(NULL){
    for(const T* a=from;a!=to;++a){
      push_back(*a);
    }
  }
  
  List(int s,const T& v = 0):head(NULL),tail(NULL),osize(0),nptr(NULL){
    for(int i=0;i<s;++i){
      push_back(v);
    }
  }

  List(const initializer_list< Node<T> >& foo):head(NULL),tail(NULL),osize(0),nptr(NULL){
    const Node<T>* ptr;
    for(ptr=foo.begin();ptr!=foo.end();++ptr){
      push_back(ptr->data);
    }
    osize=foo.size();
  }

  const Node<T>* begin() const {return head;}
  Node<T>* begin() {return head;}

  const Node<T>* end() const {return nptr;}
  Node<T>* end() {return nptr;}

  List<T>& operator->(){return *this;}
  const List<T>& operator->() const {return *this;}

  const T& front() const {assert(osize>0); return head->data;}
  T& front() {assert(osize>0); return head->data;}

  const T& back() const {assert(osize>0); return tail->data;}
  T& back() {assert(osize>0); return tail->data;}

  List<T>& operator=(const initializer_list< Node<T> >& foo){

    if(head!=NULL){clear();}

    const Node<T>* ptr=foo.begin();
    for(ptr=foo.begin();ptr!=foo.end();++ptr){
      push_back(ptr->data);
    }
    osize=foo.size();

    return *this;
  }

  ~List(){clear();}

  int size() const {return osize;}
  void clear() {while(head!=NULL){pop_back();}}

  void push_back(const T& foo){
    Node<T>* ptr = make_node(foo);
    if(head == NULL){
      head = tail = ptr;
    }
    else{
      tail->fptr = ptr;
      ptr->bptr = tail;
      tail = ptr;
    }
    ++osize;
  }

  void push_front(const T& foo){
    Node<T>* ptr = make_node(foo);
    if(head == NULL){
      head = tail = ptr;
    }
    else{
      head->bptr = ptr;
      ptr->fptr = head;
      head = ptr;
    }
    ++osize; 
  }

  void pop_back(){
    if(osize!=0){
      if(osize==1){
	delete head;
	head = tail = NULL;
      }
      else{
	Node<T>* p = tail->bptr;
	p->fptr = NULL;
	delete tail;
	tail = p;
      }
      --osize;
    }
  }

  void pop_front(){
    if(osize!=0){
      if(osize==1){
	delete head;
	head = tail = NULL;
      }
      else{
	Node<T>* p = head->fptr;
	p->bptr = NULL;
	delete head;
	head = p;
      }
      --osize;
    }
  }

  Node<T>* insert(Node<T>* q , const T& d){
    if(osize <= 1){
      push_front(d);
      return head;
    }
    else{
      if(q == head){
	push_front(d);
	return head;
      }
      else{
	Node<T>* p = make_node(d);
	p->fptr = q;
	p->bptr = q->bptr;
	p->fptr->bptr = p;
	p->bptr->fptr = p;
	++osize;
	return p;
      }
    }
  }

  void append(const List<T>& foo){
    const Node<T>* p;
    for(p=foo.begin();p!=foo.end();p=p->fptr){
      push_back(p->data);
    }
  }

  bool delete_node(const Node<T>* q){
    if(q == head){
      pop_front();
      return true;
    }
    else if(q == tail){
      pop_back();
      return true;
    }
    else{
      if(osize <= 2){
	return false;
      }
      else{
	Node<T>* p;
	for(p=head;p!=tail;p=p->fptr){
	  if(q == p){
	    p->fptr->bptr = p->bptr;
	    p->bptr->fptr = p->fptr;
	    delete p;
	    --osize;
	    return true;
	  }
	}
	return false;
      }
    }
  }

  int delete_node(const T& d){
    int no = 0;
    Node<T> *p , *q;
    for(p=head;p!=nptr;p=q){
      q=p->fptr;
      if(p->data == d){
	delete_node(p);
	++no;
      }
    }
    return no;
  }

  const List<T>& unique(){
    Node<T> *p , *q;
    for(p=head;p!=NULL;p=q){
      q=p->fptr;
      if(find(p,p->data) > 1){
	delete_node(p);
      }
    }
    return *this;
  }

  List<T> unique() const {
    List<T> foo = *this;
    Node<T> *p , *q;
    for(p=foo.head;p!=NULL;p=q){
      q=p->fptr;
      if(foo.find(p,p->data) > 1){
	foo.delete_node(p);
      }
    }
    return foo;
  }

  Node<T>* find(const T& no) const {
    
    for(Node<T> *p = head;p!=NULL;p=p->fptr){
      if(p->data == no){
	return p;
      }
    }

  }

  int find(Node<T>* s,const T& no) const {
    int n = 0;
    bool start = false;
    for(Node<T> *p =head;p!=NULL;p=p->fptr){
      if(p==s){
	start=true;
      }
      if(start && p->data == no){
	++n;
      }
    }
    return n;
  }

  List<T> splice(int s,int n=-1){
    int i,j;
    Node<T> *p,*q;
    List<T> foo;
    if(s+n >= osize || n == -1){
      n=osize-s;
    }
    for(i=0,p=head;p!=NULL;p=p->fptr,++i){
      q=p->fptr;
      if(i==s){
	for(j=0;j<n;++j){
	  foo.push_back(p->data);
	  q=p->fptr;
	  delete_node(p);
	  p=q;
	}
	return foo;
      }
    }
  }

  const List<T>& splice(int s,List<T>& foo,int a,int n = -1){
    int i,j;
    Node<T> *p,*q;
    List<T> bar = foo.splice(a,n);
    if(s >= osize){
      for(q=bar.head;q!=NULL;q=q->fptr){
	push_back(q->data);
      }
      return *this;
    }
    else{
      for(i=0,p=head;p!=NULL;++i,p=p->fptr){
	if(i==s){
	  for(q=bar.head;q!=NULL;q=q->fptr){
	    p=insert(p,q->data);
	    p=p->fptr;
	  }
	  return *this;
	}
      }
    }
  }

  template<typename Fn>
  void sort(Fn fn){
    if(osize <= 1) return;
    Node<T> *p,*q,*r;
    T tmp;
    for(p=head->fptr;p!=nptr;p=p->fptr){
      for(q=p;q!=head;q=r){
	r = q->bptr;
	if(fn(q->data,r->data)){
	  tmp=q->data;
	  q->data = r->data;
	  r->data = tmp;
	}
	else{
	  break;
	}
      }
    }
  }

  void sort(){
    if(osize <= 1) return;
    Node<T> *p,*q,*r;
    T tmp;
    for(p=head->fptr;p!=nptr;p=p->fptr){
      for(q=p;q!=head;q=r){
	r = q->bptr;
	if(less<T>()(q->data,r->data)){
	  tmp=q->data;
	  q->data = r->data;
	  r->data = tmp;
	}
	else{
	  break;
	}
      }
    }
  }

  friend ostream& operator<<(ostream& out,const List<T>& foo){
    const Node<T>* p;
    for(p=foo.begin();p!=foo.end();p=p->fptr){
      out << p->data << " ";
    }
    return out;
  }
  
};

template<typename T>
List<T> intersection(const List<T>& a,const List<T>& b){
  a.unique();
  b.unique();
  List<T> e;
  const Node<T>* ptr;
  for(ptr=a.begin();ptr!=a.end();ptr=ptr->fptr){
    if(b.find(ptr->data) > 0){
      e.push_back(ptr->data);
    }
  }
  return e;
}

template<typename T>
struct large_first{
  bool operator()(const T& a,const T& b) const {
    return greater<T>()(a,b);
  }
};

int main(){

  List<int> a{1,4,3,8,4,6};

  List<int> b{6,8,2},c{4,2};

  cout << "a : " << a << endl;
  cout << "b : " << b << endl;
  cout << "c : " << c << endl;

  a = b;
  cout << "a = b : " << a << endl;

  c.append(b);
  cout << "c.append(b) : " << c << endl;

  c={5,2,1};
  cout << "c = {5,2,1} : " << c << endl;

  auto d = c.find(2);

  c.insert(d,3);
  cout << c << endl; 

  return 0;
}

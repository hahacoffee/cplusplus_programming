// 黃俊維
// 105303011
// 機械3A

#include <iostream>

using namespace std;

int temp;

template<typename T>
class Vector{
private:
  T* data;
  int rsize;
  int osize;
public:
  Vector():data(NULL),rsize(0),osize(0){}

  Vector(int n,const T& val=0):rsize(2*n),osize(n){
    data=(n>0 ? new T[rsize]:NULL);
    for(int i=0;i<osize;++i){
      data[i]=val;
    }
  }

  Vector(T* from,T* end):data(NULL),rsize(0),osize(0){
    for(T* ptr=from;ptr!=end;++ptr){
      push_back(*ptr);
    }
  }

  Vector(const Vector<T>& foo){
    osize=foo.osize;
    rsize=foo.rsize;
    data=new T[rsize];
    for(int i=0;i<osize;++i){
      data[i]=foo.data[i];
    }
  }
  
  ~Vector(){
    delete [] data;
  }

  Vector<T>& operator=(const Vector& foo){
    if(this == &foo) return *this;

    if(rsize !=foo.rsize){
      delete [] data;
      rsize=foo.rsize;
      data = new T[rsize];
    }
    osize=foo.osize;
    for(int i=0;i<osize;++i){
      data[i]=foo.data[i];
    }
  }

  const T& front() const {return data[0];}
  T& front() {return data[0];}
  const T& back() const {return data[osize-1];}
  T& back() {return data[osize-1];}

  const T& operator[](int i) const {
    data[i]=temp;
    return data[i];
  }

  T& operator[] (int i){
    data[i]=temp;
    return data[i];
  }

  int size() const {
    return osize;
  }

  int capacity() const {
    return rsize;
  }

  T& operator=(int n){
    temp=n;
  }
  
  void push_back(const T& foo){
    if(osize==rsize){
      rsize=(rsize==0 ? 1:2*rsize);
      T* ptr=new T[rsize];
      for(int i=0;i<osize;++i){
	ptr[i]=data[i];
      }
      ptr[osize]=foo;
      delete data;
      data=ptr;
    }
    else{
      data[osize]=foo;
    }
    osize++;
  }

  void pop_back(){
    if(osize>0){
      --osize;
    }
  }

  void insert(int i,int n){
    data[i]=n;
  }

  void insert(int num,const Vector<T>& foo){
    
    int fstart,fend;
    fstart = num+foo.osize;
    fend = osize+foo.osize;
    
    while(fend>=rsize){
      rsize = (rsize==0 ? 1 : 2*rsize);
    }
    
    T* ptr = new T[rsize];
    for(int i=0;i<osize;++i){
      ptr[i]=data[i];
    }
    
    delete [] data;

    data = new T[rsize];

    for(int i=0;i<num;++i){
      data[i]=ptr[i];
    }

    for(int j=num;j<fstart;++j){
      data[j]=foo.data[j-num];
    }
    for(int k=fstart;k<fend;++k){
      data[k]=ptr[k-foo.osize];
    }
    osize=osize+foo.osize;
    delete [] ptr;
  }

  void swap(Vector<T>& foo){
    T* ptr = new T[rsize];
    for(int i=0;i<osize;++i){
      ptr[i]=data[i];
    }
    T* ptr2 = new T[foo.rsize];
    for(int i=0;i<foo.osize;++i){
      ptr2[i]=foo.data[i];
    }
    int trsize,tosize;
    tosize=osize;
    trsize=rsize;
    osize=foo.osize;
    rsize=foo.rsize;
    foo.osize=tosize;
    foo.rsize=trsize;
    delete [] data;
    delete [] foo.data;
    data = new T[rsize];
    foo.data = new T[foo.rsize];
    for(int i=0;i<osize;++i){
      data[i]=ptr2[i];
    }
    for(int i=0;i<foo.osize;++i){
      foo.data[i]=ptr[i];
    }
    delete [] ptr;
    delete [] ptr2;
  }
  
  friend ostream& operator<<(ostream& out,const Vector<T>& a){
    for(int i=0;i<a.osize;i++){
      out << a.data[i] << " ";
    }
    return out;
  }
};

int main(){
  
  Vector<int> a(3,5);
  a[2]=3;
  a[0]=0;
  a.insert(1,9);
  a.insert(2,Vector<int>(9,7));
  cout << a << endl;
  
  Vector<int> b(2,3),c(4,5);
  cout << b << "- " << c << endl;
  b.swap(c);
  cout << b << "- " << c << endl;
  return 0;
}

#include<iostream>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<iomanip> // setw, setfill
using namespace std;

struct large_digit_sum{

    int str_to_int(const string& str) const {
        // 1
        istringstream istr;
        istr.str( str );
        int num;

        istr >> num;
        return num;
    }

    int digit_sum( const string& str ) const {
        int sum = 0;

        for( int i=0;i<str.size();++i)
            sum += str[i] - '0';

        return sum;
    }

    bool operator()( const string& car1, const string& car2 ){
      // 2

        int sum1, sum2;
        // 3
        sum1 = digit_sum( car1.substr(2) );
        sum2 = digit_sum( car2.substr(2) );

        // 4
        if( sum1 != sum2 )
            return sum1 > sum2;

        int num1, num2;
        num1 = str_to_int( car1.substr(2) );
        num2 = str_to_int( car2.substr(2) );

        // 5
        if( num1 != num2 )
            return num1 > num2;

        // 6
        return car1[0] > car2[0];
    }
};

int rand_int(int a, int b){
    return rand()%(b-a+1) + a;
}

int main(){

    // 7
    srand( static_cast<unsigned>(time(NULL)) ) ;

    string file_name = "data.dat";

    // 8
    ofstream ofile(file_name.c_str());

    // 9
    int m,n;

    // 10
    char letter;
    int rand_num;

    m = rand_int(5,10);
    for(int i=0;i<m;++i){

        n = rand_int(3,10);
        for(int j=0;j<n;++j){
            // 11
            letter = rand_int('A','Z');
            rand_num = rand_int(1,99);

            ofile << letter << "-";

            // 12
            ofile << setw(2) << setfill('0') << rand_num << " ";
        }
        ofile << endl;
    }

    // 13
    ofile.close();


    ifstream ifile(file_name.c_str());
    istringstream istr ;
    string line;

    // 14
    vector<string> cars;
    string car;

    while( getline(ifile,line) ){

        istr.str(line);
        // 15
        while( istr >> car )
            cars.push_back(car);
        istr.clear();

        // 16
        sort( cars.begin() , cars.end() , large_digit_sum() );

        // 17
        for(int k=0;k<cars.size();++k){
            cout << cars[k] << " ";
        }
        cout << endl;

        // 18
        cars.clear();
    }

}

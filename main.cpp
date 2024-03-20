#include <iostream>
#include <string>
#include "CURL.h" 
#include "StockData.h"
#include <ctime>
#include <chrono>


using namespace std;
using namespace std::chrono;


struct BandEdate {

    struct tm begin{};
    struct tm end{};



};

string StockInfo() {

    BandEdate T;
    CurlWrap C;
    string interval;
    string ticker;

    cout << "Enter ticker of stock you would like to find information on: " << endl;
    cin >> ticker;

    cout << "Enter the beginning year: " << endl;
    cin >> T.begin.tm_year;
    T.begin.tm_year -= 1900;

    cout << "Enter the beginning month (1-12): " << endl;
    cin >> T.begin.tm_mon;
    T.begin.tm_mon--;

    cout << "Enter the beginning day (1-31): " << endl;
    cin >> T.begin.tm_mday;

    cout << "Enter the end year: " << endl;
    cin >> T.end.tm_year;
    T.end.tm_year -= 1900;

    cout << "Enter the end month (1-12): " << endl;
    cin >> T.end.tm_mon;
    T.end.tm_mon--;

    cout << "Enter the end day (1-31): " << endl;
    cin >> T.end.tm_mday;

    cout << "Enter the interval for the stock: " << endl;
    cin >> interval;

    time_t starttime = mktime(&T.begin);


    time_t endtime = mktime(&T.end);




    system_clock::time_point start_date = system_clock::from_time_t(starttime);
    system_clock::time_point end_date = system_clock::from_time_t(endtime);

    return C.URL(ticker, start_date, end_date, interval);


}

int main() {

    string URL = StockInfo(); 

    
    StockData s1(URL);       
    s1.Print();




}



   

   


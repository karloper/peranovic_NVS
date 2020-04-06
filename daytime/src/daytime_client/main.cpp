#include <iostream>
#include "asio.hpp"
#include <ctime>

using namespace std;
using namespace asio::ip;

int main() {
    string port{"2222"};
    tcp::iostream strm{"localhost", port};

    if (strm) { // connected
        string data;
        getline(strm, data); // get time from timeserver
        data = data.substr(6, 17); // remove overhead

        const char* date = data.c_str(); // date 20-04-06 16:50:11
        struct tm tmz;
        strptime(date, "%y-%m-%d %H:%M:%S", &tmz); // convert 'date' into tmz structure
        time_t utc = timegm(&tmz);

        tm* loctm = localtime(&utc);
        // Date and Time from time.nist.gov server in local timezone
        cout << asctime(loctm) << endl;

        strm.close();
    } else { 
        cerr << "Could not connect to Server" << endl;
    }
}
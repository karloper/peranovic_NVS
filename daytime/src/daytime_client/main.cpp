#include <iostream>
#include "asio.hpp"

using namespace std;
using namespace asio::ip;

int main() {
    string port{"2222"};
    tcp::iostream strm{"localhost", port};
    //tcp::iostream strm{"time.nist.gov", "13"};

    if (strm) { // connected
        string data;
        getline(strm, data);

        cout << data << endl;
        strm.close();
    } else { 
        cerr << "Could not connect to Server" << endl;
    }
}
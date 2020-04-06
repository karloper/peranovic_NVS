#include <iostream>
#include "asio.hpp"

using namespace std;
using namespace asio::ip;


int main() {
    short unsigned port{2222};
    asio::io_context ctx;
    tcp::endpoint ep{tcp::v4(), port};
    tcp::acceptor acceptor{ctx, ep};
    acceptor.listen();

   while(true) {
        tcp::iostream time_server{"time.nist.gov", "13"};

        tcp::socket sock{ctx};
        acceptor.accept(sock);
        tcp::iostream strm{move(sock)};
        string data{""};
        if(time_server) {
            getline(time_server, data); // first line is empty
            getline(time_server, data);

            // TEST: should return +2h -> next day
            //data = "58945 20-04-06 23:30:09 50 0 0   2.8 UTC(NIST) *";
            cout << "Data: " << data << endl;
        } else {
            cerr << "Could not fetch data from time.nist.gov server" << endl;
        }

        if(strm) {
            try {
                strm << data; // pass time to clients
            } catch(...) {
                cerr << "Could not send data without errors" << endl;
            }
        } else {
            cerr << "Could not accept connection without errors" << endl;
        }
        
        strm.close();
    }
    
}

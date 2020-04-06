#include <iostream>
#include "asio.hpp"
#include "timeutils.h"

using namespace std;
using namespace asio::ip;

int main() {
    short unsigned port{2222};
    asio::io_context ctx;
    tcp::endpoint ep{tcp::v4(), port};
    tcp::acceptor acceptor{ctx, ep};
    acceptor.listen();

   while(true) {
        asio::ip::tcp::socket sock{ctx};
        acceptor.accept(sock);
        asio::ip::tcp::iostream strm{move(sock)};

        if(strm) {
            try {
                string x{"hello"};
                strm << x;
            } catch(...) {
                cerr << "Could not send data without errors" << endl;
            }
        } else {
            cerr << "Could not accept connection without errors" << endl;
        }
        
        strm.close();
    }
}

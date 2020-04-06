#include <iostream>
#include "asio.hpp"
//#include <ctime>
#include <time.h>

using namespace std;
using namespace asio::ip;
/*
Hier schlage ich einen Zeitserver vor, der sich von =time.nist.gov= 
mittels des daytime Protokolls die aktuelle Zeit holt 
und diese in die lokale Zeit konvertiert (gemäß der lokalen Zeitzone) 

und diese an den Client nach Verbindungsaufnahme in einer Zeile zurückliefert. 
Danach wird die Verbindung geschlossen.
*/


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
                string h{"hello"};
                strm << h;

                
                //strm << curr_time();
                //strm << chrono::system_clock::now();
            } catch(...) {
                cerr << "Could not send data without errors" << endl;
            }
        } else {
            cerr << "Could not accept connection without errors" << endl;
        }
        
        strm.close();
    }
}

#ifndef  _ASYNC_UDP
#define _ASYNC_UDP

// Standard library imports
#include <string>
#include <iostream>
// Boost imports
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/make_shared.hpp>

class Async_UDP_server
{
    public:
        Async_UDP_server()=delete; // This constructor is not usuable
        // IO service 
        Async_UDP_server(boost::asio::io_service &ioservice, int PortNum);
    private:
        //  Member functions to expose
        void start_receiver();
        void handle_receieve(
                const boost::system::error_code & error_caught,
                size_t recievedByteCount 
        );

        void handle_send(
            boost::shared_ptr<std::string>,
            const boost::system::error_code&,
            std::size_t 
        );
        boost::asio::ip::udp::socket _socket;
        boost::asio::ip::udp::endpoint _endpoint;
        std::array<char,1> recieve_buffer;
        boost::shared_ptr<std::string> replymessage;
};

// References used :
// https://www.boost.org/doc/libs/1_37_0/doc/html/boost_asio/tutorial/tutdaytime6/src.html
// https://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/reference/ip__udp/socket.html

#endif //_ASYNC_UDP
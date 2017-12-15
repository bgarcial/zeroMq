#include "ZMQServerComponent.h"
#include <sofa/core/ObjectFactory.h>
#include <zmq.hpp>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


namespace sofa
{

namespace component
{

namespace controller
{

zmq::context_t context (1);
zmq::socket_t socket (context, ZMQ_REP);


ZMQServerComponent::ZMQServerComponent()
    // : myparam(initData(&myparam, 0.42, "myparam", "ZeroMq version plugin. "))
    // : myparam(initData(&myparam, (double)(0.42), "myparam", "ZeroMq version plugin. "))
    // , d_address(initData(&d_address, (std::string)"127.0.0.1", "address", "Scale for object display. (default=localhost)"))
{

}

void ZMQServerComponent::receiveRequests() {
    cout << "Creating socket zeroMQ ..."<<endl;
    socket.bind("tcp://*:5555");
    while (true) {
        zmq::message_t request;

        //  Wait for next request from client
        socket.recv(&request);
        string incomingMessage = std::string(static_cast<char *>(request.data()), request.size());
        cout << "Incoming message from client: " << incomingMessage << endl;

        // Do some work
        sleep(1);
        // int x=0.1;
        float f = 0.1;
        std::string f_str = std::to_string(f);
        std::cout << "std::cout: " << f << '\n'
              << "to_string: " << f_str  << "\n\n";

        
        std::string message="Hello Client, my version is: " + f_str;
        zmq::message_t reply (message.length());
        // memcpy (reply.data(), message.c_str(), replys);
        memcpy (reply.data(), message.c_str(), message.length());
        // cout << "myparam value is:" << myparam.getValue() << endl;
        // cout << "The addres value is:" << d_address.getValue() << endl;
        //memcpy (reply.data(), "Hello Client", myparam.getValue());
        socket.send(reply);
    }
}

/*
void ZMQServerComponent::sendReplyToClient() {
    // std::string s=myparam.getValue()
    std::string messageStr="Hello Client, my version is: ";
    zmq::message_t reply (messageStr.length());
    //memcpy (reply.data(), "H", myparam.getValue());
    memcpy (reply.data(), messageStr.c_str(), myparam.getValue());
    cout << "myparam value is:" << myparam.getValue() << endl;
    cout << "The addres value is:" << d_address.getValue() << endl;
    //memcpy (reply.data(), "Hello Client", myparam.getValue());
    socket.send(reply);
}*/

void ZMQServerComponent::init(){
    ZMQServerComponent z;
    z.receiveRequests();
    // z.sendReplyToClient();

}


ZMQServerComponent::~ZMQServerComponent()
{

}

// int ZeroMqComponentClass = sofa::core::RegisterObject("This component does nothing.").add<ZeroMqComponent>();
SOFA_DECL_CLASS(ZMQServerComponent)
int ZMQServerComponentClass = sofa::core::RegisterObject("This component create a Socket.").add<ZMQServerComponent>();

}
}
}

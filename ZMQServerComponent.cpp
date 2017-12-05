#include "ZMQServerComponent.h"
#include <sofa/core/ObjectFactory.h>
#include <zmq.hpp>
#include <iostream>

using std::cout;
using std::endl;


namespace sofa
{

namespace component
{

namespace controller
{


zmq::context_t context (1);
zmq::socket_t socket (context, ZMQ_REP);


ZMQServerComponent::ZMQServerComponent() 
    : myparam(initData(&myparam, 0.42, "myparam", "ZeroMq version plugin. "))
{
    
}

void ZMQServerComponent::receiveRequests() {
    cout << "Creating socket zeroMQ ..."<<endl;
    socket.bind("tcp://*:5555");
    zmq::message_t request;

    //  Wait for next request from client
    socket.recv(&request);
    std::string incomingMessage = std::string(static_cast<char *>(request.data()), request.size());
    std::cout << "Incoming message from client" << incomingMessage << std::endl;

    // Do some work
    sleep(1);

}

void ZMQServerComponent::sendReplyToClient() {
    //  Send reapplications/plugins/ZeroMq/CMakeFiles/ZeroMq.dir/main.cpp.oply back to client
    zmq::message_t reply (20);
    memcpy (reply.data(), "Hello Client", 20);
    socket.send(reply);
}

void ZMQServerComponent::init(){
    ZMQServerComponent z;
    z.receiveRequests();
    z.sendReplyToClient();

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
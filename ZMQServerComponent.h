#include <sofa/core/behavior/BaseController.h>
#include <zmq.hpp>

namespace sofa
{

namespace component
{

namespace controller
{


class ZMQServerComponent : public sofa::core::behavior::BaseController
{

Data<double> myparam;
public:
SOFA_CLASS(ZMQServerComponent, sofa::core::behavior::BaseController);

    ZMQServerComponent ();
    virtual ~ZMQServerComponent ();
    void receiveRequests();
    void sendReplyToClient();
    void init();
    
};

}

}

}
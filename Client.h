#include <sys/time.h>
#include <iostream>

using std::string;

class Client{
public:
    Client();
    void setupConnection();
    void GetResponseFromServer();

private:
    struct timeval t_before, t_after;
    string replyMessage;

};
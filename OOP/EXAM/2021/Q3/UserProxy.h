#pragma once
#include "User.h"
#include "EncryptStrategy.h"
#include "VerificationStrategy.h"

using std::string;
using std::cout;
using std::endl;

class UserProxy{
private:
    EncryptStrategy* enc;
    VerificationStrategy* ver;
    RealUser* user;
public:
    UserProxy(RealUser* _user, EncryptStrategy* _enc, VerificationStrategy* _ver) : user(_user), enc(_enc), ver(_ver){}
    void sendMessage(string message){
        user->sendMessage(enc->encode(message));
        cout << ver->verify(message) << endl;
    }
};
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "Proto/practice.grpc.pb.h"
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ClientContext;
using practice::Cryptography;
using practice::Sample;
using practice::Reply;
class CryptographyClient {
    public:
        CryptographyClient(std::shared_ptr<grpc::Channel> channel)
            : stub_(practice::Cryptography::NewStub(channel)) {}

    Reply Encryption(const Sample& user) {
        // Data we are sending to the server.
        Sample request=user;
        // Container for the data we expect from the server.
        Reply reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        Status status = stub_->Encryption(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
        return reply;
        } else {
        std::cout << status.error_code() << ": " << status.error_message()
                    << std::endl;
        Reply error;
        error.add_res(-1);
        return error;
        }
    }
    private:
        std::unique_ptr<practice::Cryptography::Stub> stub_;
};

int main(int argc, char** argv) {
    
    CryptographyClient greeter(grpc::CreateChannel("server:50051", grpc::InsecureChannelCredentials()));
    Sample data;
    for(int i=0;i<2;i++){
        int x;
        std::cin >> x;
        data.add_message(x);
    }
    for(int i=0;i<2;i++){
        for(int i=0;i<2;i++){
        int x;
        std::cin >> x;
        data.add_key(x);
        }
    }
    for(int i=0;i<2;i++){
        for(int i=0;i<2;i++){
        int x;
        std::cin >> x;
        data.add_uni(x);
        }
    }
    for(int i=0;i<2;i++){
        int x;
        std::cin >> x;
        data.add_er(x);
    }
    Reply a=greeter.Encryption(data);
    auto x=a.res();
    std::vector<double> list(x.begin(),x.end());
    std::cout << (int)list[0]<<" "<<(int)list[1]<<std::endl;
    return 0;
}
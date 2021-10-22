#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "Proto/practice.grpc.pb.h"
#include "main/main.hpp"
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using practice::Cryptography;
using practice::Sample;
using practice::Reply;

class GreeterService final : public practice::Cryptography::Service {
    Status Encryption(ServerContext* context, const Sample* request,
                  Reply* reply) override {
        auto req_message=request->message();
        auto req_secret_key=request->key();
        auto req_unimoduler=request->uni();
        auto req_er=request->er();

        std::vector<double> message(req_message.begin(),req_message.end());
        std::vector<double> Serialize_key(req_secret_key.begin(),req_secret_key.end());
        std::vector<double> Serialize_uni(req_unimoduler.begin(),req_unimoduler.end());
        std::vector<double> err(req_er.begin(),req_er.end());
        std::vector<std::vector<double> > key(2,std::vector<double>(2));
        std::vector<std::vector<double> > uni(2,std::vector<double>(2));

        for(int i=0;i<4;i++){
            key[i/2][i%2]=Serialize_key[i];
        }
        for(int i=0;i<4;i++){
            uni[i/2][i%2]=Serialize_uni[i];
        }
        std::vector<double> r=test::Encryptiontest(message,key,uni,err);
        for(int i=0;i<2;i++){
            reply->add_res(r[i]);
        }
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    GreeterService service;

    grpc::ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown.
    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();

    return 0;
}
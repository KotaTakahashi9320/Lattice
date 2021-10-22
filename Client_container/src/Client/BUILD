# バイナリ生成
cc_binary(
    name = "client",
    srcs = [
        "Client.cpp"
    ],
    deps = [
        "//Proto:practice_cc_grpc",
        "@com_github_grpc_grpc//:grpc++"
    ],
    visibility = ["//visibility:public"],
)
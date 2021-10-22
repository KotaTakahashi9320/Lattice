# バイナリ生成
cc_binary(
    name = "server",
    srcs = [
        "Server.cpp",
    ],
    deps = [
        "//Proto:practice_cc_grpc",
        "@com_github_grpc_grpc//:grpc++",
        "//Server/main:main",
    ],
    visibility = ["//visibility:public"],
)
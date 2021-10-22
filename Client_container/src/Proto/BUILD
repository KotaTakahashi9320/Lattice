load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

proto_library(
    name = "practice_proto",
    srcs = ["practice.proto"],
)

cc_proto_library(
    name = "practice_cc_proto",
    deps = [":practice_proto"],
)

# 通信の雛形コード生成
cc_grpc_library(
    name = "practice_cc_grpc",
    srcs = [":practice_proto"],
    grpc_only = True,
    deps = [":practice_cc_proto"],
    visibility = ["//visibility:public"],
)
FROM ubuntu:18.04 as base
# 環境変数
ENV CMAKE_INSTALL_DIR /local
ENV PATH $PATH:/grpc/cmake/build
ENV PATH $PATH:/grpc/cmake/build/third_party/protobuf
ENV PATH $PATH:$CMAKE_INSTALL_DIR/bin

RUN apt-get update && \
    apt-get install -y \
    git \
    wget \
    clang \
    ca-certificates \
    build-essential \
    libssl-dev \
    make \
    autoconf \
    automake \
    pkg-config \
    libtool \
    libboost-all-dev \
    libeigen3-dev \
    vim \
    cron \
    curl

# Install cmake
RUN wget -q -O cmake-linux.sh https://github.com/Kitware/CMake/releases/download/v3.17.0/cmake-3.17.0-Linux-x86_64.sh && \
    mkdir -p $CMAKE_INSTALL_DIR && \
    sh cmake-linux.sh -- --skip-license --prefix=$CMAKE_INSTALL_DIR && \
    rm cmake-linux.sh && \
    # Install bazel
    echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list && \
    wget https://bazel.build/bazel-release.pub.gpg && \
    apt-key add bazel-release.pub.gpg && \
    apt-get update && \
    apt-get -y install bazel-3.4.1 && \
    ln -s /usr/bin/bazel-3.4.1 /usr/bin/bazel
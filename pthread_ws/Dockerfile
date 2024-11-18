FROM ubuntu:22.04

RUN apt update && \
    apt install -y \
    sudo \
    vim \
    build-essential \
    cmake \
    cmake-curses-gui\
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

WORKDIR home/user/sharedvol

CMD "/bin/bash"

FROM ubuntu:22.04

RUN apt update && \
    apt install -y \
    x11-apps \
    vim \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

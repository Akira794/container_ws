#!/bin/bash

xhost +local:

#refs: https://tektektech.com/docker-setup-nginx/
docker container run \
	--name x11_test \
	--detach \
	--rm \
	--interactive \
	--tty \
	--net=host \
	-v "$(pwd)/sharedvol":/sharedvol \
	-e DISPLAY=$DISPLAY \
        -v /tmp/.X11-unix:/tmp/.X11-unix \
	-v $HOME/.Xauthority:/root/.Xauthority \
        my_x11:test \
        xeyes

xhost -local:

#!/bin/bash

#refs: https://tektektech.com/docker-setup-nginx/
docker container run \
	--name my_cenv \
	--rm \
	--interactive \
	--tty \
	--volume "$(pwd)/sharedvol":/home/user/sharedvol \
        my_cenv:test

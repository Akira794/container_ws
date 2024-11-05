#!/bin/bash

#refs: https://tektektech.com/docker-setup-nginx/
docker container run \
	--name nginx_test \
	--detach \
	--rm \
	--interactive \
	--tty \
	--volume "$(pwd)/html":/usr/share/nginx/html \
	--publish 8931:80 \
        my_nginx:test	

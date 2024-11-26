#!/bin/bash

#refs: https://tektektech.com/docker-setup-nginx/
docker container run \
	--name tmp_test \
	--detach \
	--interactive \
  --rm \
	--tty \
	--publish 9000:8080 \
        tmp_ws:test	

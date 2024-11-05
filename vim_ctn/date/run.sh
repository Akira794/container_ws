#!/bin/bash

docker container run \
	--name vim_conf_test \
	--rm \
	--interactive \
	--tty \
	vim_conf:date \
	vim 
	

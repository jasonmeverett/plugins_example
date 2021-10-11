FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get upgrade -y \
	&& apt-get install -y \
		build-essential \
		cmake \
		git \
		csh \
		nano \
		vim 		

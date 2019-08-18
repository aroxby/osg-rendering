FROM ubuntu:bionic

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libopenscenegraph-dev

COPY . /src
WORKDIR /src/build

RUN cmake .. && make

CMD ./osg-rendering
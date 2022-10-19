FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y make gcc valgrind
        
ADD . /libbloom
WORKDIR /libbloom
RUN make test

CMD ["/libbloom/build/test-libbloom", "100000", "1000000", "50000", "0.1"]


#FROM --platform=linux/amd64 ubuntu:20.04 as builder\
FROM fuzzers/libfuzzer:12.0

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y make gcc valgrind
        
ADD . /libbloom
WORKDIR /libbloom
RUN make

RUN clang-12 -fsanitize=fuzzer,address -Wall -fPIC -DBLOOM_VERSION=2.0 -DBLOOM_VERSION_MAJOR=2 -DBLOOM_VERSION_MINOR=0 -O3 -I/libbloom -I/libbloom/murmur2 /libbloom/misc/test/basic-fuzz.c /libbloom/build/libbloom.a -lm -o /libbloom/build/test-basic-fuzz


#CMD ["/libbloom/build/test-libbloom", "100000", "1000000", "50000", "0.1"]


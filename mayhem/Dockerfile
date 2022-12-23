FROM fuzzers/libfuzzer:12.0

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y make gcc valgrind
        
ADD . /libbloom
WORKDIR /libbloom
RUN make

RUN clang-12 -fsanitize=fuzzer,address -Wall -fPIC -DBLOOM_VERSION=2.0 -DBLOOM_VERSION_MAJOR=2 -DBLOOM_VERSION_MINOR=0 -O3 -I/libbloom -I/libbloom/murmur2 /libbloom/mayhem/basic-fuzz.c /libbloom/build/libbloom.a -lm -o /libbloom/mayhem/test-basic-fuzz



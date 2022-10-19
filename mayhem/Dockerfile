#FROM --platform=linux/amd64 ubuntu:20.04 as builder
FROM fuzzers/libfuzzer:12.0 as builder

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y make gcc
        
ADD . /libbloom
WORKDIR /libbloom
RUN make all

#RUN clang-12 -lm -ldl -fsanitize=fuzzer,address mayhem/fuzzer.c -o mayhem/libbloom-fuzzer build/libbloom.so.2.0
#/lib/x86_64-linux-gnu/libm.so.6
#ENV LIBRARY_PATH=/lib/x86_64-linux-gnu/
#RUN clang-12 -lm -ldl -fsanitize=fuzzer,address mayhem/fuzzer.c -o mayhem/libbloom-fuzzer build/libbloom.so.2  -v

#FROM --platform=linux/amd64 ubuntu:20.04

#FROM fuzzers/libfuzzer:12.0

#COPY --from=builder /libbloom/mayhem/libbloom-fuzzer /
#COPY --from=builder /libbloom/build/libbloom.so.2.0 /
#ENV LD_LIBRARY_PATH=/
#COPY --from=builder /c-vector/build/mayhem/c-vector-fuzzer /
#COPY --from=builder /c-vector/build/mayhem/c-vector-fuzzer-memory /
#COPY --from=builder /c-vector/build/mayhem/c-vector-fuzzer-address /

#ENTRYPOINT []
#CMD /libbloom-fuzzer

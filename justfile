alias b := build
build:
        premake5 gmake && make

alias t := test
test: build
        ./binary/Alpha/test-evoolution

alias c := clean
clean:
        rm -Rvf *.make Makefile binary/ build/

alias b := build
build:
        premake5 gmake && make evoolution

alias t := test
test: build
        premake5 gmake && make test-evoolution
        ./binary/Alpha/test-evoolution

alias c := clean
clean:
        rm -Rvf *.make Makefile binary/ build/

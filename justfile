build:
        premake5 gmake && make

test: build
        ./binary/Alpha/test-evoolution

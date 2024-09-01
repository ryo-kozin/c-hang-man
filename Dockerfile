FROM ubuntu:22.04

RUN apt-get update && apt-get install -y build-essential 

WORKDIR /usr/src/app

COPY hangman.c .

RUN gcc -o hangman hangman.c

CMD ["./hangman"]

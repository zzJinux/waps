#!/usr/bin/env bash

if [ "$TYPE" == "json" ]; then
  if ! [ "$2" ]; then
    >&2 echo "'ts' is not set!"
  else
    if >coderunner.cpp cat "$1" vecostream.cpp "$2"; then
      mkdir -p out
      out="out/a.out"
      g++ -std=c++17 -O1 -g -Wall -lm -fsanitize=address -fno-omit-frame-pointer coderunner.cpp -o "$out" \
        && "$out"
    fi
  fi
else
  mkdir -p out
  out="out/a.out"
  g++ -std=c++17 -O1 -g -Wall -lm -fsanitize=address -fno-omit-frame-pointer $1 -o "$out" \
    && if [ "$2" ]; then ../splitrun.sh "$2" "$out"; else "$out"; fi
fi

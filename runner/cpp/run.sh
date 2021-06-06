#!/usr/bin/env bash

if [ "$TYPE" == "json" ]; then
  # TODO
  >&2 echo "Not implemented"
else
  mkdir -p out
  out="out/a.out"
  g++ -std=c++17 -O1 -g -Wall -lm -fsanitize=address -fno-omit-frame-pointer $1 -o "$out" \
    && if [ "$2" ]; then ../splitrun.sh "$2" "$out"; else "$out"; fi
fi

#!/usr/bin/env bash

mkdir -p __pycache__
pycachedir=__pycache__
opts=('-X' "pycache_prefix=$pycachedir")

if [ "$TYPE" == "json" ]; then
  if ! [ "$2" ]; then
    python3 "${opts[@]}" json_runner.py "$1"
  else
    python3 "${opts[@]}" json_runner.py "$1" "$2"
  fi
else
  if ! [ "$2" ]; then
    python3 "$1"
  else
    ../splitrun.sh "$2" python3 "$1"
  fi
fi

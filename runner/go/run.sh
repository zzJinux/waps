#!/usr/bin/env bash

if [ "$TYPE" == "json" ]; then
  <<<'package main' >solution.go cat - "$1"
  if ! [ $2 ]; then
    go run .
  else
    go run . $2
  fi
else
  if ! [ $2 ]; then
    go run "$1"
  else
    <"$2" go run "$1"
  fi
fi

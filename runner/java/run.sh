#!/usr/bin/env bash

JAVAC=javac
JAVA=java

if [ "$TYPE" == "json" ]; then
  rm classes/* &>/dev/null
  $JAVAC -cp "lib/gson-2.8.6.jar" -d classes "$1" Main.java \
    && exec $JAVA -cp "classes:lib/gson-2.8.6.jar" cp_java.Main "$2"
else
  # TODO
  >&2 echo "plain java runner not implemeted yet"
fi

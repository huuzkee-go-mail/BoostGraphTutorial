#!/bin/bash
GCOV_EXE=gcov-5 # gcov and g++ versions must match
OBJ_FILES_PATH=debug

if [ ! -d "$OBJ_FILES_PATH" ]
then
  echo "Object file path not found at "$OBJ_FILES_PATH
  exit 1
fi

for filename in `find . | egrep '\.cpp'`; do $GCOV_EXE -o $OBJ_FILES_PATH $filename > /dev/null; done
#!/usr/bin/env bash

cd "$(dirname "${BASH_SOURCE[0]}")/.."

if [ -d "./py_proto" ];then
  echo -e "\e[1;31mremove:\e[0m py_proto folder"
  rm -rf py_proto
fi

mkdir py_proto
find modules/ cyber/ -name "*.proto" \
    | grep -v node_modules \
    | xargs protoc --python_out=py_proto
find py_proto/* -type d -exec touch "{}/__init__.py" \;
echo -e "\e[1;38mpython proto generate\e[0m \e[1;32msuccess\e[0m"
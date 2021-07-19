#!/bin/bash

pwd=`dirname $(readlink -f "$0")`

cd "$pwd"

if [ -d ~/.hostile-takeover ];then
 mv ~/.hostile-takeover "$pwd"
fi

echo "--------------------------------------------------------------"
echo "Setting PATH to $pwd:$PATH"
export PATH=$pwd:$PATH

echo "--------------------------------------------------------------"
echo "Setting HOME to $pwd"
export HOME=$pwd
export XDG_HOME_DIRS=$pwd

./ht "$@"

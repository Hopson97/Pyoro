#!/bin/bash

if [ "$1" = "release" ]
then
    ./build/release/pyoro
else
    ./build/debug/pyoro
fi
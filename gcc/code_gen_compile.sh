#!/bin/bash
cd "$(dirname "$0")" # change to current script directory

# exit when any command fails
set -e

SRC=../src

# run user code generation script.
$SRC/Tutorial1Sm.csx
# can also run c# script with this command instead: dotnet script $SRC/Tutorial1Sm.csx

# compile code
echo Compiling with GCC
gcc -g -Wall -std=c99 -I $SRC $SRC/main.c $SRC/light.c $SRC/Tutorial1Sm.c $SRC/Display.c

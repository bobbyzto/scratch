#!/usr/bin/env bash -euxo pipefail

cat main.c | indent -st -bap -bli0 -i4 -l79 -ncs -npcs -npcs \
  -fca -lc79 -fc1 -ts4 main.out

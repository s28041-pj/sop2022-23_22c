#!/bin/bash

file_count=$(ls -1A | wc -l)

if (( file_count > 5 )); then
  echo "W biezacym atalogu jest wiecej niz 5 plikow"
fi


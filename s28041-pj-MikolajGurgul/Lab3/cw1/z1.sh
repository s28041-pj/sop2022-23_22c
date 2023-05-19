#!/bin/bash

if [ $# -gt 1 ]; then
  echo "Pierwszy parametr: $1"
elif [ $# -eq 1 ]; then
  echo "Podano tylko jeden parametr"
  echo "Wartosc parametru: $1"
else
  echo "Nie podano zadnych parametrow"
fi


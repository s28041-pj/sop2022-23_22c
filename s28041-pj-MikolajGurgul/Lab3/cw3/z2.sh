#!/bin/bash

fibonacci() {
  local n=$1
  local result

  if [[ $n -eq 0 ]]; then
    result=0
  elif [[ $n -eq 1 ]]; then
    result=1
  else
    local a=$(fibonacci $((n-1)))
    local b=$(fibonacci $((n-2)))
    result=$((a + b))
  fi
}

n=5
fibonacci $n

exit $result

# Ograniczenie to wartosc zwracana przez return. To znaczy jest zwracana liczba
# z zakresu 0-255. Jezeli wynik przekroczy ten zakres, to nie bedzie on poprawny

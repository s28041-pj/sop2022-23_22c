#!/bin/bash

fibonacci() {
  local n=$1

  if [[ $n -eq 0 ]]; then
    echo 0
  elif [[ $n -eq 1 ]]; then
    echo 1
  else
    local a=$(( $(fibonacci $((n-1))) + $(fibonacci $((n-2))) ))
    echo $a
  fi
}

n=5
result=$(fibonacci $n)

echo "Wynik dla n=$n: $result"

# Ograniczenie to wartosc zwracana przez return. To znaczy jest zwracana liczba
# z zakresu 0-255. Jezeli wynik przekroczy ten zakres, to nie bedzie on poprawny

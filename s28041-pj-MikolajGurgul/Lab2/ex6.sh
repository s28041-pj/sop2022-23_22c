#!/bin/bash
imie=$1
imie=$(echo $imie | sed s/a$/ę/g | sed 's/\([^ę]\)$/\1a/g')
echo "$1 ma kota, a kot ma ${imie}"

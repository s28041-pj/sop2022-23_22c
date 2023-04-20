#!/bin/bash
echo "Pierwszy znak: ${1:0:1}"
echo "Ostatni znak: ${1: -1}"

echo -e "${1//SOP/\e[32mSOP\e[0m}"

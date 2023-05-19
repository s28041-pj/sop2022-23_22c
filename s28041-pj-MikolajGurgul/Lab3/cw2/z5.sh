#!/bin/bash

print_file() {
  while IFS= read -r line; do
    echo "$line"
  done < "$1"
}

print_file_reverse() {
  lines=()
  while IFS= read -r line; do
    lines=("$line" "${lines[@]}")
  done < "$1"
 
  for line in "${lines[@]}"; do
    echo "$line"
  done
}

files=("$@")

for file in "${files[@]}"; do
  echo "Zawartosc pliku: $file od poczatku"
  print_file "$file"
  echo
done

for file in "${files[@]}"; do
  echo "Zawartosc pliku: $file od konca"
  print_file_reverse "$file"
  echo
done

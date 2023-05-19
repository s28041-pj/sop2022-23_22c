#!/bin/bash

script_name="$1"

if [[ ! "$script_name" =~ \.sh$ ]]; then
  echo "Dopisanie rozszerzenia .sh do pliku"
  mv "$script_name" "${script_name}.sh"
  script_name="${script_name}.sh"
else
  echo "Skrypt posiada rozszerzenie .sh"
fi

if [[ "${script_name: -3}" != ".sh" ]]; then
  echo "Dopisanie rozszerzenia .sh do pliku"
  mv "$script_name" "${script_name}.sh"
  script_name="${script_name}.sh"
else
  echo "Skrypt posiada rozszerzenie .sh"
fi

if [[ "${script_name%.*}" != "$script_name" ]]; then
  echo "Dopisanie rozszerzenia .sh do pliku"
  mv "$script_name" "${script_name%.*}.sh"
  script_name="${script_name%.*}.sh"
else
  echo "Skrypt posiada rozszerzenie .sh"
fi

echo "Nazwa skryptu: $script_name"


#!/bin/bash

config_file="config.cfg"

if [ -f "$config_file" ]; then
  echo  "Wykonywanie pliku $config_file"
  source "$config_file"
elif [ $# -eq 1 ]; then
  script_file="$1"
  if [ -f "$script_file" ]; then
    echo "Wykonywanie pliku $script_file"
    source "$script_file"
  else
    echo "Error: Plik $script_file nie istnieje"
  fi
else
  echo "Errorr: Brak pliku config.cfg i nie podano argumentu"
fi


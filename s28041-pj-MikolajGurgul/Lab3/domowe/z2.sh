#!/bin/bash

if [[ $1 =~ ^[0-9]{2}-?[0-9]{3}$ ]]; then
    echo "Poprawny kod pocztowy"
else
    echo "Ten kod pocztowy nie jest poprawny"
fi

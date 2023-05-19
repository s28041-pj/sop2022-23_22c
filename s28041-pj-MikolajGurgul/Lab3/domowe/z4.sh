#!/bin/bash

argument=$1

if [[ $argument =~ ^[A-ZĄĆĘŁŃÓŚŹŻ][a-ząćęłńóśźż]+$ ]]; then
    echo "imie"
elif [[ $argument =~ ^[0-9]{2}-?[0-9]{3}$ ]]; then
    echo "kod pocztowy"
elif [[ $argument =~ ^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$ ]]; then
    echo "email"
else
    echo "Nie jest to zaden z: imie/kod pocztowy/email"
fi

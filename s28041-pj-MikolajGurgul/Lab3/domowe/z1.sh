#!/bin/bash

if [[ $1 =~ ^[A-ZĄĆĘŁŃÓŚŹŻ][a-ząćęłńóśźż]+$ ]]; then
    echo "Imie jest poprawne"
else
    echo "Imie nie jest poprawne"
fi

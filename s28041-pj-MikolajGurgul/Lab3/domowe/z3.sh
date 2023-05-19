#!/bin/bash

if [[ $1 =~ ^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$ ]]; then
    echo "Poprawny adres e-mail"
else
    echo "Nie jest to poprawny adres e-mail"
fi

#!/bin/bash
X=tekst
echo $X
#aby skrypt poprawnie zadzialal, powinnismy dodac EXPORT X
#bez tego zmienna X jest niewidoczna w nowym bashu, przez co, nie jest w stanie wyswietlic nam tekstu ze zmiennej
bash
echo $X

#!/bin/bash
ls -l
X=$(ls -l)
#w trakcie przypisywania do zmiennej, calosc wykonania komendy ls -l, jest brana jako jeden tekst ciagly
#i w takiej postacie wyswietlana po wywolaniu zmiennej
echo $X

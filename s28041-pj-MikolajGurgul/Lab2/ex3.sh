#!/bin/bash
echo $PATH
#PATH w domysle wypisze nam domyslna wartosc konczaca sie na /usr/games
#Mozna wykorzystac, gdy dodajemy wlasne skrypty lub programu do PATH, aby umozliwic
#ich wywolanie z dowolnego miejsca
echo $RANDOM
#RANDOM wypisze nam randomowa liczbe
#Przyda sie do generowania losowych liczb w skrypcie, np. do wygenerowania losowej liczby,
#ktora posluzy jako liczba do zgadniecia w grze Guess the number
echo $PWD
#PWD wypisze nam nasza aktualna lokalizacje
#Moze sie przydac, np. w momencie tworzenia wzglednych sciezek
echo $PS1
#PS1 jest to tak zwany znak zachety
#Mozna dostosowac wyglad prompta do wlasnych potrzeb, np. poprzez kolorowanie, czy dodaniu
#informacji o aktualnej lokalizacji
echo $USER
#USER wypisze nam usera, ktroy jest zalogowany obecnie
#Mozna wykorzystac w skryptach, ktore np. potrzebuja informacji jaki uzytkownik
#uruchomil dany skrypt
echo $HOSTNAME
#HOSTNAME wypisze nam nazwe hosta
#Moze np. pomoc odroznic na ktorym urzadzeniu zostal uruchomiony dany skrypt poprzez
#podanie nazwy hosta, albo np. do tworzenia plikow z nazwa hosta
echo $OSTYPE
#OSTYPE wypisze nam typ naszego systemu
#Moze byc przydatne do tworzenia skryptow, ktore dzialaja tylko na okreslonych systemach

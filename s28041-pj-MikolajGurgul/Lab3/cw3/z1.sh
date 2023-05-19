#/bin/bash


function color(){
	local color=$2
	if [ $color == "black" ]; then
		echo -e "\e[30m${1}\e[0m"

	elif [ $color == "red" ]; then
		echo -e "\e[31m${1}\e[0m"

	elif [ $color == "green" ]; then
		echo -e "\e[32m${1}\e[0m"

	elif [ $color == "yellow" ]; then
		echo -e "\e[33m${1}\e[0m"

	elif [ $color == "blue" ]; then
		echo -e "\e[34m${1}\e[0m"
	else
		echo "Tego koloru nie ma w zakresie"
	fi
}

color $1 $2

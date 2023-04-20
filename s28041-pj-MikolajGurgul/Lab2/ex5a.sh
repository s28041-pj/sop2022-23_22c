#!/bin/bash
name=${1/%a/ę}
name=${name/%n/na}
echo "$1 ma kota, a kot ma ${name}"

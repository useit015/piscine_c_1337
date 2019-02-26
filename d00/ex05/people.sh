#!/bin/bash

ldapsearch -x -LLL "uid=z*" | grep cn: | cut -c5- | sort -r | grep Z 

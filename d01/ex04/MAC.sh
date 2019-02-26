#!/bin/bash

ifconfig | grep "ether " | cut -f 2 -d " "

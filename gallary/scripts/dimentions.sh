#!/bin/sh

identify $1 | cut -d ' ' -f3|sed s/x/\ /


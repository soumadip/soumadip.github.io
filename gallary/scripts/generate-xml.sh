#!/bin/sh

indir=$1
outdir=$2
mkdir -p _tmp
rm -rf _tmp/*
cp $indir/*.jpg _tmp >/dev/null
cp $indir/*.Jpg _tmp >/dev/null
cp $indir/*.JPG _tmp >/dev/null

cd _tmp

	touch .tmp
	>.tmp

	for f in ./*; do 
		echo $f|cut -d '/' -f2 >> .tmp
	done

	mv .tmp _tmp
	python ../scripts/populate-xml.py $2

	rm _tmp
cd -

mkdir -p $outdir
mkdir -p $outdir/thumbs
mv _tmp/thumb* $outdir/thumbs
mv _tmp/*.xml data/
mv _tmp/* $outdir/

rmdir _tmp

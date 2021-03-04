fname="${1%.*}"
extension="${1##*.}"
outfile=$fname".min."$extension
echo $fname
echo $extension
echo $outfile
yui-compressor --type $extension $1 -o $outfile



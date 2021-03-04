fname="${1%.*}"
size=$2
extension="${1##*.}"
outfile=$fname"_"$2"_thumb.jpg"
echo $fname
echo $extension
echo $outfile
convert -thumbnail $2 $1 $outfile



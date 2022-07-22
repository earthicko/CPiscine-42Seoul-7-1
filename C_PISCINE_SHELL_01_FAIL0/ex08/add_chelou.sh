NBR1=$(echo "$FT_NBR1" | tr '\\\"\?\!' 1234)
NBR1=$(echo "$NBR1" | sed "s/\'/0/g")
NBR2=$(echo "$FT_NBR2" | tr "mrdoc" 01234)

# echo "$NBR1"
# echo "$NBR2"

DEC_NBR1=$(echo "ibase=5; $NBR1" | bc)
DEC_NBR2=$(echo "ibase=5; $NBR2" | bc)

# echo "$DEC_NBR1"
# echo "$DEC_NBR2"

DEC_SUM=$(echo "$DEC_NBR1 + $DEC_NBR2" | bc)

# echo $DEC_SUM

B13_SUM=$(echo "obase=13; $DEC_SUM" | bc) 
B13_SUM=$(echo "$B13_SUM" | tr 0123456789ABC 'gtaio luSnemf')

echo $B13_SUM


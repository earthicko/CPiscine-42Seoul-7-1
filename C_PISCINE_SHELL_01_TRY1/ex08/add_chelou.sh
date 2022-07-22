FIG=$(echo $FT_NBR1 + $FT_NBR2)
# echo $FIG
FIG=$(echo $FIG | tr "\'" 0 | tr '\\\"\?\!' "1234" | tr "mrdoc" "01234")
# echo $FIG
DEC_SUM=$(echo "ibase=5; $FIG" | bc)
# echo $DEC_SUM
B13_SUM=$(echo "obase=13; $DEC_SUM" | bc)
B13_SUM=$(echo $B13_SUM | tr "0123456789ABC" "gtaio luSnemf")

echo $B13_SUM

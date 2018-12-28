#!/bin/bash
# saves me a shitload of time

#TEXT VARIABLES:
purpletext="\033[35m"
bluetext="\033[34m"
bold="\033[1m"
normal="\033[0m"

#HELPER VARIABLES:
sortTypes=(Bubble Shaker Selection Insertion)
arraySizes=(1000 10000 25000 50000 100000 250000 500000)
logfile=dataFile.txt

#STORAGE VARIABLES:
storage=0
data1=0
data2=0
data3=0
average=0

rm datafile.txt

printf "Script Started at " >> $logfile
date "+%H:%M:%S">> $logfile
echo >> $logfile

echo "-----------------------" >> $logfile
echo -e $bluetext"Sorting Unsorted Data"$normal >> $logfile
echo "-----------------------" >> $logfile
echo >> $logfile

for i in ${sortTypes[*]}; do
    echo -e $purpletext$i" Sort:"$normal >> $logfile #if you want to see color, you need to view the file with "less -r"
    echo >> $logfile
    for j in ${arraySizes[*]}; do
	echo "Array Size:" $j >> $logfile
	echo "-----------------------" >> $logfile
        for k in `seq 1 3`; do
	    storage=$(./a.out $j l2data.txt $i | grep Sorting | cut -f 3 -d " " | sed 's/e/*10^/g')
	    if [ $k == 1 ]; then
		data1=$storage
                echo "First Sort:" $data1 >> $logfile
	    elif [ $k == 2 ]; then
		data2=$storage
                echo "Second Sort:" $data2 >> $logfile
	    elif [ $k == 3 ]; then
		data3=$storage
                echo "Third Sort:" $data3 >> $logfile
	    fi
        done
        echo "-----------------------" >> $logfile
	average=$(bc -l <<< "scale=6; ($data1+$data2+$data3)/3")
	echo "Average Sort Time:" $average >> $logfile
	echo >> $logfile
    done
done

echo "-----------------------" >> $logfile
echo -e $bluetext"Sorting Sorted Data"$normal >> $logfile
echo "-----------------------" >> $logfile
echo >> $logfile

for i in ${sortTypes[*]}; do
    echo -e $purpletext$i" Sort:"$normal >> $logfile #if you want to see color, you need to view the file with "less -r"
    echo >> $logfile
    for j in ${arraySizes[*]}; do
        echo "Array Size:" $j >> $logfile
        echo "-----------------------" >> $logfile
        for k in `seq 1 3`; do
            storage=$(./a.out $j sortedl2data.txt $i | grep Sorting | cut -f 3 -d " " | sed 's/e/*10^/g')
            if [ $k == 1 ]; then
                data1=$storage
                echo "First Sort:" $data1 >> $logfile
            elif [ $k == 2 ]; then
                data2=$storage
                echo "Second Sort:" $data2 >> $logfile
            elif [ $k == 3 ]; then
                data3=$storage
                echo "Third Sort:" $data3 >> $logfile
            fi
        done
        echo "-----------------------" >> $logfile
        average=$(bc -l <<< "scale=6; ($data1+$data2+$data3)/3")
        echo "Average Sort Time:" $average >> $logfile
        echo >> $logfile
    done
done

echo "-----------------------" >> $logfile
echo -e $bluetext"Reversing Sorted Data"$normal >> $logfile
echo "-----------------------" >> $logfile
echo >> $logfile

for i in ${sortTypes[*]}; do
    echo -e $purpletext$i" Sort:"$normal >> $logfile #if you want to see color, you need to view the file with "less -r"
    echo >> $logfile
    for j in ${arraySizes[*]}; do
        echo "Array Size:" $j >> $logfile
        echo "-----------------------" >> $logfile
        for k in `seq 1 3`; do
            storage=$(./a.out $j sortedl2data.txt $i flip | grep Sorting | cut -f 3 -d " " | sed 's/e/*10^/g')
            if [ $k == 1 ]; then
                data1=$storage
                echo "First Sort:" $data1 >> $logfile
            elif [ $k == 2 ]; then
                data2=$storage
                echo "Second Sort:" $data2 >> $logfile
            elif [ $k == 3 ]; then
                data3=$storage
                echo "Third Sort:" $data3 >> $logfile
            fi
        done
        echo "-----------------------" >> $logfile
        average=$(bc -l <<< "scale=6; ($data1+$data2+$data3)/3")
        echo "Average Sort Time:" $average >> $logfile
        echo >> $logfile
    done
done

printf "Script Finished at " >> $logfile
date "+%H:%M:%S">> $logfile
echo >> $logfile

echo All Algorithms Complete!

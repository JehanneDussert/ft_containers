#!/usr/bin/env bash

make re
./ft_containers > ft
./std_containers > std

printf "\nCheck diff between ft & std\n";
printf "****************************\n\n";
if diff ft std > /dev/null;then
   printf "No diff between ft & std :)\n";
else
    printf diff ft std;
fi

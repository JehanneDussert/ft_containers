#!/usr/bin/env bash

make fclean
make re
$ft_containers > ft
$std_containers > std
printf "\nCheck diff between ft & std\n";
printf "****************************\n\n";
if cmp -s "$ft" "$std"; then
   printf "Diff between ft & std :(\n";
else
    printf "No diff between ft & std :)\n";
fi
#!/bin/bash

cd ../../
make
cd tests/functional

#Test 1
echo "Test 1: "

../../pbrain-gomoku-ai < test_1 > tmp

i=0
while IFS= read -r ligne; do
  if [ "$i" -eq 1 ]; then
      if [[ $ligne = 17,16 ]]; then
          echo "OK - Player 2 blocked"
      else
          echo "KO - Player 2 unblocked"
      fi
  fi
  i=$(($i+1))
done < "tmp"

#Test 2
echo "
Test 2: "

../../pbrain-gomoku-ai < test_2 > tmp

i=0
while IFS= read -r ligne; do
    if [ "$i" -eq 1 ]; then
      if [[ $ligne = 9,15 ]]; then
          echo "OK - Player 2 blocked"
      else
          echo "KO - Player 2 unblocked"
      fi
  fi
  i=$(($i+1))
done < "tmp"

#Test 3
echo "
Test 3: "

../../pbrain-gomoku-ai < test_3 > tmp

i=0
while IFS= read -r ligne; do
    if [ "$i" -eq 1 ]; then
      if [[ $ligne = 6,7 ]]; then
          echo "OK - Player 1 win"
      else
          echo "KO - Player 2 win"
      fi
  fi
  i=$(($i+1))
done < "tmp"

#Test 4
echo "
Test 4: "

../../pbrain-gomoku-ai < test_4 > tmp

i=0
while IFS= read -r ligne; do
    if [ "$i" -eq 1 ]; then
      if [[ $ligne = 3,7 ]]; then
          echo "OK - Player 2 blocked"
      else
          echo "KO - Player 2 unblocked"
      fi
  fi
  i=$(($i+1))
done < "tmp"

#Finish tests
echo "
Finish test.."
rm tmp
exit 0

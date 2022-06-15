mkdir tests_3
cd tests_3
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/6.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/7.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/8.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/9.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/10.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/1_bonus.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/2_bonus.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/3_bonus.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/4_bonus.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/5_bonus.in

wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/6.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/7.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/8.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/9.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/10.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/1_bonus.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/2_bonus.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/3_bonus.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/4_bonus.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/5_bonus.out

cd ..

wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/driver_normal.c
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/driver_bonus.c

cp driver_normal.c 3/main.c
make

./q3.out < tests_3/6.in > tests_3/sub_6.out
./q3.out < tests_3/7.in > tests_3/sub_7.out
./q3.out < tests_3/8.in > tests_3/sub_8.out
./q3.out < tests_3/9.in > tests_3/sub_9.out
./q3.out < tests_3/10.in > tests_3/sub_10.out

cp driver_bonus.c 3/main.c
make

./q3.out < tests_3/1_bonus.in > tests_3/sub_1.out
./q3.out < tests_3/2_bonus.in > tests_3/sub_2.out
./q3.out < tests_3/3_bonus.in > tests_3/sub_3.out
./q3.out < tests_3/4_bonus.in > tests_3/sub_4.out
./q3.out < tests_3/5_bonus.in > tests_3/sub_5.out

cmp --silent tests_3/1_bonus.out tests_3/sub_1.out && echo '### Test 1 PASSED ###' || echo '### Test 1 FAILED ###'
cmp --silent tests_3/2_bonus.out tests_3/sub_2.out && echo '### Test 2 PASSED ###' || echo '### Test 2 FAILED ###'
cmp --silent tests_3/3_bonus.out tests_3/sub_3.out && echo '### Test 3 PASSED ###' || echo '### Test 3 FAILED ###'
cmp --silent tests_3/4_bonus.out tests_3/sub_4.out && echo '### Test 4 PASSED ###' || echo '### Test 4 FAILED ###'
cmp --silent tests_3/5_bonus.out tests_3/sub_5.out && echo '### Test 5 PASSED ###' || echo '### Test 5 FAILED ###'

cmp --silent tests_3/6.out tests_3/sub_6.out && echo '### Test 6 PASSED ###' || echo '### Test 6 FAILED ###'
cmp --silent tests_3/7.out tests_3/sub_7.out && echo '### Test 7 PASSED ###' || echo '### Test 7 FAILED ###'
cmp --silent tests_3/8.out tests_3/sub_8.out && echo '### Test 8 PASSED ###' || echo '### Test 8 FAILED ###'
cmp --silent tests_3/9.out tests_3/sub_9.out && echo '### Test 9 PASSED ###' || echo '### Test 9 FAILED ###'
cmp --silent tests_3/10.out tests_3/sub_10.out && echo '### Test 10 PASSED ###' || echo '### Test 10 FAILED ###'

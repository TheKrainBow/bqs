rm *k*_file

touch "5kx5k_1%_file"
touch "5kx5k_10%_file"
touch "5kx5k_50%_file"
touch "10kx10k_1%_file"
touch "10kx10k_10%_file"
touch "10kx10k_50%_file"

gcc generator.c && ./a.out "5kx5k_1%_file" "1" "5000"
gcc generator.c && ./a.out "5kx5k_10%_file" "10" "5000"
gcc generator.c && ./a.out "5kx5k_50%_file" "50" "5000"
gcc generator.c && ./a.out "10kx10k_1%_file" "1" "10000"
gcc generator.c && ./a.out "10kx10k_10%_file" "10" "10000"
gcc generator.c && ./a.out "10kx10k_50%_file" "50" "10000"
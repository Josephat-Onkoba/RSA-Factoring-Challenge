import sys

def factorize(n):
    factors = []
    for i in range(2, n // 2 + 1):
        if n % i == 0:
            factors.append((i, n // i))
    return factors

def main():
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)

    input_file = sys.argv[1]

    try:
        with open(input_file, 'r') as file:
            numbers = file.readlines()
            numbers = [int(num.strip()) for num in numbers]
    except FileNotFoundError:
        print(f"Error: File '{input_file}' not found.")
        sys.exit(1)

    for num in numbers:
        if num <= 1:
            continue
        factor_pairs = factorize(num)
        print(f"{num}=", end='')
        for pair in factor_pairs:
            print(f"{pair[0]}*{pair[1]}", end='')
            if pair != factor_pairs[-1]:
                print("+", end='')
        print()

if __name__ == "__main__":
    main()

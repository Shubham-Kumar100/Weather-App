def getOneBits(n):
    # Convert integer n to binary representation (without '0b' prefix)
    binary_str = bin(n)[2:]
    
    # List to hold the positions of 1-bits
    positions = []
    
    # Iterate through the binary string and collect positions of 1-bits
    for i, bit in enumerate(binary_str):
        if bit == '1':
            # Positions are 1-based, so add 1 to the index
            positions.append(i + 1)
    
    # The number of 1-bits is the length of positions list
    num_ones = len(positions)
    
    # Return the result list: [count of 1s, positions...]
    return [num_ones] + positions

# Test the function with the sample input
print(getOneBits(37))  # Output should be [3, 1, 3, 8]
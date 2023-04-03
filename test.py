# Example usage:
def find_x(a, b, c):
    """
    This function takes in three distinct integers A, B, and C.
    It finds the value of X such that (A⊕X) < (B⊕X) < (C⊕X).
    """
    max_num = max(a, b, c) # get the maximum number among A, B, C
    max_binary = bin(max_num)[2:] # convert maximum number to binary representation
    # pad the binary representation with 0s to make it the same length as the other numbers
    max_binary = max_binary.zfill(len(bin(a)[2:]))
    
    # start with the highest bit and check if flipping it would make the inequality true
    for i in range(len(max_binary)):
        # flip the i-th bit in the binary representation of X
        x_binary = max_binary[:i] + ('0' if max_binary[i] == '1' else '1') + max_binary[i+1:]
        x = int(x_binary, 2)
        if a^x < b^x < c^x:
            return x
    return -1 # no X was found


# Example usage:
a,b,c=[int(x) for x in input().split()]
x = find_x(a, b, c)
print(x) # Output: 5

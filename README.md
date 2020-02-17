# Visual-Crypthography_CPP

Visual Cryptography is a cryptographic technique where a message is revealed as a visual image.

**2 members Secret Sharing:**

Visual secret sharing problem assumes that the message consists of a collection of black and white pixels, and each pixel is handled separately.
By doing some operations shares will be given one to each person(namely S1,S2).
When the transparencies S1,S2 are stacked together, then we can see combines share which the message.
Logically stacking of these S1 and S2 is equal to bitwise xor of them.

**Programming files written:** 

**visual.cpp -** File that contains the entire code

**Functions written -**
    **visual** - This takes black and white image as input performs some operations and divide the shares S1,S2. When S1,S2 are stacked the original message is obtained.




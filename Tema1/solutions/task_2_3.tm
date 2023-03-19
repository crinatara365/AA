01X.
start   #   L   writeX
        *   R   start

writeX  1   PX,R    write(1, move_one_to_left)
        0   PX,R    write(0, move_one_to_left)
        #   R       deleteX

write(c, s) *   Pc,L  s

move_one_to_left    *   L   count1

reset(s)    X   L   s
            *   R   reset(s)

count1  #   R   reset(writeX)   
        *   L   count2

count2  #   R   reset(writeX)  
        *   L   count3

count3  #   R   reset(writeX)  
        *   L   count4

count4  #   R   reset(writeX)
        *   H   compare

compare 1   H   minus_3
        0   L   count1

minus_3  *   R   m1

m1  *   R   m2

m2  *   R   s1

s1  1   P0,L    s2
    0   P1,L    s5

s2  1   P0,L    s9
    0   P1,L    s4

s3      0   P#,R    s3
        1   L       s7

s4  0   P1,L    s10
    1   P0,L    s8

s5  1   P1,L    s6
    0   L       s4

s6  0   P1,L    s10
    1   P0,L    s8

s10 1   P0,L    s7

s7  #   H   reset(writeX)   
    *   H   count1

s8  *   L   s7

s9  *   L   s8

deleteX X   P#,R    delete_0

delete_0    0   P#,R    delete_0
            1   H       accept

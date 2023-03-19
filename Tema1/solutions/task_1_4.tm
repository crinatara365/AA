01acXSM.
start   #   PS  reset_by_X(delimitator)
        *   R   start

delimitator 0   PM,L    write(0, begin)
            1   PM,L    write(1, begin)

shift_by_M  1   PM,L    write(1, move_2_steps)
            0   PM,L    write(0, move_2_steps) 

shift_by_X  1   PX,L    write(1, begin)
            0   PX,L    write(0, begin) 

write(c, s) *   Pc      s 

move_2_steps    *   R   more 

more    *   R   if_end

if_end  S   P#,L        delete_M
        *   L           move_back(begin)

move_back(s)   *   L   s

reset_by_X(s)   #   R   s
                X   R   s
                *   L   reset_by_X(s)

reset_by_M(s)   M       R       s
                *       L       reset_by_M(s)

begin   #   R   verify
        X   R   verify
        *   L   begin

verify  *       R       count1

count1  M   R   shift_by_M
        X   R   check
        *   R   count2

count2  M   R   shift_by_M
        X   R   check
        *   R   count3

count3  M   L   reset_by_X(compare)
        X   L   reset_by_X(compare)
        *   R   if_more_than_4

if_more_than_4  M   L   reset_by_X(compare)
                X   L   reset_by_X(compare)
                *   H   reset_by_X(shift_by_X)   

compare 1   R   see1
        0   R   see2

see1    X   R   check
        M   R   check
        1   R   try1
        0   R   try2

see2    X   R   check
        M   R   check
        1   R   try3
        0   R   reset

try1    1   H   add
        0   H   add
        X   R   check
        M   R   check

try2    X   R   check
        M   R   check
        1   H   add
        0   R   try_again

try3    X   R   check
        M   R   check
        1   H   add
        0   R   keep_trying

try_again       X   R   check
                M   R   check
                *   H   add

keep_trying 1   H   add
            X   R   check
            M   R   check
            0   R   move_1_step

move_1_step *   R   check

check   M       L       reset_by_X(compare)
        X       L       reset_by_X(compare)
        S       L       reset_by_M(shift_by_M)
        *       R       check

add X   L   x1
    M   L   x1
    *   R   add

x1  0   P1,L    x2
    1   P0,L    x3

x2  0       P1,H    reset
    1       P0,L    x4

x4  0       P1      reset
    #       P1      reset
    1       P0,L    x4

x3  *       L       x4

reset   M   R   shift_by_M
        X   R   check
        *   R   reset   

delete_M        *       P#,L      c1

c1      *       L       c2

c2      #       H       put1
        *       L       c3 

c3      #       H       put2
        *       L       c4

c4      #       H       put3
        *       L       c5

c5      X       R       switch
        *       H       switch
        #       R       mark_end

switch  0       PX,L    write(0, c1)
        1       PX,L    write(1, c1)

put1    *       P0,L    put2

put2    *       P0,L    put3

put3    *       P0,H    mark_end

mark_end        #       PS,L    reset2
                *       R       mark_end

delete_X        X       P#,R    shift_right
                S       P#,H    accept
                *       R       delete_X

shift_right     0       P#,L    write(0, s7)
                1       P#,L    write(1, s7)
                X       P#,L    write(X, s7)
                S       P#,L    write(S, reset2)

s7      *       R       s8

s8      *       R       shift_right

reset2  #       R       delete_X
        *       L       reset2

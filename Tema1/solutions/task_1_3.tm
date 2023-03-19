01.
start   #   L   s1
        *   R   start

s1      0       P1,L    s2
        1       P0,L    s3

s2      0       P1,H    accept
        1       P0,L    s4

s4      0       P1      accept
        1       P0,L    s4
        #       P1      accept

s3      *       L       s4

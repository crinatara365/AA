01.
start   1   R   count1

count1  #   P0  accept   
        *   R   count2

count2  #   L   reset(delete2)   
        *   R   count3

count3  #   L   reset(verify) 
        *   L   reset(delete1)

reset(s)    #   R   s   
            *   L   reset(s)

delete1 #   P1,H    accept
        *   P#,R    delete1

delete2 #   P0,H    accept
        *   P#,R    delete2

verify  1   R   verify_again

verify_again    1   H   reset(delete1)
                0   R   keep_verifying

keep_verifying  1   H   reset(delete1)
                0   H   reset(delete2)

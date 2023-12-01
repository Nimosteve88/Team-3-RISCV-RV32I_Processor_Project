init:
    # Initialize lights output
    addi a0, zero, 0x0

    # Initialize the LFSR with a non-zero seed // when using vbuddy copy value of rotary thing to t1 upon initializing
    addi t4, zero, 0x55

    # Initialize no. of times to run LFSR
    addi t2, zero, 0x3

    # Initialize useful values
    addi s1, zero, 0x1
    addi s2, zero, 0xff

    # 7-bit primitive polynomial
    addi s3, zero, 0x83 

    addi t0, t0, 0x1

idle:
    # Checking for trigger
    bne t0, s1, idle

    # Set t0 back to zero once condition is met
    addi t0, zero, 0x0

    # Copy vbuddy rotary value once trigger is activated
    add t1, t4, zero
    beq t1, zero, init

fsm_setup:
    # Make the output 1
    add a0, zero, s1
    add t5, zero, s1
    bne a0, s1, fsm_setup

fsm_loop:
    # Add t5 to itself and add 1 (left shift by 1 with 1 as lsb)
    add t5, t5, t5
    add t5, t5, s1

    # Set output to t5 to avoid lights incrementing in two steps
    add a0, t5, zero
    bne a0, s2, fsm_loop

lfsr:
    # Shift seed/working delay
    add t1, t1, t1

    # And working delay with primitive polynomial
    and t3, t1, s3

    # Xor nonzero polynomial bits with working delay
    xor t1, t1, t3

    # Reduce number of remaining loops 
    sub t2, t2, s1
    bne t2, zero, lfsr

delay:
    # Add noOps while the delay is decreasing
    nop 
    sub t1, t1, s1
    bne t1, zero, delay

lights_off:
    # lights go off and back to init and idle
    addi a0, zero, 0x0
    jal zero, init
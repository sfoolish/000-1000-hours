# C语言之函数栈结构分析
## 测试代码

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    int backtrace_test3 (void **buf, int size)
    {
        int *sp;
        int *fp;
        int *p;
        int i = 0;
    
        asm volatile("mov %0, sp" :"=r"(sp)::"memory");
        printf("-%s:sp-----0x%8x\n", __func__, (unsigned int)sp);
        asm volatile("mov %0, fp" :"=r"(fp)::"memory");
        printf("-%s:fp-----0x%8x\n", __func__, (unsigned int)fp);
    
        asm volatile("mov %0, lr" :"=r"(p)::"memory");
        printf("--lr-----0x%8x\n",(unsigned int) p);
        asm volatile("mov %0, r4" :"=r"(p)::"memory");
        printf("--r4-----0x%8x\n\n",(unsigned int) p);
    
        p = sp;
    
        for(i = 0; i < 0x30; i++, p++)
            printf("%p----0x%8x\n", p, (unsigned int)*p);
    
        return size;
    }
    
    void backtrace_test2(void)
    {
        int *sp;
        int *fp;
        void *array[5];
        int ret = -1;
        
        asm volatile("mov %0, sp" :"=r"(sp)::"memory");
        printf("-%s:sp-----0x%8x\n", __func__, (unsigned int)sp);
        asm volatile("mov %0, fp" :"=r"(fp)::"memory");
        printf("-%s:fp-----0x%8x\n", __func__, (unsigned int)fp);
    
        ret = backtrace_test3(array, 5);
    }
    
    void backtrace_test1(void)
    {
        int *sp;
        int *fp;
    
        asm volatile("mov %0, sp" :"=r"(sp)::"memory");
        printf("-%s:sp-----0x%8x\n", __func__, (unsigned int)sp);
        asm volatile("mov %0, fp" :"=r"(fp)::"memory");
        printf("-%s:fp-----0x%8x\n", __func__, (unsigned int)fp);
    
        backtrace_test2();
    }
    
    int main()
    {
        backtrace_test1();
    
        return 0;
    }

## 不带优化选项测试
### 反汇编结果及简要说明
编译和反汇编命令：

    arm-linux-uclibcgnueabi-gcc backtrace_test.c -o backtrace_test
    arm-linux-uclibcgnueabi-objdump -d backtrace_test
汇编代码：

    000083f4 <backtrace_test3>:
        83f4:       e92d4800        push    {fp, lr}
        83f8:       e28db004        add     fp, sp, #4      ; 0x4
        83fc:       e24dd018        sub     sp, sp, #24     ; 0x18
        8400:       e50b0018        str     r0, [fp, #-24]
        8404:       e50b101c        str     r1, [fp, #-28]
        8408:       e3a03000        mov     r3, #0  ; 0x0
        840c:       e50b3008        str     r3, [fp, #-8]
        8410:       e1a0300d        mov     r3, sp
        8414:       e50b3014        str     r3, [fp, #-20]
        8418:       e3083600        movw    r3, #34304      ; 0x8600
        841c:       e3403000        movt    r3, #0  ; 0x0
        8420:       e51b2014        ldr     r2, [fp, #-20]
        8424:       e1a00003        mov     r0, r3
        8428:       e3081698        movw    r1, #34456      ; 0x8698
        842c:       e3401000        movt    r1, #0  ; 0x0
        8430:       ebffffc4        bl      8348 <_init+0x24>
        8434:       e1a0300b        mov     r3, fp
        8438:       e50b3010        str     r3, [fp, #-16]
        843c:       e3083618        movw    r3, #34328      ; 0x8618
        8440:       e3403000        movt    r3, #0  ; 0x0
        8444:       e51b2010        ldr     r2, [fp, #-16]
        8448:       e1a00003        mov     r0, r3
        844c:       e3081698        movw    r1, #34456      ; 0x8698
        8450:       e3401000        movt    r1, #0  ; 0x0
        8454:       ebffffbb        bl      8348 <_init+0x24>
        8458:       e1a0300e        mov     r3, lr
        845c:       e50b300c        str     r3, [fp, #-12]
        8460:       e3083630        movw    r3, #34352      ; 0x8630
        8464:       e3403000        movt    r3, #0  ; 0x0
        8468:       e51b200c        ldr     r2, [fp, #-12]
        846c:       e1a00003        mov     r0, r3
        8470:       e1a01002        mov     r1, r2
        8474:       ebffffb3        bl      8348 <_init+0x24>
        8478:       e1a03004        mov     r3, r4
        847c:       e50b300c        str     r3, [fp, #-12]
        8480:       e3083648        movw    r3, #34376      ; 0x8648
        8484:       e3403000        movt    r3, #0  ; 0x0
        8488:       e51b200c        ldr     r2, [fp, #-12]
        848c:       e1a00003        mov     r0, r3
        8490:       e1a01002        mov     r1, r2
        8494:       ebffffab        bl      8348 <_init+0x24>
        8498:       e51b3014        ldr     r3, [fp, #-20]
        849c:       e50b300c        str     r3, [fp, #-12]
        84a0:       e3a03000        mov     r3, #0  ; 0x0
        84a4:       e50b3008        str     r3, [fp, #-8]
        84a8:       ea00000c        b       84e0 <backtrace_test3+0xec>
        84ac:       e3083660        movw    r3, #34400      ; 0x8660
        84b0:       e3403000        movt    r3, #0  ; 0x0
        84b4:       e51b200c        ldr     r2, [fp, #-12]
        84b8:       e5922000        ldr     r2, [r2]
        84bc:       e1a00003        mov     r0, r3
        84c0:       e51b100c        ldr     r1, [fp, #-12]
        84c4:       ebffff9f        bl      8348 <_init+0x24>
        84c8:       e51b3008        ldr     r3, [fp, #-8]
        84cc:       e2833001        add     r3, r3, #1      ; 0x1
        84d0:       e50b3008        str     r3, [fp, #-8]
        84d4:       e51b300c        ldr     r3, [fp, #-12]
        84d8:       e2833004        add     r3, r3, #4      ; 0x4
        84dc:       e50b300c        str     r3, [fp, #-12]
        84e0:       e51b3008        ldr     r3, [fp, #-8]
        84e4:       e353002f        cmp     r3, #47 ; 0x2f
        84e8:       daffffef        ble     84ac <backtrace_test3+0xb8>
        84ec:       e51b301c        ldr     r3, [fp, #-28]
        84f0:       e1a00003        mov     r0, r3
        84f4:       e24bd004        sub     sp, fp, #4      ; 0x4
        84f8:       e8bd8800        pop     {fp, pc}
    
    000084fc <backtrace_test2>:
        84fc:       e92d4800        push    {fp, lr}
        8500:       e28db004        add     fp, sp, #4      ; 0x4
        8504:       e24dd020        sub     sp, sp, #32     ; 0x20
        8508:       e3e03000        mvn     r3, #0  ; 0x0
        850c:       e50b3008        str     r3, [fp, #-8]
        8510:       e1a0300d        mov     r3, sp
        8514:       e50b3010        str     r3, [fp, #-16]
        8518:       e3083600        movw    r3, #34304      ; 0x8600
        851c:       e3403000        movt    r3, #0  ; 0x0
        8520:       e51b2010        ldr     r2, [fp, #-16]
        8524:       e1a00003        mov     r0, r3
        8528:       e3081688        movw    r1, #34440      ; 0x8688
        852c:       e3401000        movt    r1, #0  ; 0x0
        8530:       ebffff84        bl      8348 <_init+0x24>
        8534:       e1a0300b        mov     r3, fp
        8538:       e50b300c        str     r3, [fp, #-12]
        853c:       e3083618        movw    r3, #34328      ; 0x8618
        8540:       e3403000        movt    r3, #0  ; 0x0
        8544:       e51b200c        ldr     r2, [fp, #-12]
        8548:       e1a00003        mov     r0, r3
        854c:       e3081688        movw    r1, #34440      ; 0x8688
        8550:       e3401000        movt    r1, #0  ; 0x0
        8554:       ebffff7b        bl      8348 <_init+0x24>
        8558:       e24b3024        sub     r3, fp, #36     ; 0x24
        855c:       e1a00003        mov     r0, r3
        8560:       e3a01005        mov     r1, #5  ; 0x5
        8564:       ebffffa2        bl      83f4 <backtrace_test3>
        8568:       e1a03000        mov     r3, r0
        856c:       e50b3008        str     r3, [fp, #-8]
        8570:       e24bd004        sub     sp, fp, #4      ; 0x4
        8574:       e8bd8800        pop     {fp, pc}
    
    00008578 <backtrace_test1>:
        8578:       e92d4800        push    {fp, lr}
        857c:       e28db004        add     fp, sp, #4      ; 0x4
        8580:       e24dd008        sub     sp, sp, #8      ; 0x8
        8584:       e1a0300d        mov     r3, sp
        8588:       e50b300c        str     r3, [fp, #-12]
        858c:       e3083600        movw    r3, #34304      ; 0x8600
        8590:       e3403000        movt    r3, #0  ; 0x0
        8594:       e51b200c        ldr     r2, [fp, #-12]
        8598:       e1a00003        mov     r0, r3
        859c:       e3081678        movw    r1, #34424      ; 0x8678
        85a0:       e3401000        movt    r1, #0  ; 0x0
        85a4:       ebffff67        bl      8348 <_init+0x24>
        85a8:       e1a0300b        mov     r3, fp
        85ac:       e50b3008        str     r3, [fp, #-8]
        85b0:       e3083618        movw    r3, #34328      ; 0x8618
        85b4:       e3403000        movt    r3, #0  ; 0x0
        85b8:       e51b2008        ldr     r2, [fp, #-8]
        85bc:       e1a00003        mov     r0, r3
        85c0:       e3081678        movw    r1, #34424      ; 0x8678
        85c4:       e3401000        movt    r1, #0  ; 0x0
        85c8:       ebffff5e        bl      8348 <_init+0x24>
        85cc:       ebffffca        bl      84fc <backtrace_test2>
        85d0:       e24bd004        sub     sp, fp, #4      ; 0x4
        85d4:       e8bd8800        pop     {fp, pc}
    
    000085d8 <main>:
        85d8:       e92d4800        push    {fp, lr}
        85dc:       e28db004        add     fp, sp, #4      ; 0x4
        85e0:       ebffffe4        bl      8578 <backtrace_test1>
        85e4:       e3a03000        mov     r3, #0  ; 0x0
        85e8:       e1a00003        mov     r0, r3
        85ec:       e8bd8800        pop     {fp, pc}

backtrace_test3 为例简要分析汇编代码：

    000083f4 <backtrace_test3>:
        push    {fp, lr}        ; 将 fp, lr 压栈，相当于 *(--sp) = lr; *(--sp) = fp; 
        add     fp, sp, #4      ; 设置帧指针(FP)地址，FP是本函数调用栈的局部基指针；
        sub     sp, sp, #24     ; 设置堆栈指针(SP)地址，空出足够的局部变量空间；
        str     r0, [fp, #-24]  ; 函数的参数相当于一个局部变量，相当于初始化 buf；
        ... ...
        mov     r0, r3          ; r0 为函数返回值，本行作用为设置函数返回值；
        sub     sp, fp, #4      ; 恢复 sp 指针到上一次值；
        pop     {fp, pc}        ; 弹栈，相当于*(sp++) = pc; *(sp++) = fp;

### 测试打印与说明
    -backtrace_test1:sp-----0xbe886e08
    -backtrace_test1:fp-----0xbe886e14
    -backtrace_test2:sp-----0xbe886de0
    -backtrace_test2:fp-----0xbe886e04
    -backtrace_test3:sp-----0xbe886dc0
    -backtrace_test3:fp-----0xbe886ddc
    --lr-----0x    8458
    --r4-----0x40057ed0
    
    0xbe886dc0----0x       5    ; backtrace_test3:sp   arg size
    0xbe886dc4----0xbe886de0    ;                      arg **buf
    0xbe886dc8----0xbe886dc0    ;                      arg *sp
    0xbe886dcc----0xbe886ddc    ;                      arg *fp
    0xbe886dd0----0xbe886dd0    ;                      arg *p
    0xbe886dd4----0x       5    ;                      arg i
    0xbe886dd8----0xbe886e04    ;                      backtrace_test2:fp
    0xbe886ddc----0x    8568    ; backtrace_test3:fp   lr back to test1       push    {fp, lr}
    0xbe886de0----0xbe886e14    ; backtrace_test2:sp   arg *array[0]
    0xbe886de4----0x4002b250    ;                      arg *array[1]
    0xbe886de8----0x    8618    ;                      arg *array[2]
    0xbe886dec----0xbe886dfc    ;                      arg *array[3]
    0xbe886df0----0xbe886e14    ;                      arg *array[4]
    0xbe886df4----0xbe886de0    ;                      arg *sp
    0xbe886df8----0xbe886e04    ;                      arg *fp
    0xbe886dfc----0xffffffff    ;                      arg ret
    0xbe886e00----0xbe886e14    ;                      backtrace_test1:fp
    0xbe886e04----0x    85d0    ; backtrace_test2:fp   lr back to test1      push    {fp, lr}
    0xbe886e08----0xbe886e08    ; backtrace_test1:sp   arg *sp
    0xbe886e0c----0xbe886e14    ;                      arg *fp
    0xbe886e10----0xbe886e1c    ;                      main:fp
    0xbe886e14----0x    85e4    ; backtrace_test1:fp   lr back to main       push    {fp, lr}
    0xbe886e18----0x       0
    0xbe886e1c----0x4004a9c4
    0xbe886e20----0x       0
    0xbe886e24----0x       0
    0xbe886e28----0x       0

从上面的栈信息我们看可以看到，lr 保存的值为，本次函数返回后将继续执行的指令起始地址。

## 带 -O2 优化选项测试
### 反汇编结果及简要说明
编译和反汇编命令：

    arm-linux-uclibcgnueabi-gcc backtrace_test.c -O2 -o backtrace_test
    arm-linux-uclibcgnueabi-objdump -d backtrace_test
汇编代码：

    000083f4 <backtrace_test3>:
        83f4:       e92d4070        push    {r4, r5, r6, lr}
        83f8:       e1a06001        mov     r6, r1
        83fc:       e1a0500d        mov     r5, sp
        8400:       e59f105c        ldr     r1, [pc, #92]   ; 8464 <backtrace_test3+0x70>
        8404:       e1a02005        mov     r2, r5
        8408:       e59f0058        ldr     r0, [pc, #88]   ; 8468 <backtrace_test3+0x74>
        840c:       ebffffcd        bl      8348 <_init+0x24>
        8410:       e1a0200b        mov     r2, fp
        8414:       e59f1048        ldr     r1, [pc, #72]   ; 8464 <backtrace_test3+0x70>
        8418:       e59f004c        ldr     r0, [pc, #76]   ; 846c <backtrace_test3+0x78>
        841c:       ebffffc9        bl      8348 <_init+0x24>
        8420:       e1a0100e        mov     r1, lr
        8424:       e59f0044        ldr     r0, [pc, #68]   ; 8470 <backtrace_test3+0x7c>
        8428:       ebffffc6        bl      8348 <_init+0x24>
        842c:       e1a01004        mov     r1, r4
        8430:       e59f003c        ldr     r0, [pc, #60]   ; 8474 <backtrace_test3+0x80>
        8434:       e1a04005        mov     r4, r5
        8438:       ebffffc2        bl      8348 <_init+0x24>
        843c:       e28550c0        add     r5, r5, #192    ; 0xc0
        8440:       e1a01004        mov     r1, r4
        8444:       e5942000        ldr     r2, [r4]
        8448:       e59f0028        ldr     r0, [pc, #40]   ; 8478 <backtrace_test3+0x84>
        844c:       e2844004        add     r4, r4, #4      ; 0x4
        8450:       ebffffbc        bl      8348 <_init+0x24>
        8454:       e1540005        cmp     r4, r5
        8458:       1afffff8        bne     8440 <backtrace_test3+0x4c>
        845c:       e1a00006        mov     r0, r6
        8460:       e8bd8070        pop     {r4, r5, r6, pc}
        8464:       00008524        .word   0x00008524
        8468:       00008554        .word   0x00008554
        846c:       00008568        .word   0x00008568
        8470:       0000857c        .word   0x0000857c
        8474:       0000858c        .word   0x0000858c
        8478:       000085a0        .word   0x000085a0
    
    0000847c <backtrace_test2>:
        847c:       e92d4010        push    {r4, lr}
        8480:       e24dd018        sub     sp, sp, #24     ; 0x18
        8484:       e1a0200d        mov     r2, sp
        8488:       e59f4034        ldr     r4, [pc, #52]   ; 84c4 <backtrace_test2+0x48>
        848c:       e3080554        movw    r0, #34132      ; 0x8554
        8490:       e3400000        movt    r0, #0  ; 0x0
        8494:       e1a01004        mov     r1, r4
        8498:       ebffffaa        bl      8348 <_init+0x24>
        849c:       e1a0200b        mov     r2, fp
        84a0:       e3080568        movw    r0, #34152      ; 0x8568
        84a4:       e1a01004        mov     r1, r4
        84a8:       e3400000        movt    r0, #0  ; 0x0
        84ac:       ebffffa5        bl      8348 <_init+0x24>
        84b0:       e28d0004        add     r0, sp, #4      ; 0x4
        84b4:       e3a01005        mov     r1, #5  ; 0x5
        84b8:       ebffffcd        bl      83f4 <backtrace_test3>
        84bc:       e28dd018        add     sp, sp, #24     ; 0x18
        84c0:       e8bd8010        pop     {r4, pc}
        84c4:       00008534        .word   0x00008534
    
    000084c8 <backtrace_test1>:
        84c8:       e92d4010        push    {r4, lr}
        84cc:       e1a0200d        mov     r2, sp
        84d0:       e59f4028        ldr     r4, [pc, #40]   ; 8500 <backtrace_test1+0x38>
        84d4:       e3080554        movw    r0, #34132      ; 0x8554
        84d8:       e3400000        movt    r0, #0  ; 0x0
        84dc:       e1a01004        mov     r1, r4
        84e0:       ebffff98        bl      8348 <_init+0x24>
        84e4:       e1a0200b        mov     r2, fp
        84e8:       e3080568        movw    r0, #34152      ; 0x8568
        84ec:       e1a01004        mov     r1, r4
        84f0:       e3400000        movt    r0, #0  ; 0x0
        84f4:       ebffff93        bl      8348 <_init+0x24>
        84f8:       e8bd4010        pop     {r4, lr}
        84fc:       eaffffde        b       847c <backtrace_test2>
        8500:       00008544        .word   0x00008544
    
    00008504 <main>:
        8504:       e92d4010        push    {r4, lr}
        8508:       ebffffee        bl      84c8 <backtrace_test1>
        850c:       e3a00000        mov     r0, #0  ; 0x0
        8510:       e8bd8010        pop     {r4, pc}

### 测试打印与说明
    -backtrace_test1:sp-----0xbe87ce10
    -backtrace_test1:fp-----0x       0
    -backtrace_test2:sp-----0xbe87cdf8
    -backtrace_test2:fp-----0x       0
    -backtrace_test3:sp-----0xbe87cde8
    -backtrace_test3:fp-----0x       0
    --lr-----0x    8420
    --r4-----0x    8534
    
    0xbe87cde8----0x    8534    ; -backtrace_test3:sp   reg r4 backup for test2
    0xbe87cdec----0xbe87cea4    ;                       reg r5 backup for test2
    0xbe87cdf0----0x       1    ;                       reg r6 backup for test2
    0xbe87cdf4----0x    84bc    ;                       reg lr back to test2
    0xbe87cdf8----0x       0    ; -backtrace_test2:sp   for 8 bytes align padding
    0xbe87cdfc----0x    84f8    ;                       arg arrary[0]
    0xbe87ce00----0x    8568    ;                       arg arrary[1]
    0xbe87ce04----0x    8544    ;                       arg arrary[2]
    0xbe87ce08----0x       0    ;                       arg arrary[3]
    0xbe87ce0c----0xbe87ce10    ;                       arg arrary[4]
    0xbe87ce10----0x40057ed0    ; -backtrace_test1:sp   reg r4 backup for main
    0xbe87ce14----0x    850c    ;                       reg lr back to main
    0xbe87ce18----0x40057ed0
    0xbe87ce1c----0x4004a9c4
    0xbe87ce20----0x       0

优化后的代码，不使用 fp 寄存器，指令也更加紧凑，很多局部变量都直接使用寄存器。在函数的调用过程中，如果要对默写寄存器进行修改，则在进入函数的时候将这些寄存器压栈，函数返回时弹栈。
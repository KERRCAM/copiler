.global _start
.align 2


_start:
        mov x0, 255 // 255 max value -> 0 or 256 will exit clean then 257 goes back to 1
        mov x1, 100
        mov x16, 1
        svc 0
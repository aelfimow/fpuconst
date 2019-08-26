# void fpu_pi(void *p)
# p is in %rcx
.global fpu_pi
.section .text
fpu_pi:
	fldpi
	fstpt (%rcx)
	ret

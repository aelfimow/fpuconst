# void fpu_pi(void *p)
# p is in %rdi
.global fpu_pi
.section .text
fpu_pi:
	fldpi
	fstpt (%rdi)
	ret

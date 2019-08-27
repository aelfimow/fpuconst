# void fpu_pi80(void *p)
# p is in %rdi
.global fpu_pi80
.section .text
fpu_pi80:
	fldpi
	fstpt (%rdi)
	ret
# void fpu_pi64(void *p)
# p is in %rdi
.global fpu_pi64
.section .text
fpu_pi64:
	fldpi
	fstpl (%rdi)
	ret
# void fpu_pi32(void *p)
# p is in %rdi
.global fpu_pi32
.section .text
fpu_pi32:
	fldpi
	fstps (%rdi)
	ret

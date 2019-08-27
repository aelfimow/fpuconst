# void fpu_pi80(void *p)
# p is in %rcx
.global fpu_pi80
.section .text
fpu_pi80:
	fldpi
	fstpt (%rcx)
	ret
# void fpu_pi64(void *p)
# p is in %rcx
.global fpu_pi64
.section .text
fpu_pi64:
	fldpi
	fstpl (%rcx)
	ret
# void fpu_pi32(void *p)
# p is in %rcx
.global fpu_pi32
.section .text
fpu_pi32:
	fldpi
	fstps (%rcx)
	ret

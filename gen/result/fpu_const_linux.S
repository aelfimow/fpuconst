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
# void fpu_zero80(void *p)
# p is in %rdi
.global fpu_zero80
.section .text
fpu_zero80:
	fldz
	fstpt (%rdi)
	ret
# void fpu_zero64(void *p)
# p is in %rdi
.global fpu_zero64
.section .text
fpu_zero64:
	fldz
	fstpl (%rdi)
	ret
# void fpu_zero32(void *p)
# p is in %rdi
.global fpu_zero32
.section .text
fpu_zero32:
	fldz
	fstps (%rdi)
	ret
# void fpu_one80(void *p)
# p is in %rdi
.global fpu_one80
.section .text
fpu_one80:
	fld1
	fstpt (%rdi)
	ret
# void fpu_one64(void *p)
# p is in %rdi
.global fpu_one64
.section .text
fpu_one64:
	fld1
	fstpl (%rdi)
	ret
# void fpu_one32(void *p)
# p is in %rdi
.global fpu_one32
.section .text
fpu_one32:
	fld1
	fstps (%rdi)
	ret
# void fpu_ld10_80(void *p)
# p is in %rdi
.global fpu_ld10_80
.section .text
fpu_ld10_80:
	fldl2t
	fstpt (%rdi)
	ret
# void fpu_ld10_64(void *p)
# p is in %rdi
.global fpu_ld10_64
.section .text
fpu_ld10_64:
	fldl2t
	fstpl (%rdi)
	ret
# void fpu_ld10_32(void *p)
# p is in %rdi
.global fpu_ld10_32
.section .text
fpu_ld10_32:
	fldl2t
	fstps (%rdi)
	ret
# void fpu_ld_e_80(void *p)
# p is in %rdi
.global fpu_ld_e_80
.section .text
fpu_ld_e_80:
	fldl2e
	fstpt (%rdi)
	ret
# void fpu_ld_e_64(void *p)
# p is in %rdi
.global fpu_ld_e_64
.section .text
fpu_ld_e_64:
	fldl2e
	fstpl (%rdi)
	ret
# void fpu_ld_e_32(void *p)
# p is in %rdi
.global fpu_ld_e_32
.section .text
fpu_ld_e_32:
	fldl2e
	fstps (%rdi)
	ret

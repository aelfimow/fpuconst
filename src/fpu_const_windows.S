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
# void fpu_zero80(void *p)
# p is in %rcx
.global fpu_zero80
.section .text
fpu_zero80:
	fldz
	fstpt (%rcx)
	ret
# void fpu_zero64(void *p)
# p is in %rcx
.global fpu_zero64
.section .text
fpu_zero64:
	fldz
	fstpl (%rcx)
	ret
# void fpu_zero32(void *p)
# p is in %rcx
.global fpu_zero32
.section .text
fpu_zero32:
	fldz
	fstps (%rcx)
	ret
# void fpu_one80(void *p)
# p is in %rcx
.global fpu_one80
.section .text
fpu_one80:
	fld1
	fstpt (%rcx)
	ret
# void fpu_one64(void *p)
# p is in %rcx
.global fpu_one64
.section .text
fpu_one64:
	fld1
	fstpl (%rcx)
	ret
# void fpu_one32(void *p)
# p is in %rcx
.global fpu_one32
.section .text
fpu_one32:
	fld1
	fstps (%rcx)
	ret
# void fpu_ld10_80(void *p)
# p is in %rcx
.global fpu_ld10_80
.section .text
fpu_ld10_80:
	fldl2t
	fstpt (%rcx)
	ret
# void fpu_ld10_64(void *p)
# p is in %rcx
.global fpu_ld10_64
.section .text
fpu_ld10_64:
	fldl2t
	fstpl (%rcx)
	ret
# void fpu_ld10_32(void *p)
# p is in %rcx
.global fpu_ld10_32
.section .text
fpu_ld10_32:
	fldl2t
	fstps (%rcx)
	ret
# void fpu_ld_e_80(void *p)
# p is in %rcx
.global fpu_ld_e_80
.section .text
fpu_ld_e_80:
	fldl2e
	fstpt (%rcx)
	ret
# void fpu_ld_e_64(void *p)
# p is in %rcx
.global fpu_ld_e_64
.section .text
fpu_ld_e_64:
	fldl2e
	fstpl (%rcx)
	ret
# void fpu_ld_e_32(void *p)
# p is in %rcx
.global fpu_ld_e_32
.section .text
fpu_ld_e_32:
	fldl2e
	fstps (%rcx)
	ret
# void fpu_lg2_80(void *p)
# p is in %rcx
.global fpu_lg2_80
.section .text
fpu_lg2_80:
	fldlg2
	fstpt (%rcx)
	ret
# void fpu_lg2_64(void *p)
# p is in %rcx
.global fpu_lg2_64
.section .text
fpu_lg2_64:
	fldlg2
	fstpl (%rcx)
	ret
# void fpu_lg2_32(void *p)
# p is in %rcx
.global fpu_lg2_32
.section .text
fpu_lg2_32:
	fldlg2
	fstps (%rcx)
	ret

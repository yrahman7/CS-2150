;;  Yumna Rahman, yr6by
;;  November 4, 2020
;;  file : binarySearch.s

	global binarySearch

	section .text

	;; 1st param (rdi): pointer to an int array
	;; 2nd param (rsi): the beginning of the array
	;; 3rd param (rdx): the end of the array
	;; 4th param (rcx): target element to find
	;; return (rax): int index of the array that the target was found in; -1 if not found
binarySearch:
	xor rax, rax 		; zero out return register
loop:
	cmp rsi, rdx		; if(start > end), not found
	jg notFound
	mov r8, rsi 		; mov start to another register for midpoint calculation
	add r8, rdx 		; start+end
	shr r8, 1 		; (start+end)/2 for midpoint
	mov r9, r8 		; move midpoint to another register for a[mid] calculation
	imul r9, 4 		; midpoint * size of int
	add r9, rdi 		; add array pointer 
	cmp ecx, [r9]	
	je midPoint 		; if a[mid] = key
	jg greaterThan 		; if a[mid] > key
	jl lessThan 		; if a[mid] < key

lessThan:
	mov rdx, r8 		; end = mid-1
	dec rdx
	jmp loop

greaterThan:
	mov rsi, r8 		; start = mid+1
	inc rsi
	jmp loop

midPoint:	
	mov rax, r8 		; move midpoint into return
	ret

notFound:
	mov rax, -1 		; not found
	ret

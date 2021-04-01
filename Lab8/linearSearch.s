	;;  Yumna Rahman, yr6by
	;;  Postlab
	;;  file : linearSearch.s

	global linearSearch

	section .text

	;; Param 1:  array start address (&a), pointer to int array (rdi)
	;; Param 2: size of array (rsi)
	;; Param 3: target element to find (rdx)
	;; return type: index (i) where target found (eax) or -1 if not found
	;;  compare value register (rcx)
linearSearch:
	xor rax, rax		; zero out return register (i)
	dec rsi 		; to account for index start at 0
	mov r9, rdi 		; compare value register
loop:
	cmp rsi, rax
	je notFound 		; if size-count = 0, notFound
	cmp edx, [r9] 		; if target = &a[i]
	je end 			; end
				; else
	add r9, 4		; &a[i] + size of elements
	inc rax 		; increment i
	jmp loop

notFound:
	mov rax, -1 		; return -1
	ret
end:
	ret

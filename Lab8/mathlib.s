; Yumna Rahman, yr6by
; October 25, 2020
; file: mathlib.s
	
	global _product
	global _power	

	section .text

_product:
	; Prologue
	xor rax, rax	; zero out return value

addloop:
	cmp rsi, 0		; if rcx <= 0
	jle endloop		; then, end
	
	add rax, rdi		; otherwise, add first operand to result
	dec rsi			; decrement counter
	jmp addloop		; repeat

endloop:
	; Epilogue
	ret

_power:
	; Prologue
	xor rax, rax		; zero out return value
	mov rcx, rsi		; copying power into another register
	mov r8, rdi		; copy base into another register
	mov rsi, rdi		; copy base into power for addloop to be base * base
	
	
recurse:
	cmp rcx, 1		; if (power = 1)
	je end			; return base
	
	call _product
	mov rsi, r8		; reset base into counter
	mov rdi, rax		; store accumulation of addition

	
	dec rcx			; else, decrement power	
	call recurse		; rax = power(base, power-1)
	

	; Epilogue
	ret
	
end:
	mov rax, rdi 		; move base into return register
	ret

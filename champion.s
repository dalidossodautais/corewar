.name "champion"
.comment "champion qui fait des truc"

	sti r1, %:pattern, %1
	live %0

process1:
	fork %:process2
	fork %:process4
	ldi %:pattern, %0, r2
	ld %0, r3
	ld %0, r4
	zjmp %:pattern

process2:
	fork %:process3
	ldi %:pattern, %4, r2
	ld %4, r3
	ld %0, r4
	zjmp %:pattern

process3:
	ldi %:pattern, %8, r2
	ld %8, r3
	ld %0, r4
	zjmp %:pattern

process4:
	ldi %:pattern, %0, r2
	ld %12, r3
	ld %0, r4
	zjmp %:pattern

pattern:
	live %0
	sti r2, %:end, r3
end:

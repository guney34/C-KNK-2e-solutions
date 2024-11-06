while (...) {
	...
	if (...)
		continue;
	...
	//continue jumps here
}

//equivalent goto example:

while (...) {
	...
	if (...)
		goto end;
	...
	end:
}
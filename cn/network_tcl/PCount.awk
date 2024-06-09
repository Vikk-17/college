BEGIN {
	count = 0;
}

{
	if($1 == "d")
		count ++;
}

END {
	printf("The number of packet dropped %d\n", count);
}

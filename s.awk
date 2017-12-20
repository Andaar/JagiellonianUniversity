BEGIN { 
	print ARGC; 
	for(i = 0; i < ARGC; i++) 
	{
		print ARGV[i];
	}
}


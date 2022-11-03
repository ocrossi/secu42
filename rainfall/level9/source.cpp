class N {
	char annotation
	
	

	void setAnnotation(void *p, char *s) {
		size_t len;
		
		len = strlen(s);
		memcpy(p + 4, s, len);
		return;
	}
}

void  main(int ac, char **av) {
	void *p;
	void **t;

	if (ac < 1)
		exit(1);
	p = new N::N(108);
	p(int)(p, 5);
	t = new N::N(108);
	t(int)(t, 6);
	N::setAnnotation(av[1], p);
	t(t, s);
	return;
}

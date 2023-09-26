cass N {
	public:
	char annotation[100];
	int num;
	 
	
	N(int i) {
		size_t len = strlen(this.s);

		memcpy(this + 4, s, len)
	}


	void setAnnotation(char *s) {
		size_t len = strlen(s);

		memcpy(this + 4, s, len);
		return;
	}

	int N::operator+(N *c2) {
		return (this.num + c2.num)
	}

	int N::operator-(N *c2) {
		return (this.num - c2.num)
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

bsvdir = "./includes"

compile:
	mkdir -p buildDir
	bsc -u -sim -bdir buildDir -info-dir buildDir -simdir buildDir -vdir buildDir -p +:$(bsvdir) -aggressive-conditions WithoutCache.bsv
	rm -rf buildDir